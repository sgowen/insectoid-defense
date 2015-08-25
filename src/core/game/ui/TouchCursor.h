//
//  TouchCursor.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/28/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__TouchCursor__
#define __insectoiddefense__TouchCursor__


#include "Color.h"

#include <memory>

class Vector2D;
class Rectangle;
class Circle;
class Tower;

class TouchCursor
{
public:
	TouchCursor(float x, float y);

	void setPosition(Vector2D &position);

	bool canTowerBeUpgraded();

	bool canAffordUpgrade(int funds);

	bool shouldUpdateTowerInformation();

	void acquirePositionLock(Tower *tower);

	bool isTowerLockAcquired();

	Tower * getSelectedTower();

	Rectangle & getDisplayBounds();

	Circle & getSelectedTowerShadow();

	Circle & getDisplayCircle();

	Color getColor();
	
	Color getShadowColor();

	void setVisibility(bool isVisible);

	bool isVisible();

private:
	std::unique_ptr<Rectangle> m_displayBounds;
	std::unique_ptr<Circle> m_display;
	std::unique_ptr<Circle> m_selectedTowerShadow;
	Tower *m_selectedTower;
	float m_fRed;
	float m_fGreen;
	float m_fBlue;
	float m_fAlpha;
	float m_fShadowRed;
	float m_fShadowGreen;
	float m_fShadowBlue;
	float m_fShadowAlpha;

	int m_iSelectedTowerStage;
	bool m_isVisible;

	bool isOkayToMove();
};

#endif /* defined(__insectoiddefense__TouchCursor__) */