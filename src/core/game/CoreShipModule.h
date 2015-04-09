//
//  CoreShipModule.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/14/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__CoreShipModule__
#define __insectoiddefense__CoreShipModule__

#include "GameObject.h"
#include "CoreShipModuleState.h"

class CoreShipModule : public GameObject
{
public: 
	CoreShipModule(float x, float y, float width, float height);
	void update(float deltaTime);
	void takeDamage();
	bool isAtMaxHealth();
	bool isGameOver();
	Core_Ship_Module_State getState();
	float getStateTime();
	int getMaxHealth();
	int getRemainingHealth();
	
private:
	void setState(Core_Ship_Module_State state);

	Core_Ship_Module_State m_state;
	float m_stateTime;
	int m_maxHealth;
	int m_health;
};

#endif /* defined(__insectoiddefense__CoreShipModule__) */