//
//  RedCreep.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "RedCreep.h"
#include "Vector2D.h"
#include "Rectangle.h"

RedCreep::RedCreep(float x, float y, float width, float height, float speed, int maxHealth, int pointValue, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : Creep (x, y, width, height, speed, maxHealth, pointValue, levelIndex, spawnPointIndex, isUsingAltPath)
{
	// No setup required
}
	
void RedCreep::freeze(float frozenTime, int freezeChance)
{
	// Red creeps are more likely to freeze
	Creep::freeze(frozenTime, freezeChance - 1);
}

bool RedCreep::isFlammable()
{
	return false;
}

bool RedCreep::applyDamage(int damage, Damage_Type damageType)
{
	if (damageType == Damage_Type::ICE)
	{
		m_health -= damage * 2;
		return true;
	}
	else if (damageType == Damage_Type::FIRE || damageType == Damage_Type::EXPLOSION)
	{
		return false;
	}
	
	m_health -= damage;
	return true;
}