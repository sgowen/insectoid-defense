//
//  CreepBodyPart.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/3/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__CreepBodyPart__
#define __insectoiddefense__CreepBodyPart__

#include "DynamicGameObject.h"
#include "CreepBodyPartType.h"
#include "Color.h"

class CreepBodyPart : public DynamicGameObject
{
public:
	CreepBodyPart(float x, float y, float width, float height, float initialVelocity, float angle, float directionalAngle, float alpha, float red, float green, float blue, Creep_Body_Part_Type type);

	void update(float deltaTime);
	
	Creep_Body_Part_Type getType();
	
	Color getColor();
	
	bool remove();

private:
	Creep_Body_Part_Type m_type;
	float m_fAlpha;
	float m_fRed;
	float m_fGreen;
	float m_fBlue;
	bool m_remove;

	void setMovementPhysics(float directionalAngle, float initialVelocity, float friction);
};

#endif /* defined(__insectoiddefense__CreepBodyPart__) */