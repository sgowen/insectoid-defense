//
//  LazerTower.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "LazerTower.h"
#include "Circle.h"
#include "Creep.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "LazerBeam.h"
#include "World.h"
#include "Line.h"
#include "Color.h"
#include "GameListener.h"
#include "ResourceConstants.h"
#include "macros.h"

#include <stdlib.h>
#include <math.h>

LazerTower::LazerTower(float x, float y) : Tower(Tower_Type::LAZER_TYPE, x, y, 1, 1, 1.7f, 6.0f, 45)
{
	m_lazerBeams.push_back(new LazerBeam(m_position->getX(), m_position->getY(), 1.0f, 30));
	m_lazerBeams.push_back(new LazerBeam(m_position->getX(), m_position->getY(), 0.9f, 20));
	m_lazerBeams.push_back(new LazerBeam(m_position->getX(), m_position->getY(), 0.9f, 20));

	for (std::vector<LazerBeam *>::iterator itr = m_lazerBeams.begin(); itr != m_lazerBeams.end(); itr++)
	{
		World::getInstance()->getLazerBeams().push_back(std::unique_ptr<LazerBeam>(*itr));
	}

	m_fStateTime = 0;
	m_fCooldownTime = 2.4f;
	m_fFiringTime = 0.60f;

	setLazerBeamState(Lazer_Beam_State::WAITING);
}

Tower_Type LazerTower::getTowerType()
{
	return Tower_Type::LAZER_TYPE;
}

void LazerTower::onRemove()
{
	for (std::vector<LazerBeam *>::iterator itr = m_lazerBeams.begin(); itr != m_lazerBeams.end(); itr++)
	{
		for (std::vector<std::unique_ptr<LazerBeam>>::iterator itr2 = World::getInstance()->getLazerBeams().begin(); itr2 != World::getInstance()->getLazerBeams().end(); )
		{
			if((*itr)->getLazerBeamID() == (*itr2)->getLazerBeamID())
			{
				itr2 = World::getInstance()->getLazerBeams().erase(itr2);
			}
			else
			{
				itr2++;
			}
		}
	}
}

Lazer_Beam_State LazerTower::getLazerBeamState()
{
	return m_state;
}

// Virtual Methods

void LazerTower::updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fStateTime += deltaTime;

	if (m_state == Lazer_Beam_State::WAITING)
	{
		checkCreepInRadius(creeps);
	}
}

void LazerTower::fireAtCreep(Creep *creep)
{
	if (m_fStateTime > m_fCooldownTime)
	{
        float radians = DEGREES_TO_RADIANS(m_fAngle);
		float cos = cosf(radians);
		float sin = sinf(radians);

		Vector2D firstLazerBeamOrigin = m_lazerBeams.at(0)->getPath().getOrigin();
		firstLazerBeamOrigin.set(m_position->getX() + (cos * 0.35f), m_position->getY() + (sin * 0.35f));

		float alteredAngle = m_fAngle + 90;
		if (alteredAngle >= 360)
		{
			alteredAngle -= 360;
		}

        float alteredRadians = DEGREES_TO_RADIANS(alteredAngle);
        float alteredCos = cosf(alteredRadians);
		float alteredSin = sinf(alteredRadians);

		float offset = 0.01f;
		float xOffset = alteredCos * offset;
		float yOffset = alteredSin * offset;

		std::vector<LazerBeam *>::iterator itr = m_lazerBeams.begin();
		itr++;
		for (; itr != m_lazerBeams.end(); itr++)
		{
			(*itr)->getPath().getOrigin().set(firstLazerBeamOrigin.getX() + xOffset, firstLazerBeamOrigin.getY() + yOffset);
			itr++;
			(*itr)->getPath().getOrigin().set(firstLazerBeamOrigin.getX() - xOffset, firstLazerBeamOrigin.getY() - yOffset);

			offset += 0.01f;
			xOffset = alteredCos * offset;
			yOffset = alteredSin * offset;
		}

		for (std::vector<LazerBeam *>::iterator itr = m_lazerBeams.begin(); itr != m_lazerBeams.end(); itr++)
		{
			Vector2D origin = (*itr)->getPath().getOrigin();
			(*itr)->fire(origin.getX() + cos * 16, origin.getY() + sin * 16);
		}

		setLazerBeamState(Lazer_Beam_State::FIRING);

        GameListener::getInstance()->playSound(SOUND_LAZER_BEAM);
	}
}

void LazerTower::performUpgrade()
{
	setLazerBeamState(Lazer_Beam_State::WAITING);

	m_iUpgradeCost += 30;
	m_fCooldownTime -= 0.20f;
	m_fFiringTime += 0.20f;

	m_attackRadius->m_fRadius += 0.1f;

	for (std::vector<LazerBeam *>::iterator itr = m_lazerBeams.begin(); itr != m_lazerBeams.end(); itr++)
	{
		(*itr)->increaseDamageRate();
	}

	float alpha = m_lazerBeams.back()->getColor().alpha - (getStage() * 0.2f);

	LazerBeam *lazerBeamLeft = new LazerBeam(m_position->getX(), m_position->getY(), alpha, 20);
	LazerBeam *lazerBeamRight = new LazerBeam(m_position->getX(), m_position->getY(), alpha, 20);

	m_lazerBeams.push_back(lazerBeamLeft);
	m_lazerBeams.push_back(lazerBeamRight);

	World::getInstance()->getLazerBeams().push_back(std::unique_ptr<LazerBeam>(lazerBeamLeft));
	World::getInstance()->getLazerBeams().push_back(std::unique_ptr<LazerBeam>(lazerBeamRight));
}

void LazerTower::updatePhysics(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	if (m_state == Lazer_Beam_State::FIRING)
	{
		if (m_fStateTime > m_fFiringTime || getState() == Tower_State::UPGRADING)
		{
			setLazerBeamState(Lazer_Beam_State::WAITING);

			for (std::vector<LazerBeam *>::iterator itr = m_lazerBeams.begin(); itr != m_lazerBeams.end(); itr++)
			{
				(*itr)->reset();
			}
		}
		else
		{
			float red = ((float) (rand() % 100)) / 100.0f;
			float green = ((float) (rand() % 100)) / 100.0f;
			float blue = ((float) (rand() % 100)) / 100.0f;

			for (std::vector<LazerBeam *>::iterator itr = m_lazerBeams.begin(); itr != m_lazerBeams.end(); itr++)
			{
				(*itr)->update(red, green, blue);
				(*itr)->checkCreepsHitByLazerBeam(deltaTime, creeps);
			}
		}
	}
}

// Private Methods

void LazerTower::setLazerBeamState(Lazer_Beam_State state)
{
	m_state = state;
	m_fStateTime = 0;
}