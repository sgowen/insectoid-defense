//
//  BlueCreep.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/10/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__BlueCreep__
#define __insectoiddefense__BlueCreep__

#include "Creep.h"

class BlueCreep : public Creep
{
public:
	BlueCreep(float x, float y, float width, float height, float speed, int maxHealth, int pointValue, int levelIndex, int spawnPointIndex, bool isUsingAltPath);
	
	virtual void freeze(float frozenTime, int freezeChance);
	
	virtual bool canMissilesTarget();

protected:
	bool applyDamage(int damage, Damage_Type damageType);
};

#endif /* defined(__insectoiddefense__BlueCreep__) */