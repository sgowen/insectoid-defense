//
//  TowerCostMapper.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__TowerCostMapper__
#define __insectoiddefense__TowerCostMapper__

#include "TowerType.h"

class TowerCostMapper
{
public:
	static int getCostForTowerType(Tower_Type type)
	{
		switch(type)
		{
		case PROJECTILE_TYPE:
			return 10;
		case ELECTRIC_TYPE:
			return 20;
		case LAZER_TYPE:
			return 30;
		case ICE_TYPE:
			return 40;
		case MISSILE_TYPE:
			return 55;
		case FIRE_TYPE:
			return 45;
		case POISON_TYPE:
		default:
			return 50;
		}
	}
};

#endif /* defined(__insectoiddefense__TowerCostMapper__) */