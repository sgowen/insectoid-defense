//
//  GreenMiniCreep.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__GreenMiniCreep__
#define __insectoiddefense__GreenMiniCreep__

#include "GreenCreep.h"

class GreenMiniCreep : public GreenCreep
{
public:
	GreenMiniCreep(float x, float y, int wave, int pathIndex, int direction, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);
};

#endif /* defined(__insectoiddefense__GreenMiniCreep__) */