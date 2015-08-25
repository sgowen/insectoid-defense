//
//  YellowCreep.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "YellowCreep.h"
#include "FlagUtil.h"
#include "Vector2D.h"
#include "Rectangle.h"

YellowCreep::YellowCreep(float x, float y, float width, float height, int maxHealth, int pointValue, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : Creep (x, y, width, height, 2.50f, maxHealth, pointValue, levelIndex, spawnPointIndex, isUsingAltPath)
{
	// No setup required
}

bool YellowCreep::canStick()
{
	// Yellow creeps cannot be stuck
	return false;
}

void YellowCreep::electrify()
{
	// Yellow creeps cannot be electrified
}

bool YellowCreep::applyDamage(int damage, Damage_Type damageType)
{
	if (damageType == ACID)
	{
		m_health -= damage * 3;
		return true;
	}
	else if (damageType == ELECTRIC)
	{
		return false;
	}
	
	m_health -= damage;
	return true;
}