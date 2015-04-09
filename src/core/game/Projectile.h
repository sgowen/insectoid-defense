//
//  Projectile.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__Projectile__
#define __insectoiddefense__Projectile__

#include "pch.h"
#include "DynamicGameObject.h"
#include "ProjectileState.h"
#include "Color.h"

#include <vector>
#include <memory>

class Creep;

class Projectile : public DynamicGameObject
{
public:
	Projectile(float x, float y, float width, float height, float velocityConstant, float directionalAngle, int damage, bool isSticky);

	void update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

	Projectile_State getProjectileState();

	void zap(int zapDamage);

	Color getColor();

	float getStateTime();

	bool remove();

private:
	Creep *m_stuckCreep;
	std::unique_ptr<Vector2D> m_stickLocationRelativeToCreep;
	Projectile_State m_projectileState;
	float m_fAlpha;
	float m_fRed;
	float m_fGreen;
	float m_fBlue;
	float m_fStateTime;
	int m_iZapDamage;
	int m_iDamage;
	bool m_isSticky;
	bool m_remove;

	void setVelocity(float directionalAngle, float velocityConstant);

	void setState(Projectile_State projectileState);

	void checkCreepHitByProjectile(std::vector<std::unique_ptr<Creep>> &creeps);
};

#endif /* defined(__insectoiddefense__Projectile__) */