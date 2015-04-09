//
//  YellowCreepOne.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__YellowCreepOne__
#define __insectoiddefense__YellowCreepOne__

#include "YellowCreep.h"

class YellowCreepOne : public YellowCreep
{
public:
	YellowCreepOne(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);
};

#endif /* defined(__insectoiddefense__YellowCreepOne__) */