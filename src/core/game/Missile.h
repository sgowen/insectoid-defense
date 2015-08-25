//
//  Missile.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/7/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__Missile__
#define __insectoiddefense__Missile__


#include "PhysicalEntity.h"
#include "ExplosionType.h"

#include <vector>
#include <memory>

class Explosion;
class Circle;
class Creep;

class Missile : public PhysicalEntity
{
public:
	Missile(float x, float y, float width, float height, float velocityConstant, float directionalAngle, int damage, Explosion_Type explosionType, Creep *target);

	void update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps, std::vector<std::unique_ptr<Explosion>> &explosions);

	bool remove();

private:
	Creep *m_target;
	Explosion_Type m_explosionType;
	float m_fVelocityConstant;
	float m_fBlastRadius;
	int m_iDamage;
	bool m_isCreepDead;
	bool m_remove;

	void explode(std::vector<std::unique_ptr<Creep>> &creeps, std::vector<std::unique_ptr<Explosion>> &explosions, Vector2D &position, Explosion_Type explosionType);

	bool checkCreepHitByProjectile(std::vector<std::unique_ptr<Creep>> &creeps, std::vector<std::unique_ptr<Explosion>> &explosions);

	void checkMissileTouchingExplosion(std::vector<std::unique_ptr<Creep>> &creeps, std::vector<std::unique_ptr<Explosion>> &explosions);

	void setVelocity(float directionalAngle, float velocityConstant);
};

#endif /* defined(__insectoiddefense__Missile__) */