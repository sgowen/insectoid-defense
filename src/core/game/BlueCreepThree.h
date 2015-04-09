//
//  BlueCreepThree.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/16/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__BlueCreepThree__
#define __insectoiddefense__BlueCreepThree__

#include "BlueCreep.h"

class BlueCreepThree : public BlueCreep
{
public:
	BlueCreepThree(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);

	virtual void deploy(std::vector<Creep *> &creeps, int wave);

	virtual void kill(Damage_Type damageType);

private:
	int m_iWave;
};

#endif /* defined(__insectoiddefense__BlueCreepThree__) */