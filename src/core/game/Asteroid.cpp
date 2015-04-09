//
//  Asteroid.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 8/18/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "pch.h"
#include "Asteroid.h"
#include "ScreenUtils.h"
#include "World.h"
#include "Vector2D.h"
#include "macros.h"

#include <ctime>
#include <stdlib.h>
#include <math.h>

Asteroid * Asteroid::generateRandomAsteroid()
{
	srand((unsigned)time(0));

	float size = ((float)(rand() % 101)) / 100.0f + ((float)(rand() % 101)) / 100.0f;
	float speed = ((float)(rand() % 101)) / 100.0f + 0.5f;
	float spinDegreesPerSecond = (rand() % 166) + 15.0f;

	float x = -2;
	float y = -2;
	int random_integer = rand() % 3;
	switch (random_integer)
	{
	case 0:
		x = -2;
		y = (rand() % (int) SCREEN_HEIGHT) - 3;
		break;
	case 1:
		x = (rand() % (int) SCREEN_WIDTH) + 1;
		y = (rand() % 2) == 0 ? SCREEN_HEIGHT + 2 : -2;
		break;
	case 2:
		x = SCREEN_WIDTH + 2;
		y = (rand() % (int) SCREEN_HEIGHT) - 2;
	}

	Vector2D asteroidPosition(x, y);
	Vector2D destinationPosition((rand() % (int) SCREEN_WIDTH) + 1, (rand() % (int) SCREEN_HEIGHT) + 1);
	float directionalAngle = destinationPosition.sub(asteroidPosition.getX(), asteroidPosition.getY()).angle();

	int random_asteroid = (rand() % 2);

	return new Asteroid(x, y, size, size, speed, directionalAngle, spinDegreesPerSecond, random_asteroid == 0 ? Asteroid_Type::GRAY : Asteroid_Type::BROWN);
}

Asteroid::Asteroid(float x, float y, float width, float height, float velocityConstant, float directionalAngle, float spinDegreesPerSecond, Asteroid_Type type) : DynamicGameObject (x, y, width, height, 0)
{
	m_spinDegreesPerSecond = spinDegreesPerSecond;

	float radians = DEGREES_TO_RADIANS(directionalAngle);
	m_velocity->set(cosf(radians) * velocityConstant, sinf(radians) * velocityConstant);

	m_hasEnteredWorld = false;
	m_remove = false;

	m_type = type;
}

void Asteroid::update(float &deltaTime)
{
	m_fAngle += m_spinDegreesPerSecond * deltaTime;

	m_position->add(m_velocity->getX() * deltaTime, m_velocity->getY() * deltaTime);
	updateBounds();

	if (m_hasEnteredWorld)
	{
		m_remove = ScreenUtils::isVectorOffScreen(*m_position);
	}
	else if (World::isVectorInWorld(*m_position))
	{
		m_hasEnteredWorld = true;
	}
}

Asteroid_Type Asteroid::getAsteroidType()
{
	return m_type;
}

bool Asteroid::remove()
{
	return m_remove;
}