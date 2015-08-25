//
//  Explosion.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/7/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__Explosion__
#define __insectoiddefense__Explosion__


#include "PhysicalEntity.h"
#include "ExplosionType.h"

#include <vector>
#include <memory>

class Creep;
class Circle;

class Explosion : public PhysicalEntity
{
public:
	Explosion(float x, float y, float blastRadius, Explosion_Type type, int damageRate);

	void update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);
	
	Circle & getDamageRadius();
	
	Explosion_Type getType();
	
	bool remove();

private:
	std::unique_ptr<Circle> m_damageRadius;
	Explosion_Type m_type;
	float m_fExplosionTime;
	float m_fDamageTime;
	float m_fFireTime;
	int m_iDamageRate;
	int m_iDamage;
	bool m_remove;
};

#endif /* defined(__insectoiddefense__Explosion__) */