//
//  WorldPlatform.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/20/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__WorldPlatform__
#define __insectoiddefense__WorldPlatform__

#include "GameObject.h"
#include "WorldPlatformType.h"

class Tower;

class WorldPlatform : public GameObject
{
public:
	WorldPlatform(float x, float y, World_Platform_Type type);

	World_Platform_Type getType();
	
	void setTower(Tower *tower);
	
	Tower * getTower();
	
	bool holdsTower();

private:
	World_Platform_Type m_type;
	Tower *m_holdingTower;
};

#endif /* defined(__insectoiddefense__WorldPlatform__) */