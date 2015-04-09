//
//  BackgroundElements.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/14/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "pch.h"
#include "BackgroundElements.h"
#include "GameObject.h"
#include "Asteroid.h"
#include "ShipModule.h"
#include "CoreShipModule.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "TowerCursor.h"
#include "OverlapTester.h"
#include "TowerCostMapper.h"
#include "Text.h"
#include "TowerOptionButton.h"
#include "GameListener.h"
#include "ResourceConstants.h"
#include "GameConstants.h"

BackgroundElements::BackgroundElements(int levelIndex)
{
	m_leftBackground = std::unique_ptr<GameObject>(new GameObject(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0));
	m_rightBackground = std::unique_ptr<GameObject>(new GameObject(SCREEN_WIDTH / 2 + SCREEN_WIDTH, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0));

	m_asteroids.push_back(std::unique_ptr<Asteroid>(Asteroid::generateRandomAsteroid()));

	initCoreShipForLevelIndex(levelIndex);
	initShipModulesForLevelIndex(levelIndex);

	m_towerSelectionMenuBounds = std::unique_ptr<Rectangle>(new Rectangle(14.31f, 0, 1.59f, SCREEN_HEIGHT));
	m_sellTowerButton = std::unique_ptr<TowerOptionButton>(new TowerOptionButton(14.40f, 0.50f, "SELL", 0, 1, 0, 1, 1, 1, 1, 1));
	m_upgradeTowerButton = std::unique_ptr<TowerOptionButton>(new TowerOptionButton(14.40f, 2.00f, "UPGRADE", 1, 0, 0, 1, 1, 1, 1, 1));

	m_backgroundScrollingSpeed = 0.85f;
	m_fTimeSinceLastAsteroidSpawned = 0;

	m_isRightBackgroundFirst = false;
	m_isUpgradeSellMenuShowing = false;

	m_towerCursors.push_back(std::unique_ptr<TowerCursor>(new TowerCursor(15.105f, 1.00625f, 1.59f, 1.43125f, Tower_Type::PROJECTILE_TYPE, true)));
	m_towerCursors.push_back(std::unique_ptr<TowerCursor>(new TowerCursor(15.105f, 2.4375f, 1.59f, 1.43125f, Tower_Type::ELECTRIC_TYPE, true)));
	m_towerCursors.push_back(std::unique_ptr<TowerCursor>(new TowerCursor(15.105f, 3.86875f, 1.59f, 1.43125f, Tower_Type::LAZER_TYPE, true)));
	m_towerCursors.push_back(std::unique_ptr<TowerCursor>(new TowerCursor(15.105f, 5.3f, 1.59f, 1.43125f, Tower_Type::ICE_TYPE, levelIndex >= 1)));
	m_towerCursors.push_back(std::unique_ptr<TowerCursor>(new TowerCursor(15.105f, 6.73125f, 1.59f, 1.43125f, Tower_Type::MISSILE_TYPE, levelIndex >= 2)));
	m_towerCursors.push_back(std::unique_ptr<TowerCursor>(new TowerCursor(15.105f, 8.1625f, 1.59f, 1.43125f, Tower_Type::FIRE_TYPE, levelIndex >= 3)));
	m_towerCursors.push_back(std::unique_ptr<TowerCursor>(new TowerCursor(15.105f, 9.59375f, 1.59f, 1.43125f, Tower_Type::POISON_TYPE, levelIndex >= 4)));

	m_selectedTowerCursor = nullptr;
}

void BackgroundElements::update(float deltaTime)
{
	if(m_isRightBackgroundFirst)
	{
		m_rightBackground->getPosition().sub(m_backgroundScrollingSpeed * deltaTime, 0);
		m_leftBackground->getPosition().set(m_rightBackground->getPosition().getX() + SCREEN_WIDTH, SCREEN_HEIGHT / 2);
	}
	else
	{
		m_leftBackground->getPosition().sub(m_backgroundScrollingSpeed * deltaTime, 0);
		m_rightBackground->getPosition().set(m_leftBackground->getPosition().getX() + SCREEN_WIDTH, SCREEN_HEIGHT / 2);
	}

	resetBackgroundIfNecessary();

	m_fTimeSinceLastAsteroidSpawned += deltaTime;

	if (m_fTimeSinceLastAsteroidSpawned > 45)
	{
		m_asteroids.clear();
	}

	if (m_fTimeSinceLastAsteroidSpawned > 10 && m_asteroids.size() < 6)
	{
		m_asteroids.push_back(std::unique_ptr<Asteroid>(Asteroid::generateRandomAsteroid()));
		m_fTimeSinceLastAsteroidSpawned = 0;
	}

	for (std::list<std::unique_ptr<Asteroid>>::iterator itr = m_asteroids.begin(); itr != m_asteroids.end(); )
	{
		(*itr)->update(deltaTime);

		if ((*itr)->remove())
		{
			itr = m_asteroids.erase(itr);
		}
		else
		{
			++itr;
		}
	}
}

