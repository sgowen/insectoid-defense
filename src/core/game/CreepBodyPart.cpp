//
//  CreepBodyPart.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/3/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "CreepBodyPart.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "macros.h"

#include <math.h>

CreepBodyPart::CreepBodyPart(float x, float y, float width, float height, float initialVelocity, float angle, float directionalAngle, float alpha, float red, float green, float blue, Creep_Body_Part_Type type) : PhysicalEntity (x, y, width, height, angle)
{
	m_type = type;
	m_fAlpha = alpha;
	m_fRed = red;
	m_fGreen = green;
	m_fBlue = blue;
	m_remove = false;
	
	setMovementPhysics(directionalAngle, initialVelocity, -1);
}

void CreepBodyPart::update(float deltaTime)
{
	m_velocity->add(m_acceleration->getX() * deltaTime, m_acceleration->getY() * deltaTime);
	m_position->add(m_velocity->getX() * deltaTime, m_velocity->getY() * deltaTime);

	m_fAngle += M_PI_2 * deltaTime;
	m_fAlpha -= deltaTime / 2;
	m_remove = m_fAlpha < 0;
}
	
Creep_Body_Part_Type CreepBodyPart::getType()
{
	return m_type;
}
	
Color CreepBodyPart::getColor()
{
	Color color = Color(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	return color;
}
	
bool CreepBodyPart::remove()
{
	return m_remove;
}

void CreepBodyPart::setMovementPhysics(float directionalAngle, float initialVelocity, float friction)
{
    float radians = DEGREES_TO_RADIANS(directionalAngle);
	m_velocity->set(cosf(radians) * initialVelocity, sinf(radians) * initialVelocity);
	m_acceleration->set(cosf(radians) * friction, sinf(radians) * friction);
}