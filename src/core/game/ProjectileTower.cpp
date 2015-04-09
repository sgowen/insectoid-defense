//
//  ProjectileTower.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "ProjectileTower.h"
#include "Circle.h"
#include "Creep.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "World.h"
#include "Projectile.h"
#include "macros.h"

#include <math.h>

ProjectileTower::ProjectileTower(float x, float y) : Tower(Tower_Type::PROJECTILE_TYPE, x, y, 1, 1, 1.5f, 4.0f, 25)
{
	m_fTimeSinceLastShot = 0;
	m_fCooldownTime = 0.30f;
	m_fProjectileSize = 0.15f;
	m_fProjectileSpeed = 4.5f;
	m_iProjectileDamage = 80;
}

Tower_Type ProjectileTower::getTowerType()
{
	return Tower_Type::PROJECTILE_TYPE;
}

void ProjectileTower::updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fTimeSinceLastShot += deltaTime;
	
	checkCreepInRadius(creeps);
}

void ProjectileTower::fireAtCreep(Creep *creep)
{
	if (m_fTimeSinceLastShot > m_fCooldownTime)
	{
		float radians = DEGREES_TO_RADIANS(m_fAngle);
		float cos = cosf(radians);
		float sin = sinf(radians);
		
		World::getInstance()->getProjectiles().push_back(std::unique_ptr<Projectile>(new Projectile(m_position->getX() + (cos * 0.275f), m_position->getY() + (sin * 0.275f), m_fProjectileSize, m_fProjectileSize, m_fProjectileSpeed, m_fAngle, m_iProjectileDamage, getStage() == 2)));
		m_fTimeSinceLastShot = 0;
	}
}

void ProjectileTower::performUpgrade()
{
	m_fTimeSinceLastShot = 0;
	m_iUpgradeCost += 20;
	m_fCooldownTime -= 0.025f;
	m_fProjectileSize += 0.025f;
	m_fProjectileSpeed += 0.25f;
	m_iProjectileDamage *= 2;
	m_attackRadius->m_fRadius += 0.1f;
}