void BackgroundElements::reset()
{
	resetSelectedTowerCursor();
	m_isUpgradeSellMenuShowing = false;
}

void BackgroundElements::handleFundsChanged(int funds, bool atLeastOnePlatformAvailable)
{
	for (std::vector<std::unique_ptr<TowerCursor>>::iterator itr = m_towerCursors.begin(); itr != m_towerCursors.end(); ++itr)
	{
		(*itr)->handleFundsChanged(atLeastOnePlatformAvailable ? funds : 0);
	}
}

int BackgroundElements::handleTouchDownInTowerSelectionMenu(Vector2D &touchPoint)
{
	for (std::vector<std::unique_ptr<TowerCursor>>::iterator itr = m_towerCursors.begin(); itr != m_towerCursors.end(); itr++)
	{
		if ((*itr)->areFundsAvailableForPurchase() && OverlapTester::isPointInRectangle(touchPoint, (*itr)->getBounds()))
		{
			m_selectedTowerCursor = itr->get();
            
            GameListener::getInstance()->playSound(SOUND_DRAG_TOWER);
            
			return TowerCostMapper::getCostForTowerType((*itr)->getTowerType());
		}
	}

	return -1;
}

bool BackgroundElements::isTouchInTowerSelectionMenuArea(Vector2D &touchPoint)
{
	return OverlapTester::isPointInRectangle(touchPoint, *m_towerSelectionMenuBounds);
}

void BackgroundElements::setSelectedTowerPosition(Vector2D &position)
{
	getSelectedTowerCursor().setPosition(position);
}

bool BackgroundElements::isTowerSelected()
{
	return m_selectedTowerCursor != nullptr;
}

TowerCursor & BackgroundElements::getSelectedTowerCursor()
{
	return *m_selectedTowerCursor;
}

GameObject & BackgroundElements::getLeftBackground()
{
	return *m_leftBackground;
}

GameObject & BackgroundElements::getRightBackground()
{
	return *m_rightBackground;
}

void BackgroundElements::setUpgradeSellMenuShowing(bool isUpgradeSellMenuShowing)
{
	m_isUpgradeSellMenuShowing = isUpgradeSellMenuShowing;
}

bool BackgroundElements::isUpgradeSellMenuShowing()
{
	return m_isUpgradeSellMenuShowing;
}

std::list<std::unique_ptr<Asteroid>> & BackgroundElements::getAsteroids()
{
	return m_asteroids;
}

std::vector<std::unique_ptr<TowerCursor>> & BackgroundElements::getTowerCursors()
{
	return m_towerCursors;
}

std::list<std::unique_ptr<ShipModule>> & BackgroundElements::getShipModules()
{
	return m_shipModules;
}

CoreShipModule & BackgroundElements::getCoreShipModule()
{
	return *m_coreShipModule;
}

TowerOptionButton & BackgroundElements::getSellTowerButton()
{
	return *m_sellTowerButton;
}

TowerOptionButton & BackgroundElements::getUpgradeTowerButton()
{
	return *m_upgradeTowerButton;
}

// Private Methods

void BackgroundElements::resetSelectedTowerCursor()
{
	if (isTowerSelected())
	{
		getSelectedTowerCursor().resetPosition();
		m_selectedTowerCursor = nullptr;
	}
}

