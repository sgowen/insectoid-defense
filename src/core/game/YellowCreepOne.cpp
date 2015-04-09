//
//  YellowCreepOne.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "YellowCreepOne.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"

YellowCreepOne::YellowCreepOne(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : YellowCreep (x, y, 0.74f, 0.74f, World::getHealthAdjustmentForWave(wave, 4), wave / 4 + 2, levelIndex, spawnPointIndex, isUsingAltPath)
{
	// No setup required
}

Creep_Type YellowCreepOne::getCreepType()
{
	return Creep_Type::YELLOW_CREEP_ONE;
}
	
void YellowCreepOne::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepOneBodyParts(creepBodyParts, 2.5f);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LOWER_LEFT_WING_YELLOW_1, 2, 102);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::CORE_YELLOW_1, 2, 204);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LOWER_RIGHT_WING_YELLOW_1, 2, 255);
}