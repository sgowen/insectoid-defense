//
//  ToxicCloud.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/8/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "ToxicCloud.h"
#include "Circle.h"
#include "Creep.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "OverlapTester.h"

ToxicCloud::ToxicCloud(float x, float y, float initialRadius, float endRadius, float poisonTime, float poisonToCreepHealthRatio) : PhysicalEntity (x, y, initialRadius, initialRadius, 0)
{
	m_radius = std::unique_ptr<Circle>(new Circle(x, y, initialRadius));
	m_fAlpha = 0.4f;
	m_fRed = 0.38f;
	m_fGreen = 0.64f;
	m_fBlue = 0.15f;
	m_fEndRadius = endRadius;
	m_fPoisonTime = poisonTime;
	m_fPoisonToCreepHealthRatio = poisonToCreepHealthRatio;
	m_fTimeForPoisonDisburse = 0.1f;

	m_fRunningTimeForPoisonDisburse = 0;
	m_state = Toxic_Cloud_State::INITIAL_IMPACT;
	m_remove = false;
}

void ToxicCloud::update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fGreen += deltaTime;
	if (m_fGreen > 0.75f)
	{
		m_fGreen = 0.64f;
	}
	m_fBlue -= deltaTime;
	if (m_fBlue < 0.09f)
	{
		m_fBlue = 0.15f;
	}

	if (m_state == Toxic_Cloud_State::INITIAL_IMPACT)
	{
		m_radius->m_fRadius += deltaTime * 2;

		if (m_radius->m_fRadius > m_fEndRadius)
		{
			m_radius->m_fRadius = m_fEndRadius;
			m_state = Toxic_Cloud_State::AFTERMATH;
		}
	}
	else
	{
		m_fAlpha -= deltaTime * 0.5f;
	}

	if (m_fAlpha > 0)
	{
		if (m_fAlpha > 0.15f)
		{
			m_fRunningTimeForPoisonDisburse += deltaTime;

			if (m_fRunningTimeForPoisonDisburse > m_fTimeForPoisonDisburse)
			{
				m_fRunningTimeForPoisonDisburse -= m_fTimeForPoisonDisburse;

				for (std::vector<std::unique_ptr<Creep>>::iterator itr = creeps.begin(); itr != creeps.end(); itr++)
				{
					if (OverlapTester::overlapCircleRectangle(*m_radius, (*itr)->getBounds()))
					{
						(*itr)->poison(m_fPoisonTime, (int) ((*itr)->getMaxHealth() * m_fPoisonToCreepHealthRatio));
					}
				}
			}
		}
	}
	else
	{
		m_remove = true;
	}
}

Circle &ToxicCloud::getRadius()
{
	return *m_radius;
}

Color ToxicCloud::getColor()
{
    Color color = Color(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	return color;
}

bool ToxicCloud::remove()
{
	return m_remove;
}