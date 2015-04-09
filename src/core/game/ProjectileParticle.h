//
//  ProjectileParticle.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/3/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__ProjectileParticle__
#define __insectoiddefense__ProjectileParticle__

#include "DynamicGameObject.h"
#include "Color.h"

class ProjectileParticle : public DynamicGameObject
{
public:
	ProjectileParticle(float x, float y, float width, float height, float velocityConstant, float directionalAngle);

	void update(float deltaTime);

	Color getColor();

	float getStateTime();

	bool remove();

private:
	float m_fAlpha;
	float m_fRed;
	float m_fGreen;
	float m_fBlue;
	float m_fStateTime;
	bool m_remove;

	void setMovementPhysics(float directionalAngle, float initialVelocity, float friction);
};

#endif /* defined(__insectoiddefense__ProjectileParticle__) */