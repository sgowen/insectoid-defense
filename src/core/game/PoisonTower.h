//
//  PoisonTower.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__PoisonTower__
#define __insectoiddefense__PoisonTower__

#include "Tower.h"

class PoisonTower : public Tower
{
public:
	PoisonTower(float x, float y);

	virtual Tower_Type getTowerType();

protected:
	virtual void updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

	virtual void fireAtCreep(Creep *creep);

	virtual void performUpgrade();

private:
	float m_fProjectileSpeed;
	float m_fTimeSinceLastShot;
	float m_fCooldownTime;
	float m_fProjectileWidth;
	float m_fProjectileHeight;
	float m_fPoisonTime;
	float m_fPoisonToCreepHealthRatio;
};

#endif /* defined(__insectoiddefense__PoisonTower__) */