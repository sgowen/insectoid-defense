//
//  TowerCursor.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/27/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__TowerCursor__
#define __insectoiddefense__TowerCursor__


#include "PhysicalEntity.h"
#include "TowerType.h"
#include "Color.h"

class Text;
class Rectangle;
class WorldPlatform;
class Vector2D;
class Tower;

class TowerCursor : public PhysicalEntity
{
public:
	TowerCursor(float x, float y, float width, float height, Tower_Type towerType, bool enabled);

	void setPosition(Vector2D &position);

	void resetPosition();

	void acquirePositionLock(WorldPlatform *platform);

	void reset();

	void handleFundsChanged(int funds);

	bool isLockAcquired();

	WorldPlatform * getLockedWorldPlatform();

	Tower * createTower();

	Tower_Type getTowerType();

	Text & getCostText();

	Rectangle & getDisplayBounds();

	float getDefaultX();

	float getDefaultY();

	Color getColor();

	bool areFundsAvailableForPurchase();

	bool isEnabled();

private:
	std::unique_ptr<Text> m_costText;
	std::unique_ptr<Rectangle> m_displayBounds;
	WorldPlatform *m_lockedWorldPlatform;
	Tower_Type m_towerType;
	float m_fAlpha;
	float m_fRed;
	float m_fGreen;
	float m_fBlue;
	float m_fDefaultX;
	float m_fDefaultY;
	bool m_isEnabled;
	bool m_isFundsAvailableForPurchase;

	bool isOkayToMove();
};

#endif /* defined(__insectoiddefense__TowerCursor__) */