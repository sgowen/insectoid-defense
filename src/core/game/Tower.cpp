//
//  Tower.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "Tower.h"
#include "TowerCostMapper.h"
#include "OverlapTester.h"
#include "Circle.h"
#include "Creep.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "UniqueIDUtil.h"
#include "GameListener.h"
#include "ResourceConstants.h"

Tower::Tower(Tower_Type towerType, float x, float y, float width, float height, float radius, float upgradeTime, int upgradeCost) : PhysicalEntity(x, y, width, height, 0)
{
	m_attackRadius = std::unique_ptr<Circle>(new Circle(x, y, radius));
	m_upgradeCursor = std::unique_ptr<Circle>(new Circle(x, y, 0.4f));
	
	m_fUpgradeTime = upgradeTime;
	m_fUpgradeProgressTime = 0;
	m_iUpgradeCost = upgradeCost;
	m_iSellAmount = TowerCostMapper::getCostForTowerType(towerType) / 2;
	m_state = Tower_State::READY;
	m_iStage = 0;
	m_iTowerID = UniqueIDUtil::getUniqueTowerID();
}

void Tower::update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	if (m_state == Tower_State::UPGRADING)
	{
		m_fUpgradeProgressTime += deltaTime;

		if (m_fUpgradeProgressTime > m_fUpgradeTime)
		{
			m_upgradeCursor->m_fRadius = 0.4f;
			m_iSellAmount += m_iUpgradeCost / 2;
			m_fUpgradeProgressTime = 0;
			m_fUpgradeTime *= 2;

			m_iStage++;

			performUpgrade();

			m_state = Tower_State::READY;

            GameListener::getInstance()->playSound(SOUND_TOWER_UPGRADED);
		}
	}
	else
	{
		updateReady(deltaTime, creeps);
	}
	
	updatePhysics(deltaTime, creeps);
}

void Tower::upgrade()
{
	if (m_iStage < 2)
	{
		m_state = Tower_State::UPGRADING;
	}
}

int Tower::getUpgradeCursorArcDegrees()
{
	return m_fUpgradeProgressTime > m_fUpgradeTime ? 360 : (int) (360 * (m_fUpgradeProgressTime / m_fUpgradeTime));
}

Circle & Tower::getUpgradeCursor()
{
	return *m_upgradeCursor;
}

Circle & Tower::getAttackRadius()
{
	return *m_attackRadius;
}

Tower_State Tower::getState()
{
	return m_state;
}

int Tower::getUpgradeCost()
{
	return m_iUpgradeCost;
}

int Tower::getSellAmount()
{
	return m_iSellAmount;
}

int Tower::getStage()
{
	return m_iStage;
}

void Tower::onRemove()
{
	// Override for Towers that need to release resources
}

int Tower::getID()
{
	return m_iTowerID;
}

void Tower::checkCreepInRadius(std::vector<std::unique_ptr<Creep>> &creeps)
{
	for (std::vector<std::unique_ptr<Creep>>::iterator itr = creeps.begin(); itr != creeps.end(); itr++)
	{
		if (OverlapTester::isPointInCircle((*itr)->getPosition(), *m_attackRadius))
		{
			Vector2D creepPosition = (*itr)->getPosition().cpy();
			m_fAngle = creepPosition.sub(m_position->getX(), m_position->getY()).angle();
			
			fireAtCreep(itr->get());
			
			return;
		}
	}
}

void Tower::updatePhysics(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	// Override for Towers that need to update their own physics
}