//
//  YellowCreepThree.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "YellowCreepThree.h"
#include "YellowMiniCreep.h"
#include "World.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "GameConstants.h"

YellowCreepThree::YellowCreepThree(float x, float y, int wave, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : YellowCreep (x, y, 0.84f, 0.84f, World::getHealthAdjustmentForWave(wave, 5), wave / 4 + 4, levelIndex, spawnPointIndex, isUsingAltPath)
{
	m_iWave = wave;
}

Creep_Type YellowCreepThree::getCreepType()
{
	return Creep_Type::YELLOW_CREEP_THREE;
}
	
void YellowCreepThree::scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts)
{
	addCreepThreeBodyParts(creepBodyParts, 2.5f);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LEFT_CHARGE_YELLOW_3, 2, 120);
	addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::RIGHT_CHARGE_YELLOW_3, 2, 240);
}

void YellowCreepThree::deploy(std::vector<Creep *> &creeps, int wave)
{
	if (m_direction == DIRECTION_RIGHT || m_direction == DIRECTION_LEFT)
	{
		creeps.push_back(new YellowMiniCreep(m_position->getX() - 0.40f, m_position->getY(), wave, m_pathIndex, m_direction, m_levelIndex, m_spawnPointIndex, m_isUsingAltPath));
		creeps.push_back(new YellowMiniCreep(m_position->getX(), m_position->getY(), wave, m_pathIndex, m_direction, m_levelIndex, m_spawnPointIndex, m_isUsingAltPath));
		creeps.push_back(new YellowMiniCreep(m_position->getX() + 0.40f, m_position->getY(), wave, m_pathIndex, m_direction, m_levelIndex, m_spawnPointIndex, m_isUsingAltPath));
	}
	else if (m_direction == DIRECTION_UP || m_direction == DIRECTION_DOWN)
	{
		creeps.push_back(new YellowMiniCreep(m_position->getX(), m_position->getY() - 0.40f, wave, m_pathIndex, m_direction, m_levelIndex, m_spawnPointIndex, m_isUsingAltPath));
		creeps.push_back(new YellowMiniCreep(m_position->getX(), m_position->getY(), wave, m_pathIndex, m_direction, m_levelIndex, m_spawnPointIndex, m_isUsingAltPath));
		creeps.push_back(new YellowMiniCreep(m_position->getX(), m_position->getY() + 0.40f, wave, m_pathIndex, m_direction, m_levelIndex, m_spawnPointIndex, m_isUsingAltPath));
	}

	setState(DEAD);
}

void YellowCreepThree::kill(Damage_Type damageType)
{
	// Explosions kill both the Creep and its mini versions
	if (damageType == Damage_Type::EXPLOSION)
	{
		m_pointValue += m_iWave / 10 + 1;
		m_pointValue += m_iWave / 10 + 1;
		m_pointValue += m_iWave / 10 + 1;
		Creep::kill(damageType);
	}
	else
	{
		setState(DEPLOYING);
	}
}