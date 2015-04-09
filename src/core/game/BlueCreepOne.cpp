//
//  BlueCreepOne.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/10/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "BlueCreepOne.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"

BlueCreepOne::BlueCreepOne(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : BlueCreep (x, y, 0.74f, 0.74f, 1.25f, World::getHealthAdjustmentForWave(wave, 3), wave / 7 + 1, levelIndex, spawnPointIndex, isUsingAltPath)
{
	// No setup required
}

Creep_Type BlueCreepOne::getCreepType()
{
	return Creep_Type::BLUE_CREEP_ONE;
}
	
void BlueCreepOne::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepOneBodyParts(creepBodyParts, 2);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LOWER_LEFT_WING_BLUE_1, 2, 102);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::CORE_BLUE_1, 2, 204);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LOWER_RIGHT_WING_BLUE_1, 2, 255);
}