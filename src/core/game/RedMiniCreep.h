//
//  RedMiniCreep.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__RedMiniCreep__
#define __insectoiddefense__RedMiniCreep__

#include "RedCreep.h"

class RedMiniCreep : public RedCreep
{
public:
	RedMiniCreep(float x, float y, int wave, int pathIndex, int direction, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);
};

#endif /* defined(__insectoiddefense__RedMiniCreep__) */