void BackgroundElements::resetBackgroundIfNecessary()
{
	if (m_leftBackground->getPosition().getX() < (-SCREEN_WIDTH / 2))
	{
		m_leftBackground->getPosition().set(SCREEN_WIDTH / 2 + SCREEN_WIDTH, SCREEN_HEIGHT / 2);
		m_rightBackground->getPosition().set(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		m_isRightBackgroundFirst = true;
	}
	else if (m_rightBackground->getPosition().getX() < (-SCREEN_WIDTH / 2))
	{
		m_rightBackground->getPosition().set(SCREEN_WIDTH / 2 + SCREEN_WIDTH, SCREEN_HEIGHT / 2);
		m_leftBackground->getPosition().set(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		m_isRightBackgroundFirst = false;
	}
}

void BackgroundElements::initShipModulesForLevelIndex(int levelIndex)
{
	float x = 12.879f;
	float width = 2.862f;
	float height = 2.2f;

	switch (levelIndex)
	{
	case 0:
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 3.3f, width, height, Ship_Module_Type::CIVILIAN_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 5.5f, width, height, Ship_Module_Type::CIVILIAN_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 7.7f, width, height, Ship_Module_Type::CIVILIAN_TWO)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 9.9f, width, height, Ship_Module_Type::CIVILIAN_ONE)));
		break;
	case 1:
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 1.1f, width, height, Ship_Module_Type::CIVILIAN_TWO)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 5.5f, width, height, Ship_Module_Type::SHIP_AFFILIATION)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 7.7f, width, height, Ship_Module_Type::REGULAR_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 9.9f, width, height, Ship_Module_Type::CIVILIAN_ONE)));
		break;
	case 2:
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 1.1f, width, height, Ship_Module_Type::REGULAR_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 5.5f, width, height, Ship_Module_Type::REGULAR_TWO)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 7.7f, width, height, Ship_Module_Type::SHIP_AFFILIATION)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 9.9f, width, height, Ship_Module_Type::CIVILIAN_TWO)));
		break;
	case 3:
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 1.1f, width, height, Ship_Module_Type::REGULAR_THREE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 3.3f, width, height, Ship_Module_Type::REGULAR_TWO)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 7.7f, width, height, Ship_Module_Type::HANGAR_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 9.9f, width, height, Ship_Module_Type::REGULAR_ONE)));
		break;
	case 4:
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 1.1f, width, height, Ship_Module_Type::HANGAR_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 3.3f, width, height, Ship_Module_Type::HANGAR_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 5.5f, width, height, Ship_Module_Type::HANGAR_TWO)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 9.9f, width, height, Ship_Module_Type::HANGAR_TWO)));
		break;
	case 5:
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 3.3f, width, height, Ship_Module_Type::HANGAR_TWO)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 5.5f, width, height, Ship_Module_Type::FACTORY_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 7.7f, width, height, Ship_Module_Type::HANGAR_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 9.9f, width, height, Ship_Module_Type::REGULAR_TWO)));
		break;
	case 6:
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 1.1f, width, height, Ship_Module_Type::FACTORY_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 3.3f, width, height, Ship_Module_Type::FACTORY_TWO)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 5.5f, width, height, Ship_Module_Type::FACTORY_TWO)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 9.9f, width, height, Ship_Module_Type::FACTORY_ONE)));
		break;
	case 7:
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 1.1f, width, height, Ship_Module_Type::HANGAR_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 3.3f, width, height, Ship_Module_Type::REGULAR_THREE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 7.7f, width, height, Ship_Module_Type::FACTORY_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 9.9f, width, height, Ship_Module_Type::REGULAR_TWO)));
		break;
	case 8:
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 1.1f, width, height, Ship_Module_Type::ENGINE_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 5.5f, width, height, Ship_Module_Type::REGULAR_THREE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 7.7f, width, height, Ship_Module_Type::ENGINE_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 9.9f, width, height, Ship_Module_Type::REGULAR_ONE)));
		break;
	case 9:
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 1.1f, width, height, Ship_Module_Type::ENGINE_TWO)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 3.3f, width, height, Ship_Module_Type::ENGINE_ONE)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 7.7f, width, height, Ship_Module_Type::ENGINE_TWO)));
		m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(x, 9.9f, width, height, Ship_Module_Type::REGULAR_THREE)));
		break;
	}

	m_shipModules.push_back(std::unique_ptr<ShipModule>(new ShipModule(10.017f, 9.9f, width, height, Ship_Module_Type::SIDE_TOP)));
}

void BackgroundElements::initCoreShipForLevelIndex(int levelIndex)
{
	float x = 12.879f;
	float y;
	float width = 2.862f;
	float height = 2.2f;

	switch (levelIndex)
	{
	case 0:
		y = 1.1f;
		break;
	case 1:
		y = 3.3f;
		break;
	case 2:
		y = 3.3f;
		break;
	case 3:
		y = 5.5f;
		break;
	case 4:
		y = 7.7f;
		break;
	case 5:
		y = 1.1f;
		break;
	case 6:
		y = 7.7f;
		break;
	case 7:
		y = 5.5f;
		break;
	case 8:
		y = 3.3f;
		break;
	case 9:
		y = 5.5f;
		break;
	default:
		y = -1.1f;
		break;
	}

	m_coreShipModule = std::unique_ptr<CoreShipModule>(new CoreShipModule(x, y, width, height));	
}
