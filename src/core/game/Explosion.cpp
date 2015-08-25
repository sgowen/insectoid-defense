//
//  Explosion.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/7/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "Explosion.h"
#include "Vector2D.h"
#include "OverlapTester.h"
#include "Circle.h"
#include "Creep.h"
#include "Rectangle.h"

Explosion::Explosion(float x, float y, float blastRadius, Explosion_Type type, int damageRate) : PhysicalEntity(x, y, blastRadius, blastRadius, 0)
{
	m_damageRadius = std::unique_ptr<Circle>(new Circle(x, x, blastRadius / 4));
	m_type = type;
	m_fExplosionTime = type == Explosion_Type::CREEP_DEATH ? 1.2f : type == Explosion_Type::BIG_DAMAGE ? 1.02f : 0.85f;
	m_fDamageTime = 0.1f;
	m_iDamageRate = damageRate;
	m_fStateTime = 0;
	m_fFireTime = 0;
	m_iDamage = 0;
}

void Explosion::update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fStateTime += deltaTime;
	m_fFireTime += deltaTime;

	m_remove = m_fStateTime > m_fExplosionTime;

	if (!m_remove && m_fFireTime > m_fDamageTime)
	{
		m_iDamage = 0;

		while (m_fFireTime > m_fDamageTime)
		{
			m_fFireTime -= m_fDamageTime;
			m_iDamage += m_iDamageRate;
		}

		for (std::vector<std::unique_ptr<Creep>>::iterator itr = creeps.begin(); itr != creeps.end(); itr++)
		{
			if (OverlapTester::overlapCircleRectangle(*m_damageRadius, (*itr)->getBounds()))
			{
				(*itr)->takeDamage(m_iDamage, FIRE);
			}
		}
	}
}

Circle & Explosion::getDamageRadius()
{
	return *m_damageRadius;
}

Explosion_Type Explosion::getType()
{
	return m_type;
}

bool Explosion::remove()
{
	return m_remove;
}