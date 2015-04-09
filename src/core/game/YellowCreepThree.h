//
//  YellowCreepThree.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__YellowCreepThree__
#define __insectoiddefense__YellowCreepThree__

#include "YellowCreep.h"

class YellowCreepThree : public YellowCreep
{
public:
	YellowCreepThree(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);

	virtual void deploy(std::vector<Creep *> &creeps, int wave);

	virtual void kill(Damage_Type damageType);

private:
	int m_iWave;
};

#endif /* defined(__insectoiddefense__YellowCreepThree__) */