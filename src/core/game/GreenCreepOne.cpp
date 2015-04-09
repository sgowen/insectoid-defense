//
//  GreenCreepOne.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "GreenCreepOne.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"

GreenCreepOne::GreenCreepOne(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : GreenCreep (x, y, 0.74f, 0.74f, 1.25f, World::getHealthAdjustmentForWave(wave, 4), wave / 4 + 2, levelIndex, spawnPointIndex, isUsingAltPath)
{
	// No setup required
}

Creep_Type GreenCreepOne::getCreepType()
{
	return Creep_Type::GREEN_CREEP_ONE;
}
	
void GreenCreepOne::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepOneBodyParts(creepBodyParts, 2);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LOWER_LEFT_WING_GREEN_1, 2, 102);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::CORE_GREEN_1, 2, 204);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LOWER_RIGHT_WING_GREEN_1, 2, 255);
}