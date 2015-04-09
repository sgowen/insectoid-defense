//
//  Asteroid.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 8/18/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__Asteroid__
#define __insectoiddefense__Asteroid__

#include "DynamicGameObject.h"
#include "AsteroidType.h"

class Asteroid : public DynamicGameObject
{
public:
	static Asteroid * generateRandomAsteroid();
    
	Asteroid(float x, float y, float width, float height, float velocityConstant, float directionalAngle, float spinDegreesPerSecond, Asteroid_Type type);

	void update(float &deltaTime);

	Asteroid_Type getAsteroidType();

	bool remove();

private:
	Asteroid_Type m_type;
	float m_spinDegreesPerSecond;
	
	bool m_hasEnteredWorld;
	bool m_remove;
};

#endif /* defined(__insectoiddefense__Asteroid__) */