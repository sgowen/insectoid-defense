//
//  ShipModule.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/14/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__ShipModule__
#define __insectoiddefense__ShipModule__

#include "DynamicGameObject.h"
#include "ShipModuleType.h"

class ShipModule : public DynamicGameObject
{
public: 
	ShipModule(float x, float y, float width, float height, Ship_Module_Type type);
	Ship_Module_Type getType();

private:
	Ship_Module_Type m_type;
};

#endif /* defined(__insectoiddefense__ShipModule__) */