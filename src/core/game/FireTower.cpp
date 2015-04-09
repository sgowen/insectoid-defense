//
//  FireTower.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "FireTower.h"
#include "Circle.h"
#include "Creep.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "World.h"
#include "FireBolt.h"
#include "GameListener.h"
#include "ResourceConstants.h"
#include "macros.h"

#include <math.h>

FireTower::FireTower(float x, float y) : Tower(Tower_Type::FIRE_TYPE, x, y, 1, 1, 2.75f, 7.0f, 50)
{
	m_fTimeSinceLastShot = 0;
	m_fCooldownTime = 1.20f;
	m_fProjectileWidth = 0.75f;
	m_fProjectileHeight = 0.2461f;
	m_fProjectileSpeed = 6.0f;
	m_iProjectileDamage = 400;
}

Tower_Type FireTower::getTowerType()
{
	return Tower_Type::FIRE_TYPE;
}

void FireTower::updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fTimeSinceLastShot += deltaTime;

	checkCreepInRadius(creeps);
}

void FireTower::fireAtCreep(Creep *creep)
{
	if (m_fTimeSinceLastShot > m_fCooldownTime)
	{
		float radians = DEGREES_TO_RADIANS(m_fAngle);
		float cos = cosf(radians);
		float sin = sinf(radians);
		
		World::getInstance()->getFireBolts().push_back(std::unique_ptr<FireBolt>(new FireBolt(m_position->getX() + (cos * 0.275f), m_position->getY() + (sin * 0.275f), m_fProjectileWidth, m_fProjectileHeight, m_fProjectileSpeed, m_fAngle, 4.0f + getStage(), m_iProjectileDamage)));
		m_fTimeSinceLastShot = 0;
        
        GameListener::getInstance()->playSound(SOUND_FIRE_BOLT);
	}
}

void FireTower::performUpgrade()
{
	m_fTimeSinceLastShot = 0;
	m_iUpgradeCost += 45;
	m_fCooldownTime -= 0.10f;
	m_fProjectileWidth += 0.125f;
	m_fProjectileHeight += 0.041015625f;
	m_fProjectileSpeed += 0.50f;
	m_iProjectileDamage *= 2;
	m_fProjectileSpeed += 0.25f;
	m_attackRadius->m_fRadius += 0.25f;
}