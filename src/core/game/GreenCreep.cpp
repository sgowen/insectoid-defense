//
//  GreenCreep.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "GreenCreep.h"
#include "FlagUtil.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "GameConstants.h"

GreenCreep::GreenCreep(float x, float y, float width, float height, float speed, int maxHealth, int pointValue, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : Creep (x, y, width, height, speed, maxHealth, pointValue, levelIndex, spawnPointIndex, isUsingAltPath)
{
	m_fTimeToRecover = 0.25f;
	m_fRecoveryTime = 0;
	m_iRecoveryRate = maxHealth / 60;
}
	
void GreenCreep::update(float deltaTime)
{
	Creep::update(deltaTime);
	
	if (!FlagUtil::isFlagSet(m_creepCondition, ON_FIRE) && m_health < m_maxHealth)
	{
		m_fRecoveryTime += deltaTime;

		if (m_fRecoveryTime > m_fTimeToRecover)
		{
			m_fRecoveryTime -= m_fTimeToRecover;
			m_health += m_iRecoveryRate;
			
			if (m_health > m_maxHealth)
			{
				m_health = m_maxHealth;
			}

			displayHealthBar();
		}
	}
}

void GreenCreep::poison(float poisonedTime, int damage)
{
	// Green creeps cannot be poisoned.
}

bool GreenCreep::applyDamage(int damage, Damage_Type damageType)
{
	if (damageType == FIRE || damageType == EXPLOSION)
	{
		m_health -= damage * 2;
		return true;
	}
	else if (damageType == ACID)
	{
		return false;
	}
	
	m_health -= damage;
	return true;
}