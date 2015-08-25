//
//  ScreenUtils.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/25/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__ScreenUtils__
#define __insectoiddefense__ScreenUtils__


#include "Rectangle.h"
#include "OverlapTester.h"
#include "GameConstants.h"

class ScreenUtils
{
public:
	static Rectangle * getScreenBounds()
	{
		static Rectangle * SCREEN_BOUNDS = new Rectangle(-3, -3, GAME_WIDTH + 3, GAME_HEIGHT + 3);
		return SCREEN_BOUNDS;
	}

	static bool isVectorOffScreen(Vector2D &position)
	{
		return !OverlapTester::isPointInRectangle(position, *getScreenBounds());
	}
};

#endif /* defined(__insectoiddefense__ScreenUtils__) */