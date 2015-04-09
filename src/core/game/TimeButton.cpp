//
//  TimeButton.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 9/13/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "pch.h"
#include "TimeButton.h"
#include "OverlapTester.h"
#include "Rectangle.h"
#include "Vector2D.h"

TimeButton::TimeButton(float x, float y, float width, float height) : GameObject(x, y, width, height, 0)
{
	m_speedBounds = std::unique_ptr<Rectangle>(new Rectangle(0, (m_bounds->getLowerLeft()).getY(), 0.795f, m_bounds->getHeight()));
	m_speedScalar = 1;
}

bool TimeButton::isTouching(Vector2D &touchPoint)
{
	return OverlapTester::isPointInRectangle(touchPoint, *m_bounds);
}

bool TimeButton::handleTouch(Vector2D &touchPoint)
{
	if (OverlapTester::isPointInRectangle(touchPoint, *m_speedBounds))
	{
		m_speedScalar++;
		if (m_speedScalar > 3)
		{
			m_speedScalar = 1;
		}
		
		return false;
	}
	
	return true;
}

int TimeButton::getSpeedScalar()
{
	return m_speedScalar;
}

void TimeButton::setSpeedScalar(int speedScalar)
{
	m_speedScalar = speedScalar;
}