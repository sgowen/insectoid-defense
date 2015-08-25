//
//  Tower.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "TowerCursor.h"
#include "TowerCostMapper.h"
#include "Text.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "WorldPlatform.h"
#include "ProjectileTower.h"
#include "ElectricTower.h"
#include "LazerTower.h"
#include "IceTower.h"
#include "MissileTower.h"
#include "FireTower.h"
#include "PoisonTower.h"
#include "OverlapTester.h"
#include "Vector2D.h"
#include <string>
#include <sstream>

TowerCursor::TowerCursor(float x, float y, float width, float height, Tower_Type towerType, bool enabled) : PhysicalEntity (x, y, 1, 1, 0)
{
	m_towerType = towerType;
	m_fAlpha = 0.25f;
	m_fRed = 1;
	m_fGreen = 1;
	m_fBlue = 1;
    std::stringstream ss;
    ss << "$" << TowerCostMapper::getCostForTowerType(towerType);
    std::string costString = ss.str();
	m_costText = std::unique_ptr<Text>(new Text(costString, m_position->getX() - 0.6f, m_position->getY() - 0.7f, 0.30f, 0.37f, 1, 1, 1, 0.25f));
	m_displayBounds = std::unique_ptr<Rectangle>(new Rectangle(x, y, 0.50f, 0.50f));
	m_fDefaultX = x;
	m_fDefaultY = y;
	m_isEnabled = enabled;
	m_isFundsAvailableForPurchase = false;
	m_lockedWorldPlatform = nullptr;

	m_bounds->getLowerLeft().set(14.31f, y - height / 2);
	m_bounds->setWidth(width);
	m_bounds->setHeight(height);
}

void TowerCursor::setPosition(Vector2D &position)
{
	position.sub(3, 1);

	if (isOkayToMove())
	{
		m_position->set(position);
	}

	m_displayBounds->getLowerLeft().set(position.getX() - 0.25f, position.getY() - 0.25f);
}

void TowerCursor::resetPosition()
{
	m_position->set(m_fDefaultX, m_fDefaultY);
	m_displayBounds->getLowerLeft().set(m_position->getX(), m_position->getY());
}

void TowerCursor::acquirePositionLock(WorldPlatform *platform)
{
	m_position->set(platform->getPosition());
	m_lockedWorldPlatform = platform;
}

void TowerCursor::reset()
{
	m_lockedWorldPlatform = nullptr;
}

void TowerCursor::handleFundsChanged(int funds)
{
	if (m_isEnabled)
	{
		m_isFundsAvailableForPurchase = funds >= TowerCostMapper::getCostForTowerType(m_towerType);
		m_fAlpha = m_isFundsAvailableForPurchase ? 1 :0.25f;
		m_costText->setColor(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	}
}

bool TowerCursor::isLockAcquired()
{
	if(m_lockedWorldPlatform)
	{
		return true;
	}

	return false;
}

WorldPlatform * TowerCursor::getLockedWorldPlatform()
{
	return m_lockedWorldPlatform;
}

Tower * TowerCursor::createTower()
{
	switch(m_towerType)
	{
	case PROJECTILE_TYPE:
		return new ProjectileTower(m_position->getX(), m_position->getY());
	case ELECTRIC_TYPE:
		return new ElectricTower(m_position->getX(), m_position->getY());
	case LAZER_TYPE:
		return new LazerTower(m_position->getX(), m_position->getY());
	case ICE_TYPE:
		return new IceTower(m_position->getX(), m_position->getY());
	case MISSILE_TYPE:
		return new MissileTower(m_position->getX(), m_position->getY());
	case FIRE_TYPE:
		return new FireTower(m_position->getX(), m_position->getY());
	case POISON_TYPE:
	default:
		return new PoisonTower(m_position->getX(), m_position->getY());
	}
}

Tower_Type TowerCursor::getTowerType()
{
	return m_towerType;
}

Text & TowerCursor::getCostText()
{
	return *m_costText;
}

Rectangle & TowerCursor::getDisplayBounds()
{
	return *m_displayBounds;
}

float TowerCursor::getDefaultX()
{
	return m_fDefaultX;
}

float TowerCursor::getDefaultY()
{
	return m_fDefaultY;
}

Color TowerCursor::getColor()
{
	Color color = Color(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	return color;
}

bool TowerCursor::areFundsAvailableForPurchase()
{
	return m_isFundsAvailableForPurchase;
}

bool TowerCursor::isEnabled()
{
	return m_isEnabled;
}

// Private Methods

bool TowerCursor::isOkayToMove()
{
	if (!isLockAcquired())
	{
		return true;
	}

	if (!OverlapTester::doRectanglesOverlap(*m_displayBounds, m_lockedWorldPlatform->getBounds()))
	{
		reset();
		return true;
	}

	return false;
}