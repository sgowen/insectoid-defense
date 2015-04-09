//
//  BlueCreepOne.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/10/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__BlueCreepOne__
#define __insectoiddefense__BlueCreepOne__

#include "BlueCreep.h"

class BlueCreepOne : public BlueCreep
{
public:
	BlueCreepOne(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);
};

#endif /* defined(__insectoiddefense__BlueCreepOne__) */