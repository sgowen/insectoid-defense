//
//  GreenCreep.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__GreenCreep__
#define __insectoiddefense__GreenCreep__

#include "Creep.h"

class GreenCreep : public Creep
{
public:
	GreenCreep(float x, float y, float width, float height, float speed, int maxHealth, int pointValue, int levelIndex, int spawnPointIndex, bool isUsingAltPath);

	virtual void update(float deltaTime);
	
	virtual void poison(float poisonedTime, int damage);

protected:
	virtual bool applyDamage(int damage, Damage_Type damageType);

private:
	float m_fTimeToRecover;
	float m_fRecoveryTime;
	int m_iRecoveryRate;
};

#endif /* defined(__insectoiddefense__GreenCreep__) */