//
//  TouchCursor.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/28/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "pch.h"
#include "TouchCursor.h"
#include "TowerState.h"
#include "OverlapTester.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "Tower.h"

TouchCursor::TouchCursor(float x, float y)
{
	m_displayBounds = std::unique_ptr<Rectangle>(new Rectangle(x, y, 0.50f, 0.50f));
	m_display = std::unique_ptr<Circle>(new Circle(x, y, 1));
	m_selectedTowerShadow = std::unique_ptr<Circle>(new Circle(x, y, 0.4f));
	m_selectedTower = nullptr;

	m_fRed = 1;
	m_fGreen = 1;
	m_fBlue = 1;
	m_fAlpha = 0.15f;
	m_fShadowRed = 0.25f;
	m_fShadowGreen = 0.25f;
	m_fShadowBlue = 0.25f;
	m_fShadowAlpha = 0.75f;

	m_iSelectedTowerStage = -1;
	m_isVisible = false;
}

void TouchCursor::setPosition(Vector2D &position)
{
	if (isOkayToMove())
	{
		m_display->getCenter().set(position);
	}

	m_displayBounds->getLowerLeft().set(position.getX() - 0.25f, position.getY() - 0.25f);
}

bool TouchCursor::canTowerBeUpgraded()
{
	if (isTowerLockAcquired())
	{
		return m_selectedTower->getState() == Tower_State::READY && m_selectedTower->getStage() < 2;
	}

	return false;
}

bool TouchCursor::canAffordUpgrade(int funds)
{
	if (isTowerLockAcquired())
	{
		return funds >= m_selectedTower->getUpgradeCost();
	}

	return false;
}

bool TouchCursor::shouldUpdateTowerInformation()
{
	if (isTowerLockAcquired() && m_iSelectedTowerStage != m_selectedTower->getStage())
	{
		m_iSelectedTowerStage = m_selectedTower->getStage();
		return true;
	}

	return false;
}

void TouchCursor::acquirePositionLock(Tower *tower)
{
	m_selectedTower = tower;
	m_iSelectedTowerStage= tower->getStage();
	m_display->getCenter().set(tower->getPosition());
	m_display->m_fRadius = tower->getAttackRadius().m_fRadius;
	m_selectedTowerShadow->getCenter().set(tower->getPosition());
}

bool TouchCursor::isTowerLockAcquired()
{
	return m_selectedTower != nullptr;
}

Tower * TouchCursor::getSelectedTower()
{
	return m_selectedTower;
}

Rectangle & TouchCursor::getDisplayBounds()
{
	return *m_displayBounds;
}

Circle & TouchCursor::getSelectedTowerShadow()
{
	return *m_selectedTowerShadow;
}

Circle & TouchCursor::getDisplayCircle()
{
	return *m_display;
}

Color TouchCursor::getColor()
{
	Color color = Color(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	return color;
}

Color TouchCursor::getShadowColor()
{
	Color color = Color(m_fShadowRed, m_fShadowGreen, m_fShadowBlue, m_fShadowAlpha);
	return color;
}

void TouchCursor::setVisibility(bool isVisible)
{
	m_isVisible = isVisible;

	if (!m_isVisible)
	{
		m_display->getCenter().set(-2, -2);
		m_display->m_fRadius = 0;
		m_selectedTower = nullptr;
		m_iSelectedTowerStage = -1;
	}
}

bool TouchCursor::isVisible()
{
	return m_isVisible;
}

// Private Methods

bool TouchCursor::isOkayToMove()
{
	if (!isTowerLockAcquired())
	{
		return true;
	}

	if (!OverlapTester::doRectanglesOverlap(*m_displayBounds, m_selectedTower->getBounds()))
	{
		m_selectedTower = nullptr;
		m_iSelectedTowerStage = -1;
		return true;
	}

	return false;
}