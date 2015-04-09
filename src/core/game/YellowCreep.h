//
//  YellowCreep.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__YellowCreep__
#define __insectoiddefense__YellowCreep__

#include "Creep.h"

class YellowCreep : public Creep
{
public:
	YellowCreep(float x, float y, float width, float height, int maxHealth, int pointValue, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual bool canStick();
	
	virtual void electrify();

protected:
	virtual bool applyDamage(int damage, Damage_Type damageType);
};

#endif /* defined(__insectoiddefense__YellowCreep__) */