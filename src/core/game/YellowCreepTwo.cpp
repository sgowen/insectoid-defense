//
//  YellowCreepTwo.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "YellowCreepTwo.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"

YellowCreepTwo::YellowCreepTwo(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : YellowCreep (x, y, 0.60f, 0.60f, World::getHealthAdjustmentForWave(wave, 5), wave / 4 + 3, levelIndex, spawnPointIndex, isUsingAltPath)
{
	// No setup required
}

Creep_Type YellowCreepTwo::getCreepType()
{
	return Creep_Type::YELLOW_CREEP_TWO;
}
	
void YellowCreepTwo::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepTwoBodyParts(creepBodyParts, 2.5f);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::ASS_YELLOW_2, 2.5f, 180);
}