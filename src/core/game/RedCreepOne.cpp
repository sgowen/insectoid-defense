//
//  RedCreepOne.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "RedCreepOne.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"

RedCreepOne::RedCreepOne(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : RedCreep (x, y, 0.74f, 0.74f, 1.25f, World::getHealthAdjustmentForWave(wave, 3), wave / 7 + 1, levelIndex, spawnPointIndex, isUsingAltPath)
{
	// No setup required
}

Creep_Type RedCreepOne::getCreepType()
{
	return Creep_Type::RED_CREEP_ONE;
}
	
void RedCreepOne::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepOneBodyParts(creepBodyParts, 2);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LOWER_LEFT_WING_RED_1, 2, 102);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::CORE_RED_1, 2, 204);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LOWER_RIGHT_WING_RED_1, 2, 255);
}