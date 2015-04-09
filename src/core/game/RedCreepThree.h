//
//  RedCreepThree.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__RedCreepThree__
#define __insectoiddefense__RedCreepThree__

#include "RedCreep.h"

class RedCreepThree : public RedCreep
{
public:
	RedCreepThree(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);

	virtual void deploy(std::vector<Creep *> &creeps, int wave);

	virtual void kill(Damage_Type damageType);

private:
	int m_iWave;
};

#endif /* defined(__insectoiddefense__RedCreepThree__) */