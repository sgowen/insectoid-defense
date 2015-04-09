//
//  BlueMiniCreep.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/16/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__BlueMiniCreep__
#define __insectoiddefense__BlueMiniCreep__

#include "BlueCreep.h"

class BlueMiniCreep : public BlueCreep
{
public:
	BlueMiniCreep(float x, float y, int wave, int pathIndex, int direction, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);
};

#endif /* defined(__insectoiddefense__BlueMiniCreep__) */