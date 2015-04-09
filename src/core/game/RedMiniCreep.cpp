//
//  RedMiniCreep.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "RedMiniCreep.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"

RedMiniCreep::RedMiniCreep(float x, float y, int wave, int pathIndex, int direction, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : RedCreep (x, y, 0.40f, 0.40f, 1.00f, World::getHealthAdjustmentForWave(wave, 1), wave / 10 + 1, levelIndex, spawnPointIndex, isUsingAltPath)
{
	m_pathIndex = pathIndex;
	m_direction = direction;
}

Creep_Type RedMiniCreep::getCreepType()
{
	return Creep_Type::RED_CREEP_THREE;
}
	
void RedMiniCreep::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepThreeBodyParts(creepBodyParts, 2);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LEFT_CHARGE_RED_3, 2, 120);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::RIGHT_CHARGE_RED_3, 2, 240);
}