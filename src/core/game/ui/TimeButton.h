//
//  TimeButton.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 9/13/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__TimeButton__
#define __insectoiddefense__TimeButton__

#include "PhysicalEntity.h"

class TimeButton : public PhysicalEntity
{
public:
	TimeButton(float x, float y, float width, float height);

	bool isTouching(Vector2D &touchPoint);

	bool handleTouch(Vector2D &touchPoint);

	int getSpeedScalar();

	void setSpeedScalar(int speedScalar);

private:
	std::unique_ptr<Rectangle> m_speedBounds;
	int m_speedScalar;
};

#endif /* defined(__insectoiddefense__TimeButton__) */