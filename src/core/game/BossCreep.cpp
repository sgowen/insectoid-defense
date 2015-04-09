//
//  BossCreep.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "BossCreep.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"

BossCreep::BossCreep(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : Creep (x, y, 0.90f, 0.90f, 1.0f, World::getHealthAdjustmentForWave(wave, 11), 25 * (wave / 10), levelIndex, spawnPointIndex, isUsingAltPath)
{
	// No setup required
}

Creep_Type BossCreep::getCreepType()
{
	return Creep_Type::BOSS_CREEP;
}
	
void BossCreep::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::HEAD_BOSS, 2.2f, 0);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LEFT_UPPER_WING_BOSS, 2.2f, 45);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LEFT_LOWER_WING_BOSS, 2.2f, 90);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LEFT_TAIL_BOSS, 2.2f, 135);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::CORE_BOSS, 2.2f, 180);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::RIGHT_TAIL_BOSS, 2.2f, 225);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::RIGHT_LOWER_WING_BOSS, 2.2f, 270);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::RIGHT_UPPER_WING_BOSS, 2.2f, 315);
}

bool BossCreep::applyDamage(int damage, Damage_Type damageType)
{
	m_health -= damage;
	return true;
}