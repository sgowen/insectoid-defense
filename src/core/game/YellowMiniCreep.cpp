//
//  YellowMiniCreep.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "YellowMiniCreep.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"

YellowMiniCreep::YellowMiniCreep(float x, float y, int wave, int pathIndex, int direction, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : YellowCreep (x, y, 0.40f, 0.40f, World::getHealthAdjustmentForWave(wave, 1), wave / 10 + 1, levelIndex, spawnPointIndex, isUsingAltPath)
{
	m_pathIndex = pathIndex;
	m_direction = direction;
}

Creep_Type YellowMiniCreep::getCreepType()
{
	return Creep_Type::YELLOW_CREEP_THREE;
}
	
void YellowMiniCreep::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepThreeBodyParts(creepBodyParts, 2.5f);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LEFT_CHARGE_YELLOW_3, 2, 120);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::RIGHT_CHARGE_YELLOW_3, 2, 240);
}