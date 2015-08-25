//
//  IceBlast.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/6/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "IceBlast.h"
#include "Vector2D.h"
#include "Creep.h"
#include "OverlapTester.h"
#include "Circle.h"
#include "Rectangle.h"

IceBlast::IceBlast(float x, float y) : PhysicalEntity (x, y, 3, 3, 0)
{
	m_blastRadius = std::unique_ptr<Circle>(new Circle(x, y, 1.5f));
	m_fBlastDisplayRadius = 3;
	m_fStateTime = 0;
	m_fFrozenTime = 2;
	m_iBlastDamage = 300;
	m_iFreezeChance = 4;
	m_isBlasting = false;
	m_isDamageDealt = false;
}

void IceBlast::update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fStateTime += deltaTime;

	if (m_isBlasting && m_fStateTime > 0.36f)
	{
		if (m_isDamageDealt)
		{
			if (m_fStateTime > 0.72f)
			{
				m_fStateTime = 0;
				m_isBlasting = false;
				m_isDamageDealt = false;
			}
		}
		else
		{
			for (std::vector<std::unique_ptr<Creep>>::iterator itr = creeps.begin(); itr != creeps.end(); itr++)
			{
				if (OverlapTester::isPointInCircle((*itr)->getPosition(), *m_blastRadius))
				{
					(*itr)->freeze(m_fFrozenTime, m_iFreezeChance);
					(*itr)->takeDamage(m_iBlastDamage, ICE);
				}
			}

			m_isDamageDealt = true;
		}
	}
}

void IceBlast::performUpgrade()
{
	m_blastRadius->m_fRadius += 0.25f;
	m_fBlastDisplayRadius += 0.50f;
	m_fFrozenTime += 0.5f;
	m_iBlastDamage *= 2;
	m_iFreezeChance--;
}

void IceBlast::blast()
{
	m_isBlasting = true;
}

bool IceBlast::isBlasting()
{
	return m_isBlasting;
}

int IceBlast::getIceBlastID()
{
	return m_iIceBlastID;
}

float IceBlast::getWidth()
{
	return m_fBlastDisplayRadius;
}

float IceBlast::getHeight()
{
	return m_fBlastDisplayRadius;
}