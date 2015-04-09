//
//  GreenCreepTwo.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__GreenCreepTwo__
#define __insectoiddefense__GreenCreepTwo__

#include "GreenCreep.h"

class GreenCreepTwo : public GreenCreep
{
public:
	GreenCreepTwo(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);
};

#endif /* defined(__insectoiddefense__GreenCreepTwo__) */