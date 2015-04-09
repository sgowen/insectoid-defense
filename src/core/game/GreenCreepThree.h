//
//  GreenCreepThree.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__GreenCreepThree__
#define __insectoiddefense__GreenCreepThree__

#include "GreenCreep.h"

class GreenCreepThree : public GreenCreep
{
public:
	GreenCreepThree(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);

	virtual void deploy(std::vector<Creep *> &creeps, int wave);

	virtual void kill(Damage_Type damageType);

private:
	int m_iWave;
};

#endif /* defined(__insectoiddefense__GreenCreepThree__) */