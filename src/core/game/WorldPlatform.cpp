//
//  WorldPlatform.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/12/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "pch.h"
#include "WorldPlatform.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "UniqueIDUtil.h"
#include "Tower.h"

WorldPlatform::WorldPlatform(float x, float y, World_Platform_Type type) : GameObject (x, y, 1, 1, 0)
{
	m_type = type;
	m_holdingTower = nullptr;
}

World_Platform_Type WorldPlatform::getType()
{
	return m_type;
}

void WorldPlatform::setTower(Tower *tower)
{
	m_holdingTower = tower;
}

Tower * WorldPlatform::getTower()
{
	return m_holdingTower;
}

bool WorldPlatform::holdsTower()
{
	return m_holdingTower != nullptr;
}