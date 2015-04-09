//
//  RedCreepTwo.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "RedCreepTwo.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"

RedCreepTwo::RedCreepTwo(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : RedCreep (x, y, 0.60f, 0.60f, 1.25f, World::getHealthAdjustmentForWave(wave, 4), wave / 7 + 2, levelIndex, spawnPointIndex, isUsingAltPath)
{
	// No setup required
}

Creep_Type RedCreepTwo::getCreepType()
{
	return Creep_Type::RED_CREEP_TWO;
}
	
void RedCreepTwo::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepTwoBodyParts(creepBodyParts, 2);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::ASS_RED_2, 2, 180);
}