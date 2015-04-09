//
//  ProjectileParticle.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/3/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "ProjectileParticle.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "Color.h"
#include "macros.h"

#include <math.h>

ProjectileParticle::ProjectileParticle(float x, float y, float width, float height, float velocityConstant, float directionalAngle) : DynamicGameObject (x, y, width, height, directionalAngle)
{
	m_fAlpha = 1;
	m_fRed = 1;
	m_fGreen = 1;
	m_fBlue = 1;
	m_fStateTime = 0;
	m_remove = false;

	setMovementPhysics(directionalAngle, velocityConstant, -1);
}

void ProjectileParticle::update(float deltaTime)
{
	m_fStateTime += deltaTime;

	m_velocity->add(m_acceleration->getX() * deltaTime, m_acceleration->getY() * deltaTime);
	m_position->add(m_velocity->getX() * deltaTime, m_velocity->getY() * deltaTime);

	m_fAlpha -= deltaTime / 2;
	m_remove = m_fAlpha < 0;
}
	
Color ProjectileParticle::getColor()
{
	Color color = Color(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	return color;
}
	
float ProjectileParticle::getStateTime()
{
	return m_fStateTime;
}
	
bool ProjectileParticle::remove()
{
	return m_remove;
}

// Private Methods

void ProjectileParticle::setMovementPhysics(float directionalAngle, float initialVelocity, float friction)
{
    float radians = DEGREES_TO_RADIANS(directionalAngle);
	m_velocity->set(cosf(radians) * initialVelocity, sinf(radians) * initialVelocity);
	m_acceleration->set(cosf(radians) * friction, sinf(radians) * friction);
}