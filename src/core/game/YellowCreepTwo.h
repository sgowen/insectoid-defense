//
//  YellowCreepTwo.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__YellowCreepTwo__
#define __insectoiddefense__YellowCreepTwo__

#include "YellowCreep.h"

class YellowCreepTwo : public YellowCreep
{
public:
	YellowCreepTwo(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);
};

#endif /* defined(__insectoiddefense__YellowCreepTwo__) */