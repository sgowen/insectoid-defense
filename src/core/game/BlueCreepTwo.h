//
//  BlueCreepTwo.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/16/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__BlueCreepTwo__
#define __insectoiddefense__BlueCreepTwo__

#include "BlueCreep.h"

class BlueCreepTwo : public BlueCreep
{
public:
	BlueCreepTwo(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);
};

#endif /* defined(__insectoiddefense__BlueCreepTwo__) */