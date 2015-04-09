//
//  RedCreep.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__RedCreep__
#define __insectoiddefense__RedCreep__

#include "Creep.h"

class RedCreep : public Creep
{
public:
	RedCreep(float x, float y, float width, float height, float speed, int maxHealth, int pointValue, int levelIndex, int spawnPointIndex, bool isUsingAltPath);
	
	virtual void freeze(float frozenTime, int freezeChance);
	
	virtual bool isFlammable();

protected:
	bool applyDamage(int damage, Damage_Type damageType);
};

#endif /* defined(__insectoiddefense__RedCreep__) */