//
//  Spawn.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/12/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__Spawn__
#define __insectoiddefense__Spawn__

#include "PhysicalEntity.h"
#include "SpawnState.h"
#include <vector>
#include <string>

class Creep;
struct Node;
class Circle;

class Spawn : public PhysicalEntity
{
public:
	Spawn(float x, float y, int levelIndex, int spawnPointIndex);
	
	void update(float deltaTime);
	
	void spawnNextWave(int wave);
	
	Circle& getSpawnNextWaveTimer();
	
	Spawn_State getState();
	
	int getCreepsSpawned();

private:
	std::unique_ptr<Circle> m_spawnNextWaveTimer;
	std::vector<std::string> m_currentWave;
	Spawn_State m_state;
	int m_iLevelIndex;
	int m_iSpawnPointIndex;
	int m_iWave;
	int m_iCreepsSpawned;
	bool m_isUsingAltPath;
	
	void setState(Spawn_State state);
	
	Creep * generateCreep();
};

#endif /* defined(__insectoiddefense__Spawn__) */