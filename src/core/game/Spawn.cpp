//
//  Spawn.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/12/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "Spawn.h"
#include "World.h"
#include "VectorUtils.h"
#include "LevelUtils.h"
#include "HardCodedPathGenerator.h"
#include "BlueCreepOne.h"
#include "BlueCreepTwo.h"
#include "BlueCreepThree.h"
#include "RedCreepOne.h"
#include "RedCreepTwo.h"
#include "RedCreepThree.h"
#include "GreenCreepOne.h"
#include "GreenCreepTwo.h"
#include "GreenCreepThree.h"
#include "YellowCreepOne.h"
#include "YellowCreepTwo.h"
#include "YellowCreepThree.h"
#include "BossCreep.h"
#include "Circle.h"
#include "Vector2D.h"
#include "Node.h"
#include "Rectangle.h"
#include "GameConstants.h"

Spawn::Spawn(float x, float y, int levelIndex, int spawnPointIndex) : PhysicalEntity (x, y, 0.90f, 0.90f, 0)
{
	m_spawnNextWaveTimer = std::unique_ptr<Circle>(new Circle(x, y, 0.4f));
	
	m_fStateTime = 0.0f;
	m_iLevelIndex = levelIndex;
	m_iSpawnPointIndex = spawnPointIndex;
	m_iWave = 0;
	m_iCreepsSpawned = 0;
	
	resetBounds(1.20f, 1.20f);

	HardCodedPathGenerator::getHardCodedPathForLevelSpawnPointIndex(levelIndex, spawnPointIndex, false, false);
	LevelUtils::getWavesForLevelIndexAndSpawnPointIndex(levelIndex, spawnPointIndex);
	
	setState(Spawn_State::IDLE);
}

void Spawn::update(float deltaTime)
{
	if (m_state == Spawn_State::SPAWNING)
	{
		m_fStateTime += deltaTime;
		if (m_fStateTime > TIME_TO_SPAWN_CREEP)
		{
			World::getInstance()->getCreeps().push_back(std::unique_ptr<Creep>(generateCreep()));
			m_iCreepsSpawned++;

			if (m_iCreepsSpawned == m_currentWave.size())
			{
				setState(Spawn_State::IDLE);
			}
			else
			{
				setState(m_iCreepsSpawned % m_currentWave.size() == 0 ? Spawn_State::IDLE : Spawn_State::SPAWNING);
			}
		}
	}
}
	
void Spawn::spawnNextWave(int wave)
{
	m_iCreepsSpawned = 0;
	m_iWave = wave;
	m_isUsingAltPath = true;

	std::vector<std::string> waves = LevelUtils::getWavesForLevelIndexAndSpawnPointIndex(m_iLevelIndex, m_iSpawnPointIndex);
	m_currentWave = VectorUtils::split(waves.at((m_iWave - 1) % waves.size()), ',');

	setState(Spawn_State::SPAWNING);
}

Circle& Spawn::getSpawnNextWaveTimer()
{
	return *m_spawnNextWaveTimer;
}
	
Spawn_State Spawn::getState()
{
	return m_state;
}

int Spawn::getCreepsSpawned()
{
	return m_iCreepsSpawned;
}

void Spawn::setState(Spawn_State state)
{
	m_fStateTime = 0;
	m_state = state;
}
	
Creep * Spawn::generateCreep()
{
	m_isUsingAltPath = !m_isUsingAltPath;

	if(m_currentWave.at(m_iCreepsSpawned) == "b1")
	{
		return new BlueCreepOne(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	else if(m_currentWave.at(m_iCreepsSpawned) == "b2")
	{
		return new BlueCreepTwo(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	else if(m_currentWave.at(m_iCreepsSpawned) == "b3")
	{
		return new BlueCreepThree(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	if(m_currentWave.at(m_iCreepsSpawned) == "r1")
	{
		return new RedCreepOne(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	else if(m_currentWave.at(m_iCreepsSpawned) == "r2")
	{
		return new RedCreepTwo(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	else if(m_currentWave.at(m_iCreepsSpawned) == "r3")
	{
		return new RedCreepThree(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	if(m_currentWave.at(m_iCreepsSpawned) == "g1")
	{
		return new GreenCreepOne(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	else if(m_currentWave.at(m_iCreepsSpawned) == "g2")
	{
		return new GreenCreepTwo(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	else if(m_currentWave.at(m_iCreepsSpawned) == "g3")
	{
		return new GreenCreepThree(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	if(m_currentWave.at(m_iCreepsSpawned) == "y1")
	{
		return new YellowCreepOne(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	else if(m_currentWave.at(m_iCreepsSpawned) == "y2")
	{
		return new YellowCreepTwo(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	else if(m_currentWave.at(m_iCreepsSpawned) == "y3")
	{
		return new YellowCreepThree(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
	else
	{
		return new BossCreep(m_position->getX(), m_position->getY(), m_iWave, m_iLevelIndex, m_iSpawnPointIndex, m_isUsingAltPath);
	}
}