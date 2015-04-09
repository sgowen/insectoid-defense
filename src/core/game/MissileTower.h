//
//  MissileTower.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__MissileTower__
#define __insectoiddefense__MissileTower__

#include "Tower.h"
#include "Missile.h"
#include "ExplosionType.h"
#include "MissileState.h"

class MissileTower : public Tower
{
public:
	MissileTower(float x, float y);

	virtual Tower_Type getTowerType();

protected:
	virtual void updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

	virtual void fireAtCreep(Creep *creep);

	virtual void performUpgrade();

	virtual void checkCreepInRadius(std::vector<std::unique_ptr<Creep>> &creeps);

private:
	Explosion_Type m_explosionType;
	Missile_State m_missileState;
	float m_fProjectileSpeed;
	float m_fMissileWaitTime;
	float m_fTimeSinceLastShot;
	float m_fCooldownTime;
	float m_fProjectileWidth;
	float m_fProjectileHeight;
	int m_iProjectileDamage;
	int m_iMissilesFired;
};

#endif /* defined(__insectoiddefense__MissileTower__) */