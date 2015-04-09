//
//  YellowMiniCreep.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__YellowMiniCreep__
#define __insectoiddefense__YellowMiniCreep__

#include "YellowCreep.h"

class YellowMiniCreep : public YellowCreep
{
public:
	YellowMiniCreep(float x, float y, int wave, int pathIndex, int direction, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);
};

#endif /* defined(__insectoiddefense__YellowMiniCreep__) */