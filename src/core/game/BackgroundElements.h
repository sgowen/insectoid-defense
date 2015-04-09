//
//  BackgroundElements.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/14/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__BackgroundElements__
#define __insectoiddefense__BackgroundElements__

#include <list>
#include <memory>
#include <vector>

class Vector2D;
class CoreShipModule;
class ShipModule;
class Asteroid;
class GameObject;
class TowerCursor;
class Rectangle;
class TowerOptionButton;

class BackgroundElements
{
public:
	BackgroundElements(int levelIndex);
	void update(float deltaTime);
	void reset();
	void handleFundsChanged(int funds, bool atLeastOnePlatformAvailable);
	int handleTouchDownInTowerSelectionMenu(Vector2D &touchPoint);
	bool isTouchInTowerSelectionMenuArea(Vector2D &touchPoint);
	void setSelectedTowerPosition(Vector2D &position);
	bool isTowerSelected();
	TowerCursor &getSelectedTowerCursor();
	GameObject & getLeftBackground();
	GameObject & getRightBackground();
	void setUpgradeSellMenuShowing(bool isUpgradeSellMenuShowing);
	bool isUpgradeSellMenuShowing();
	std::list<std::unique_ptr<Asteroid>> & getAsteroids();
	std::vector<std::unique_ptr<TowerCursor>> & getTowerCursors();
	std::list<std::unique_ptr<ShipModule>> & getShipModules();
	CoreShipModule & getCoreShipModule();
	TowerOptionButton & getSellTowerButton();
	TowerOptionButton & getUpgradeTowerButton();

private:
	std::unique_ptr<GameObject> m_leftBackground;
	std::unique_ptr<GameObject> m_rightBackground;
	std::list<std::unique_ptr<Asteroid>> m_asteroids;
	float m_fTimeSinceLastAsteroidSpawned;
	std::list<std::unique_ptr<ShipModule>> m_shipModules;
	std::unique_ptr<CoreShipModule> m_coreShipModule;
	std::vector<std::unique_ptr<TowerCursor>> m_towerCursors;
	std::unique_ptr<Rectangle> m_towerSelectionMenuBounds;
	std::unique_ptr<TowerOptionButton> m_sellTowerButton;
	std::unique_ptr<TowerOptionButton> m_upgradeTowerButton;
	TowerCursor *m_selectedTowerCursor;
	float m_backgroundScrollingSpeed;
	bool m_isRightBackgroundFirst;
	bool m_isUpgradeSellMenuShowing;

	void resetSelectedTowerCursor();
	void resetBackgroundIfNecessary();
	void initShipModulesForLevelIndex(int levelIndex);
	void initCoreShipForLevelIndex(int levelIndex);
};

#endif /* defined(__insectoiddefense__BackgroundElements__) */