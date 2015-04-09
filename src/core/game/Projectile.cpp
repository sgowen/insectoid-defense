//
//  Projectile.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "Projectile.h"
#include "ScreenUtils.h"
#include "DamageType.h"
#include "FlagUtil.h"
#include "Creep.h"
#include "Vector2D.h"
#include "ProjectileParticle.h"
#include "Assets.h"
#include "World.h"
#include "GameListener.h"
#include "ResourceConstants.h"
#include "macros.h"

#include <stdlib.h>
#include <math.h>

Projectile::Projectile(float x, float y, float width, float height, float velocityConstant, float directionalAngle, int damage, bool isSticky) : DynamicGameObject (x, y, width, height, directionalAngle)
{
	m_fAlpha = 1;
	m_fRed = 1;
	m_fGreen = 1;
	m_fBlue = 1;
	m_iDamage = damage;
	m_isSticky = isSticky;

	setState(Projectile_State::DEFAULT);
	m_iZapDamage = 0;
	m_remove = false;

	setVelocity(directionalAngle, velocityConstant);
}

void Projectile::update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fStateTime += deltaTime;

	if (m_projectileState == Projectile_State::DEFAULT)
	{
		m_position->add(m_velocity->getX() * deltaTime, m_velocity->getY() * deltaTime);
		updateBounds();
		m_remove = ScreenUtils::isVectorOffScreen(*m_position);
		checkCreepHitByProjectile(creeps);
	}
	else if(m_stuckCreep)
	{
		m_position->set(m_stuckCreep->getPosition());
		m_position->add(m_stickLocationRelativeToCreep->getX(), m_stickLocationRelativeToCreep->getY());
		updateBounds();
		m_remove = m_stuckCreep->isDead();

		if (m_projectileState == Projectile_State::GLOWING)
		{
			m_fAlpha += deltaTime * 2;

			if (m_fAlpha > 1)
			{
				m_fAlpha = 1;

				float particleWidth = getWidth() / 2;
				float particleHeight = getHeight() / 2;
				float particleSpeed = 4.0f;
				float particleDirection = rand() % 89;

				World::getInstance()->getProjectileParticles().push_back(std::unique_ptr<ProjectileParticle>(new ProjectileParticle(m_position->getX(), m_position->getY(), particleWidth, particleHeight, particleSpeed, particleDirection)));
				World::getInstance()->getProjectileParticles().push_back(std::unique_ptr<ProjectileParticle>(new ProjectileParticle(m_position->getX(), m_position->getY(), particleWidth, particleHeight, particleSpeed, particleDirection + M_PI_2)));
				World::getInstance()->getProjectileParticles().push_back(std::unique_ptr<ProjectileParticle>(new ProjectileParticle(m_position->getX(), m_position->getY(), particleWidth, particleHeight, particleSpeed, particleDirection + M_PI)));
				World::getInstance()->getProjectileParticles().push_back(std::unique_ptr<ProjectileParticle>(new ProjectileParticle(m_position->getX(), m_position->getY(), particleWidth, particleHeight, particleSpeed, particleDirection + M_PI + M_PI_2)));

				m_stuckCreep->takeZapDamage(m_iZapDamage);
				m_remove = true;
                
                GameListener::getInstance()->playSound(SOUND_PLASMA_BANG);
			}
		}
	}
	else
	{
		m_remove = true;
	}
}

Projectile_State Projectile::getProjectileState()
{
	return m_projectileState;
}

void Projectile::zap(int zapDamage)
{
	if (m_projectileState != Projectile_State::GLOWING)
	{
		setState(Projectile_State::GLOWING);
		m_iZapDamage = zapDamage;

		m_fAlpha = 0;
	}
}

Color Projectile::getColor()
{
	Color color = Color(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	return color;
}

float Projectile::getStateTime()
{
	return m_fStateTime;
}

bool Projectile::remove()
{
	return m_remove;
}

void Projectile::setVelocity(float directionalAngle, float velocityConstant)
{
    float radians = DEGREES_TO_RADIANS(directionalAngle);
	m_velocity->set(cosf(radians) * velocityConstant, sinf(radians) * velocityConstant);
}

void Projectile::setState(Projectile_State projectileState)
{
	m_projectileState = projectileState;
	m_fStateTime = 0;
}

void Projectile::checkCreepHitByProjectile(std::vector<std::unique_ptr<Creep>> &creeps)
{
	for (std::vector<std::unique_ptr<Creep>>::iterator itr = creeps.begin(); itr != creeps.end(); itr++)
	{
		if (OverlapTester::isPointInRectangle(*m_position, (*itr)->getBounds()))
		{
			(*itr)->takeDamage(m_iDamage, Damage_Type::REGULAR);

			bool isCreepDead = FlagUtil::isFlagSet((*itr)->getState(), DEAD) || FlagUtil::isFlagSet((*itr)->getState(), DEPLOYING) || FlagUtil::isFlagSet((*itr)->getState(), GOAL_REACHED);

			if (m_isSticky && !isCreepDead && (*itr)->canStick())
			{
				setState(Projectile_State::STUCK);
				m_stuckCreep = itr->get();
				m_stickLocationRelativeToCreep = std::unique_ptr<Vector2D>(new Vector2D(m_position->getX() - m_stuckCreep->getPosition().getX(), m_position->getY() - m_stuckCreep->getPosition().getY()));
			}
			else
			{
				m_remove = true;
			}

			return;
		}
	}
}