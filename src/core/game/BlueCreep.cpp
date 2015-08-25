//
//  BlueCreep.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/10/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "BlueCreep.h"
#include "FlagUtil.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "GameConstants.h"

BlueCreep::BlueCreep(float x, float y, float width, float height, float speed, int maxHealth, int pointValue, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : Creep (x, y, width, height, speed, maxHealth, pointValue, levelIndex, spawnPointIndex, isUsingAltPath)
{
	// No setup required
}
	
void BlueCreep::freeze(float frozenTime, int freezeChance)
{
	// Blue Creeps cannot be frozen
}

bool BlueCreep::canMissilesTarget()
{
	return FlagUtil::isFlagSet(m_creepCondition, ON_FIRE);
}

bool BlueCreep::applyDamage(int damage, Damage_Type damageType)
{
	if (damageType == ELECTRIC)
	{
		m_health -= damage * 2;
		return true;
	}
	else if (damageType == ICE)
	{
		return false;
	}

	m_health -= damage;
	return true;
}