//
//  FireBolt.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/8/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "FireBolt.h"
#include "Creep.h"
#include "Vector2D.h"
#include "ScreenUtils.h"
#include "FlagUtil.h"
#include "OverlapTester.h"
#include "macros.h"

#include <math.h>

FireBolt::FireBolt(float x, float y, float width, float height, float velocityConstant, float directionalAngle, float totalBurnTime, int damage) : DynamicGameObject(x, y, width, height, directionalAngle)
{
	m_fTotalBurnTime = totalBurnTime;
	m_fTimeToDamageFromBurn = 0.1f;
	m_iDamage = damage;
	m_iBurnDamageRate = damage / 40;

	setState(Fire_Bolt_State::LAUNCHED);
	m_fBurnTime = 0;
	m_remove = false;

	setVelocity(directionalAngle, velocityConstant);
}

void FireBolt::update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fStateTime += deltaTime;

	if (m_fireBoltState == Fire_Bolt_State::LAUNCHED)
	{
		m_position->add(m_velocity->getX() * deltaTime, m_velocity->getY() * deltaTime);
		updateBounds();

		m_remove = ScreenUtils::isVectorOffScreen(*m_position);

		checkCreepHitByProjectile(creeps);
	}
	else if (m_fireBoltState == Fire_Bolt_State::BURNING)
	{
		if(m_remove)
		{
			return;
		}

		m_remove = m_burningCreep->isDead();

		if(m_remove)
		{
			return;
		}

		if (FlagUtil::isFlagSet(m_burningCreep->getCreepCondition(), ON_FIRE))
		{
			m_fBurnTime += deltaTime;

			m_position->set(m_burningCreep->getPosition());
			m_position->add(m_burnLocationRelativeToCreep->getX(), m_burnLocationRelativeToCreep->getY());
			updateBounds();

			if (m_fStateTime < m_fTotalBurnTime)
			{
				int damage = 0;

				while (m_fBurnTime > m_fTimeToDamageFromBurn)
				{
					m_fBurnTime -= m_fTimeToDamageFromBurn;
					damage += m_iBurnDamageRate;
				}

				m_burningCreep->takeDamage(damage, FIRE);

				m_remove = m_burningCreep->isDead();
			}
			else
			{
				m_remove = true;
			}
		}
		else
		{
			m_remove = true;
		}
	}
}

float FireBolt::getStateTime()
{
	return m_fStateTime;
}

Fire_Bolt_State FireBolt::getFireBoltState()
{
	return m_fireBoltState;
}

bool FireBolt::remove()
{
	return m_remove;
}

// Private Methods

void FireBolt::setVelocity(float directionalAngle, float velocityConstant)
{
    float radians = DEGREES_TO_RADIANS(directionalAngle);
	m_velocity->set(cosf(radians) * velocityConstant, sinf(radians) * velocityConstant);
}

void FireBolt::setState(Fire_Bolt_State fireBoltState)
{
	m_fireBoltState = fireBoltState;
	m_fStateTime = 0;
}

void FireBolt::checkCreepHitByProjectile(std::vector<std::unique_ptr<Creep>> &creeps)
{
	for (std::vector<std::unique_ptr<Creep>>::iterator itr = creeps.begin(); itr != creeps.end(); itr++)
	{
		if (OverlapTester::isPointInRectangle(*m_position, (*itr)->getBounds()))
		{
			(*itr)->takeDamage(m_iDamage, FIRE);

			bool isCreepDead = (*itr)->isDead();

			if (isCreepDead)
			{
				m_remove = true;
			}
			else
			{
				if ((*itr)->isFlammable())
				{
					(*itr)->setOnFire(m_fTotalBurnTime);
					setState(Fire_Bolt_State::BURNING);
					m_fAngle = 90;
					m_burningCreep = itr->get();
					m_burnLocationRelativeToCreep = std::unique_ptr<Vector2D>(new Vector2D(m_position->getX() - (*itr)->getPosition().getX(), m_position->getY() - (*itr)->getPosition().getY()));
				}
			}
		}
	}
}