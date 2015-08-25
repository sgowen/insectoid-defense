//
//  PoisonTower.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "PoisonTower.h"
#include "Circle.h"
#include "Creep.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "AcidDrop.h"
#include "World.h"
#include "GameListener.h"
#include "ResourceConstants.h"

PoisonTower::PoisonTower(float x, float y) : Tower(Tower_Type::POISON_TYPE, x, y, 1, 1, 3.0f, 8.0f, 55)
{
	m_fTimeSinceLastShot = 0;
	m_fCooldownTime = 2.00f;
	m_fProjectileWidth = 0.30f;
	m_fProjectileHeight = 0.215f;
	m_fProjectileSpeed = 6.5f;
	m_fPoisonTime = 4;
	m_fPoisonToCreepHealthRatio = 0.01f;
}

Tower_Type PoisonTower::getTowerType()
{
	return Tower_Type::POISON_TYPE;
}

void PoisonTower::updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fTimeSinceLastShot += deltaTime;

	checkCreepInRadius(creeps);
}

void PoisonTower::fireAtCreep(Creep *creep)
{
	if (m_fTimeSinceLastShot > m_fCooldownTime)
	{
		m_fTimeSinceLastShot = 0;
		Rectangle *destinationBounds = new Rectangle(creep->getBounds().getLowerLeft().getX(), creep->getBounds().getLowerLeft().getY(), creep->getBounds().getWidth(), creep->getBounds().getHeight());
		World::getInstance()->getAcidDrops().push_back(std::unique_ptr<AcidDrop>(new AcidDrop(m_position->getX(), m_position->getY(), m_fProjectileWidth, m_fProjectileHeight, m_fProjectileSpeed, m_fAngle, destinationBounds, m_fPoisonTime, m_fPoisonToCreepHealthRatio)));
        
        GameListener::getInstance()->playSound(SOUND_ACID_DROP);
	}
}

void PoisonTower::performUpgrade()
{
	m_fTimeSinceLastShot = 0;
	m_iUpgradeCost += 35;
	m_fCooldownTime -= 0.2f;
	m_fProjectileWidth += 0.05f;
	m_fProjectileHeight += 0.036f;
	m_attackRadius->m_fRadius += 0.50f;
	m_fPoisonTime += 0.50f;
	m_fPoisonToCreepHealthRatio += 0.005f;
}