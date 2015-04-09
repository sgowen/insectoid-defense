//
//  BossCreep.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__BossCreep__
#define __insectoiddefense__BossCreep__

#include "Creep.h"

class BossCreep : public Creep
{
public:
	BossCreep(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual Creep_Type getCreepType();

	virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts);

protected:
	virtual bool applyDamage(int damage, Damage_Type damageType);
};

#endif /* defined(__insectoiddefense__BossCreep__) */