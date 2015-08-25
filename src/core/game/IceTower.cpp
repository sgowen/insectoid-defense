//
//  IceTower.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "IceTower.h"
#include "IceBlast.h"
#include "Circle.h"
#include "Creep.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "World.h"
#include "GameListener.h"
#include "ResourceConstants.h"

IceTower::IceTower(float x, float y) : Tower(Tower_Type::ICE_TYPE, x, y, 1, 1, 1.5f, 7.0f, 40)
{
	m_iceBlast = new IceBlast(x, y);
	m_fStateTime = 0;
	m_fCooldownTime = 2.20f;

	World::getInstance()->getIceBlasts().push_back(std::unique_ptr<IceBlast>(m_iceBlast));
}

Tower_Type IceTower::getTowerType()
{
	return Tower_Type::ICE_TYPE;
}

void IceTower::onRemove()
{
	for (std::vector<std::unique_ptr<IceBlast>>::iterator itr = World::getInstance()->getIceBlasts().begin(); itr != World::getInstance()->getIceBlasts().end(); itr++)
	{
		if(m_iceBlast->getIceBlastID() == (*itr)->getIceBlastID())
		{
			itr = World::getInstance()->getIceBlasts().erase(itr);
			return;
		}
	}
}

// Virtual Methods

void IceTower::updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	m_fStateTime += deltaTime;

	checkCreepInRadius(creeps);
}

void IceTower::fireAtCreep(Creep *creep)
{
	if (!m_iceBlast->isBlasting() && m_fStateTime > m_fCooldownTime)
	{
		m_iceBlast->blast();
        
        GameListener::getInstance()->playSound(SOUND_ICE_BLAST);
	}
}

void IceTower::performUpgrade()
{
	m_fStateTime = 0;
	m_iUpgradeCost += 40;
	m_fCooldownTime -= 0.20f;
	m_iceBlast->performUpgrade();
}

void IceTower::updatePhysics(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps)
{
	if (m_iceBlast->isBlasting())
	{
		m_iceBlast->update(deltaTime, creeps);

		if (!m_iceBlast->isBlasting())
		{
			m_fStateTime = 0;
		}
	}
}