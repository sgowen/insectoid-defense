//
//  AcidDrop.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/8/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__AcidDrop__
#define __insectoiddefense__AcidDrop__


#include "PhysicalEntity.h"

class Rectangle;

class AcidDrop : public PhysicalEntity
{
public:
	AcidDrop(float x, float y, float width, float height, float velocityConstant, float directionalAngle, Rectangle *destinationBounds, float poisonTime, float poisonToCreepHealthRatio);

	void update(float deltaTime);
	
	bool remove();

private:
	std::unique_ptr<Rectangle> m_destinationBounds;
	float m_fPoisonTime;
	float m_fPoisonToCreepHealthRatio;
	bool m_remove;

	void setVelocity(float directionalAngle, float velocityConstant);
};

#endif /* defined(__insectoiddefense__AcidDrop__) */