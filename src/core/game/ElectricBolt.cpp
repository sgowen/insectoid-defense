//
//  ElectricBolt.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/4/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "ElectricBolt.h"
#include "Vector2D.h"
#include "ScreenUtils.h"
#include "OverlapTester.h"
#include "Rectangle.h"
#include "Creep.h"
#include "WorldPlatform.h"
#include "FlagUtil.h"
#include "Projectile.h"
#include "macros.h"

#include <math.h>

ElectricBolt::ElectricBolt(float x, float y, float width, float height, float velocityConstant, float directionalAngle, int damage, int fadeTimeSeconds) : DynamicGameObject (x, y, width, height, directionalAngle)
{
	m_fAlpha = 1;
	m_fRed = 1;
	m_fGreen = 1;
	m_fBlue = 1;
	m_fDamageTime = 0.1f;
	m_iFadeTimeSeconds = fadeTimeSeconds;
	m_iDamage = damage;
	m_iZapDamage = damage * 4;
	m_fStateTime = 0;
	m_fFireTime = 0.1f;
	m_iDamageSinceLastUpdate = 0;
	m_hasEscapedTowerPlatform = false;
	m_remove = false;

	setVelocity(directionalAngle, velocityConstant);
}

void ElectricBolt::update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps, std::vector<std::unique_ptr<WorldPlatform>> &platforms, std::vector<std::unique_ptr<Projectile>> &projectiles)
{
	m_fStateTime += deltaTime;
	m_fFireTime += deltaTime;
	m_position->add(m_velocity->getX() * deltaTime, m_velocity->getY() * deltaTime);
	updateBounds();
	m_remove = ScreenUtils::isVectorOffScreen(*m_position);

	m_fAlpha -= deltaTime / m_iFadeTimeSeconds;

	m_remove = m_fAlpha < 0;

	if (!m_remove && m_fFireTime > m_fDamageTime)
	{
		m_iDamageSinceLastUpdate = 0;

		while (m_fFireTime > m_fDamageTime)
		{
			m_fFireTime -= m_fDamageTime;
			m_iDamageSinceLastUpdate += m_iDamage;
		}

		for (std::vector<std::unique_ptr<Creep>>::iterator itr = creeps.begin(); itr != creeps.end(); itr++)
		{
			if (OverlapTester::doRectanglesOverlap((*itr)->getBounds(), *m_bounds))
			{
				(*itr)->takeDamage(m_iDamageSinceLastUpdate, ELECTRIC);

				if(FlagUtil::isFlagSet((*itr)->getState(), ALIVE))
				{
					(*itr)->electrify();
				}
			}
		}

		for (std::vector<std::unique_ptr<Projectile>>::iterator itr = projectiles.begin(); itr != projectiles.end(); itr++)
		{
			if ((*itr)->getProjectileState() == Projectile_State::STUCK && OverlapTester::doRectanglesOverlap((*itr)->getBounds(), *m_bounds))
			{
				(*itr)->zap(m_iZapDamage);
			}
		}
	}

	if (m_hasEscapedTowerPlatform)
	{
		for (std::vector<std::unique_ptr<WorldPlatform>>::iterator itr = platforms.begin(); itr != platforms.end(); itr++)
		{
			if (OverlapTester::doRectanglesOverlap((*itr)->getBounds(), *m_bounds))
			{
				float deltaY = fabs((*itr)->getPosition().getY() - m_position->getY());
				float deltaX = fabs((*itr)->getPosition().getX() - m_position->getX());

				if (deltaY > deltaX)
				{
					m_velocity->set(m_velocity->getX(), -m_velocity->getY());
				}
				else
				{
					m_velocity->set(-m_velocity->getX(), m_velocity->getY());
				}

				m_fAngle = m_velocity->angle();

				return;
			}
		}
	}
	else
	{
		for (std::vector<std::unique_ptr<WorldPlatform>>::iterator itr = platforms.begin(); itr != platforms.end(); itr++)
		{
			if (OverlapTester::doRectanglesOverlap((*itr)->getBounds(), *m_bounds))
			{
				return;
			}
		}

		m_hasEscapedTowerPlatform = true;
	}
}

Color ElectricBolt::getColor()
{
	Color color = Color(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	return color;
}

float ElectricBolt::getStateTime()
{
	return m_fStateTime;
}

bool ElectricBolt::remove()
{
	return m_remove;
}

// Private Methods

void ElectricBolt::setVelocity(float directionalAngle, float velocityConstant)
{
    float radians = DEGREES_TO_RADIANS(directionalAngle);
	m_velocity->set(cosf(radians) * velocityConstant, sinf(radians) * velocityConstant);
}