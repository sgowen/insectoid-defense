//
//  FireTower.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__FireTower__
#define __insectoiddefense__FireTower__

#include "Tower.h"

class FireTower : public Tower
{
public:
	FireTower(float x, float y);

	virtual Tower_Type getTowerType();

protected:
	virtual void updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

	virtual void fireAtCreep(Creep *creep);

	virtual void performUpgrade();

private:
	float m_fTimeSinceLastShot;
	float m_fCooldownTime;
	float m_fProjectileWidth;
	float m_fProjectileHeight;
	float m_fProjectileSpeed;
	int m_iProjectileDamage;
};

#endif /* defined(__insectoiddefense__FireTower__) */