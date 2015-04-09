//
//  AcidDrop.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/8/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "AcidDrop.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "ScreenUtils.h"
#include "World.h"
#include "ToxicCloud.h"
#include "Circle.h"
#include "GameListener.h"
#include "ResourceConstants.h"
#include "macros.h"

#include <math.h>

AcidDrop::AcidDrop(float x, float y, float width, float height, float velocityConstant, float directionalAngle, Rectangle *destinationBounds, float poisonTime, float poisonToCreepHealthRatio) : DynamicGameObject(x, y, width, height, directionalAngle)
{
	m_destinationBounds = std::unique_ptr<Rectangle>(destinationBounds);
	m_fPoisonTime = poisonTime;
	m_fPoisonToCreepHealthRatio = poisonToCreepHealthRatio;
	m_remove = false;

	setVelocity(directionalAngle, velocityConstant);
}

void AcidDrop::update(float deltaTime)
{
	m_fStateTime += deltaTime;

	m_position->add(m_velocity->getX() * deltaTime, m_velocity->getY() * deltaTime);
	updateBounds();
	m_remove = ScreenUtils::isVectorOffScreen(*m_position);

	if (OverlapTester::isPointInRectangle(*m_position, *m_destinationBounds))
	{
		World::getInstance()->getToxicClouds().push_back(std::unique_ptr<ToxicCloud>(new ToxicCloud(m_destinationBounds->getLowerLeft().getX() + m_destinationBounds->getWidth() / 2, m_destinationBounds->getLowerLeft().getY() + m_destinationBounds->getHeight() / 2, m_fWidth / 2, m_fWidth * 3, m_fPoisonTime, m_fPoisonToCreepHealthRatio)));
        
        GameListener::getInstance()->playSound(SOUND_TOXIC_CLOUD);
        
		m_remove = true;
	}
}

float AcidDrop::getStateTime()
{
	return m_fStateTime;
}

bool AcidDrop::remove()
{
	return m_remove;
}

// Private Methods

void AcidDrop::setVelocity(float directionalAngle, float velocityConstant)
{
    float radians = DEGREES_TO_RADIANS(directionalAngle);
	m_velocity->set(cosf(radians) * velocityConstant, sinf(radians) * velocityConstant);
}