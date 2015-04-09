//
//  LazerBeam.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/5/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "pch.h"
#include "LazerBeam.h"
#include "Vector2D.h"
#include "OverlapTester.h"
#include "Rectangle.h"
#include "Creep.h"
#include "Line.h"
#include "UniqueIDUtil.h"

LazerBeam::LazerBeam(float x, float y, float alpha, int damageRate)
{
	m_path = std::unique_ptr<Line>(new Line(x, y, x, y));
	m_fAlpha = alpha;
	m_fRed = 0;
	m_fGreen = 0;
	m_fBlue = 0;
	m_fDamageTime = 0.1f;
	m_fFireTime = 0;
	m_iDamageRate = damageRate;
	m_iDamage = 0;
	m_iLazerBeamID = UniqueIDUtil::getUniqueLazerBeamID();
}

void LazerBeam::update(float red, float green, float blue)
{
	m_fRed = red;
	m_fGreen = green;
	m_fBlue = blue;
}

void LazerBeam::checkCreepsHitByLazerBeam(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fFireTime += deltaTime;

	if (m_fFireTime > m_fDamageTime)
	{
		m_iDamage = 0;

		while (m_fFireTime > m_fDamageTime)
		{
			m_fFireTime -= m_fDamageTime;
			m_iDamage += m_iDamageRate;
		}

		for (std::vector<std::unique_ptr<Creep>>::iterator itr = creeps.begin(); itr != creeps.end(); itr++)
		{
			if (OverlapTester::doLineAndRectangleOverlap(getPath(), (*itr)->getBounds()))
			{
				(*itr)->takeDamage(m_iDamage, REGULAR);
			}
		}
	}
}

void LazerBeam::fire(float endX, float endY)
{
	getPath().getEnd().set(endX, endY);
	m_isFiring = true;
}

void LazerBeam::reset()
{
	m_fFireTime = 0;
	getPath().getEnd().set(getPath().getOrigin());
	m_fRed = 0;
	m_fGreen = 0;
	m_fBlue = 0;
	m_isFiring = false;
}

void LazerBeam::increaseDamageRate()
{
	m_iDamageRate += 20;
}

Line & LazerBeam::getPath()
{
	return *m_path;
}

Color LazerBeam::getColor()
{
	Color color = Color(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	return color;
}

bool LazerBeam::isFiring()
{
	return m_isFiring;
}

int LazerBeam::getLazerBeamID()
{
	return m_iLazerBeamID;
}