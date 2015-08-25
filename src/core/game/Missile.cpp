//
//  Missile.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/7/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "Missile.h"
#include "Explosion.h"
#include "Vector2D.h"
#include "OverlapTester.h"
#include "Circle.h"
#include "Creep.h"
#include "Rectangle.h"
#include "FlagUtil.h"
#include "ScreenUtils.h"
#include "GameListener.h"
#include "ResourceConstants.h"
#include "macros.h"

#include <math.h>

Missile::Missile(float x, float y, float width, float height, float velocityConstant, float directionalAngle, int damage, Explosion_Type explosionType, Creep *target) : PhysicalEntity (x, y, width, height, directionalAngle)
{
	m_target = target;
	m_fVelocityConstant = velocityConstant;
	m_explosionType = explosionType;
	m_fBlastRadius = explosionType == Explosion_Type::BIG_DAMAGE ? 2.4f : 2;
	m_iDamage = damage;
	m_isCreepDead = false;

	m_fStateTime = 0;

	setVelocity(directionalAngle, velocityConstant);
}

void Missile::update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps, std::vector<std::unique_ptr<Explosion>> &explosions)
{
	m_fStateTime += deltaTime;
	m_position->add(m_velocity->getX() * deltaTime, m_velocity->getY() * deltaTime);
	updateBounds();
	m_remove = ScreenUtils::isVectorOffScreen(*m_position);

	if(m_isCreepDead)
	{
		if (checkCreepHitByProjectile(creeps, explosions))
		{
			return;
		}
		else
		{
			checkMissileTouchingExplosion(creeps, explosions);
		}
	}
	else
	{
		m_isCreepDead = m_target->isDead();

		if (!m_isCreepDead)
		{
			Vector2D creepPosition = m_target->getPosition().cpy();
			float directionalAngle = creepPosition.sub(m_position->getX(), m_position->getY()).angle();
			setVelocity(directionalAngle, m_fVelocityConstant);
			m_fAngle = directionalAngle;

			if (OverlapTester::doRectanglesOverlap(m_target->getBounds(), *m_bounds))
			{
				explode(creeps, explosions, m_target->getPosition(), m_explosionType);
				m_isCreepDead = m_target->isDead();
				return;
			}
		}
	}
}

bool Missile::remove()
{
	return m_remove;
}

// Private Methods

void Missile::explode(std::vector<std::unique_ptr<Creep>> &creeps, std::vector<std::unique_ptr<Explosion>> &explosions, Vector2D &position, Explosion_Type explosionType)
{
    GameListener::getInstance()->playSound(SOUND_EXPLOSION);

	bool creepHasDiedInExplosion = false;
	const Circle damageRadius = Circle(m_position->getX(), m_position->getY(), m_fBlastRadius / 4);

	for (std::vector<std::unique_ptr<Creep>>::iterator itr = creeps.begin(); itr != creeps.end(); itr++)
	{
		if (OverlapTester::overlapCircleRectangle(damageRadius, (*itr)->getBounds()))
		{
			(*itr)->takeDamage(m_iDamage, EXPLOSION);
			creepHasDiedInExplosion = FlagUtil::isFlagSet((*itr)->getState(), DEAD);
		}
	}

	explosions.push_back(std::unique_ptr<Explosion>(new Explosion(m_position->getX(), m_position->getY(), m_fBlastRadius, creepHasDiedInExplosion ? Explosion_Type::CREEP_DEATH : explosionType, m_iDamage / 100)));
	m_remove = true;
}

bool Missile::checkCreepHitByProjectile(std::vector<std::unique_ptr<Creep>> &creeps, std::vector<std::unique_ptr<Explosion>> &explosions)
{
	for (std::vector<std::unique_ptr<Creep>>::iterator itr = creeps.begin(); itr != creeps.end(); itr++)
	{
		if (OverlapTester::doRectanglesOverlap((*itr)->getBounds(), *m_bounds))
		{
			explode(creeps, explosions, (*itr)->getPosition(), m_explosionType);
			return true;
		}
	}

	return false;
}

void Missile::checkMissileTouchingExplosion(std::vector<std::unique_ptr<Creep>> &creeps, std::vector<std::unique_ptr<Explosion>> &explosions)
{
	for (std::vector<std::unique_ptr<Explosion>>::iterator itr = explosions.begin(); itr != explosions.end(); itr++)
	{
		if (OverlapTester::overlapCircleRectangle((*itr)->getDamageRadius(), *m_bounds))
		{
			explode(creeps, explosions, (*itr)->getPosition(), (*itr)->getType());
			return;
		}
	}
}

void Missile::setVelocity(float directionalAngle, float velocityConstant)
{
    float radians = DEGREES_TO_RADIANS(directionalAngle);
	m_velocity->set(cosf(radians) * velocityConstant, sinf(radians) * velocityConstant);
}