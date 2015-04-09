//
//  BlueMiniCreep.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/16/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "BlueMiniCreep.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"

BlueMiniCreep::BlueMiniCreep(float x, float y, int wave, int pathIndex, int direction, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : BlueCreep (x, y, 0.40f, 0.40f, 1.00f, World::getHealthAdjustmentForWave(wave, 1), wave / 10 + 1, levelIndex, spawnPointIndex, isUsingAltPath)
{
	m_pathIndex = pathIndex;
	m_direction = direction;
}

Creep_Type BlueMiniCreep::getCreepType()
{
	return Creep_Type::BLUE_CREEP_THREE;
}
	
void BlueMiniCreep::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepThreeBodyParts(creepBodyParts, 2);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LEFT_CHARGE_BLUE_3, 2, 120);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::RIGHT_CHARGE_BLUE_3, 2, 240);
}