//
//  MissileTower.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "MissileTower.h"
#include "OverlapTester.h"
#include "Circle.h"
#include "Creep.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "Assets.h"
#include "World.h"
#include "GameListener.h"
#include "ResourceConstants.h"
#include "macros.h"

#include <math.h>

MissileTower::MissileTower(float x, float y) : Tower(Tower_Type::MISSILE_TYPE, x, y, 1, 1, 3.2f, 8.0f, 65)
{
	m_explosionType = Explosion_Type::MINI_DAMAGE;
	m_missileState = Missile_State::MISSILES_WAITING;
	m_fProjectileSpeed = 5.00f;
	m_fMissileWaitTime = 0.50f;
	m_fTimeSinceLastShot = 0;
	m_fCooldownTime = 3.40f;
	m_fProjectileWidth = 0.576f;
	m_fProjectileHeight = 0.08f;
	m_iProjectileDamage = 1600;
	m_iMissilesFired = 0;
}

Tower_Type MissileTower::getTowerType()
{
	return Tower_Type::MISSILE_TYPE;
}

void MissileTower::updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fTimeSinceLastShot += deltaTime;

	checkCreepInRadius(creeps);
}

void MissileTower::fireAtCreep(Creep *creep)
{
	if (m_missileState == Missile_State::MISSILES_WAITING)
	{
		if (m_fTimeSinceLastShot > m_fCooldownTime)
		{
			m_missileState = Missile_State::MISSILES_FIRING;
			m_fTimeSinceLastShot = 0;
		}
	}
	else if (m_fTimeSinceLastShot > m_fMissileWaitTime)
	{
        GameListener::getInstance()->playSound(SOUND_MISSILE_LAUNCH);

        float radians = DEGREES_TO_RADIANS(m_fAngle);
		float cos = cosf(radians);
		float sin = sinf(radians);

		World::getInstance()->getMissiles().push_back(std::unique_ptr<Missile>(new Missile(m_position->getX() + (cos * 0.30f), m_position->getY() + (sin * 0.30f), m_fProjectileWidth, m_fProjectileHeight, m_fProjectileSpeed, m_fAngle, m_iProjectileDamage, m_explosionType, creep)));
		m_iMissilesFired++;
		if (m_iMissilesFired > getStage())
		{
			m_missileState = Missile_State::MISSILES_WAITING;
			m_iMissilesFired = 0;
		}

		m_fTimeSinceLastShot = 0;
	}
}

void MissileTower::performUpgrade()
{
	if (getStage() == 2)
	{
		m_explosionType = Explosion_Type::BIG_DAMAGE;
	}

	m_iUpgradeCost += 70;
	m_fTimeSinceLastShot = 0;
	m_fCooldownTime -= 0.20f;
	m_fProjectileWidth += 0.0835f;
	m_fProjectileHeight += 0.025f;
	m_iProjectileDamage += 400;

	m_attackRadius->m_fRadius += 0.40f;
}

void MissileTower::checkCreepInRadius(std::vector<std::unique_ptr<Creep>> &creeps)
{
	for (std::vector<std::unique_ptr<Creep>>::iterator itr = creeps.begin(); itr != creeps.end(); itr++)
	{
		if ((*itr)->canMissilesTarget() && OverlapTester::isPointInCircle((*itr)->getPosition(), *m_attackRadius))
		{
			Vector2D creepPosition = (*itr)->getPosition().cpy();
			m_fAngle = creepPosition.sub(m_position->getX(), m_position->getY()).angle();

			fireAtCreep(itr->get());

			return;
		}
	}
}