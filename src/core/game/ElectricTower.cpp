//
//  ElectricTower.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "ElectricTower.h"
#include "ElectricBolt.h"
#include "Circle.h"
#include "Creep.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "World.h"
#include "Assets.h"
#include "GameListener.h"
#include "ResourceConstants.h"
#include "macros.h"

#include <math.h>

ElectricTower::ElectricTower(float x, float y) : Tower(Tower_Type::ELECTRIC_TYPE, x, y, 1, 1, 1.5f, 5.0f, 35)
{
	m_fTimeSinceLastShot = 0;
	m_fCooldownTime = 1.00f;
	m_fProjectileWidth = 0.50f;
	m_fProjectileHeight = 0.16f;
	m_fProjectileSpeed = 5.5f;
	m_iProjectileDamage = 80;
	m_iFadeTimeSeconds = 1;
}

Tower_Type ElectricTower::getTowerType()
{
	return Tower_Type::ELECTRIC_TYPE;
}

void ElectricTower::updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fTimeSinceLastShot += deltaTime;

	checkCreepInRadius(creeps);
}

void ElectricTower::fireAtCreep(Creep *creep)
{
	if (m_fTimeSinceLastShot > m_fCooldownTime)
	{
        GameListener::getInstance()->playSound(SOUND_ELECTRIC_BOLT);

        float radians = DEGREES_TO_RADIANS(m_fAngle);
		float cos = cosf(radians);
		float sin = sinf(radians);

		if (getStage() == 0 || getStage() == 2)
		{
			World::getInstance()->getElectricBolts().push_back(std::unique_ptr<ElectricBolt>(new ElectricBolt(m_position->getX() + (cos * 0.40f), m_position->getY() + (sin * 0.40f), m_fProjectileWidth, m_fProjectileHeight, m_fProjectileSpeed, m_fAngle, m_iProjectileDamage, m_iFadeTimeSeconds)));
		}

		if (getStage() >= 1)
		{
			float alteredAngle = m_fAngle + 90;
			if (alteredAngle >= 360)
			{
				alteredAngle -= 360;
			}

            float alteredRadians = DEGREES_TO_RADIANS(alteredAngle);
			float alteredCos = cosf(alteredRadians);
			float alteredSin = sinf(alteredRadians);

			float xOffset = alteredCos * 0.225f;
			float yOffset = alteredSin * 0.225f;

			World::getInstance()->getElectricBolts().push_back(std::unique_ptr<ElectricBolt>(new ElectricBolt(m_position->getX() + (cos * 0.52f) + xOffset, m_position->getY() + (sin * 0.52f) + yOffset, m_fProjectileWidth, m_fProjectileHeight, m_fProjectileSpeed, m_fAngle, m_iProjectileDamage, m_iFadeTimeSeconds)));
			World::getInstance()->getElectricBolts().push_back(std::unique_ptr<ElectricBolt>(new ElectricBolt(m_position->getX() + (cos * 0.52f) - xOffset, m_position->getY() + (sin * 0.52f) - yOffset, m_fProjectileWidth, m_fProjectileHeight, m_fProjectileSpeed, m_fAngle, m_iProjectileDamage, m_iFadeTimeSeconds)));
		}

		m_fTimeSinceLastShot = 0;
	}
}

void ElectricTower::performUpgrade()
{
	m_iUpgradeCost += 25;
	m_fTimeSinceLastShot = 0;
	m_fCooldownTime -= 0.1f;
	m_fProjectileWidth += 0.05f;
	m_fProjectileHeight += 0.025f;
	m_fProjectileSpeed += 0.25f;
	m_iFadeTimeSeconds++;
}