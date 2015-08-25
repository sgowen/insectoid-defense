//
//  Tower.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__Tower__
#define __insectoiddefense__Tower__

#include "PhysicalEntity.h"
#include "TowerState.h"
#include "TowerType.h"
#include "Color.h"

#include <memory>
#include <vector>

class Creep;
class Circle;

class Tower : public PhysicalEntity
{
public:
	static Color getUpgradeCursorColor()
	{
		static Color color = Color(1, 1, 1, 0.25f);
		return color;
	}

	virtual Tower_Type getTowerType() = 0;

	Tower(Tower_Type towerType, float x, float y, float width, float height, float radius, float upgradeTime, int upgradeCost);

	void update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

	void upgrade();

	int getUpgradeCursorArcDegrees();

	Circle & getUpgradeCursor();

	Circle & getAttackRadius();

	Tower_State getState();

	int getUpgradeCost();

	int getSellAmount();

	int getStage();

	virtual void onRemove();

	int getID();

protected:
	std::unique_ptr<Circle> m_attackRadius;
	int m_iUpgradeCost;
	int m_iSellAmount;

	virtual void updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps) = 0;

	virtual void fireAtCreep(Creep *creep) = 0;

	virtual void performUpgrade() = 0;

	virtual void checkCreepInRadius(std::vector<std::unique_ptr<Creep>> &creeps);

	virtual void updatePhysics(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

private:
	std::unique_ptr<Circle> m_upgradeCursor;
	float m_fUpgradeTime;
	float m_fUpgradeProgressTime;
	Tower_State m_state;
	int m_iStage;
	int m_iTowerID;
};

#endif /* defined(__insectoiddefense__Tower__) */