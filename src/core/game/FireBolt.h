//
//  FireBolt.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/8/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__FireBolt__
#define __insectoiddefense__FireBolt__

#include "pch.h"
#include "DynamicGameObject.h"
#include "FireBoltState.h"

#include <vector>
#include <memory>

class Creep;
class Vector2D;

class FireBolt : public DynamicGameObject
{
public:
	FireBolt(float x, float y, float width, float height, float velocityConstant, float directionalAngle, float totalBurnTime, int damage);

	void update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

	float getStateTime();

	Fire_Bolt_State getFireBoltState();

	bool remove();

private:
	Creep *m_burningCreep;
	std::unique_ptr<Vector2D> m_burnLocationRelativeToCreep;
	Fire_Bolt_State m_fireBoltState;
	float m_fStateTime;
	float m_fBurnTime;
	float m_fTotalBurnTime;
	float m_fTimeToDamageFromBurn;
	int m_iDamage;
	int m_iBurnDamageRate;
	bool m_remove;

	void setVelocity(float directionalAngle, float velocityConstant);

	void setState(Fire_Bolt_State fireBoltState);

	void checkCreepHitByProjectile(std::vector<std::unique_ptr<Creep>> &creeps);
};

#endif /* defined(__insectoiddefense__FireBolt__) */