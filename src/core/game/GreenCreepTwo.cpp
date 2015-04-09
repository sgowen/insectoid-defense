//
//  GreenCreepTwo.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "GreenCreepTwo.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"

GreenCreepTwo::GreenCreepTwo(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : GreenCreep (x, y, 0.60f, 0.60f, 1.25f, World::getHealthAdjustmentForWave(wave, 5), wave / 4 + 3, levelIndex, spawnPointIndex, isUsingAltPath)
{
	// No setup required
}

Creep_Type GreenCreepTwo::getCreepType()
{
	return Creep_Type::GREEN_CREEP_TWO;
}
	
void GreenCreepTwo::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepTwoBodyParts(creepBodyParts, 2);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::ASS_GREEN_2, 2, 180);
}