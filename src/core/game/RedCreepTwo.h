//
//  RedCreepTwo.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__RedCreepTwo__
#define __insectoiddefense__RedCreepTwo__

#include "RedCreep.h"

class RedCreepTwo : public RedCreep
{
public:
	RedCreepTwo(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);
};

#endif /* defined(__insectoiddefense__RedCreepTwo__) */