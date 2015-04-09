//
//  World.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/20/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "World.h"
#include "LevelUtils.h"
#include "VectorUtils.h"
#include "FlagUtil.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "Circle.h"
#include "OverlapTester.h"
#include "CreepBodyPart.h"
#include "Spawn.h"
#include "WorldPlatform.h"
#include "Projectile.h"
#include "Creep.h"
#include "Tower.h"
#include "ProjectileTower.h"
#include "TowerCursor.h"
#include "TouchCursor.h"
#include "ProjectileParticle.h"
#include "ElectricBolt.h"
#include "LazerBeam.h"
#include "Line.h"
#include "IceBlast.h"
#include "Missile.h"
#include "Explosion.h"
#include "FireBolt.h"
#include "ToxicCloud.h"
#include "AcidDrop.h"
#include "GameListener.h"
#include "ResourceConstants.h"
#include "GameConstants.h"

World * World::getInstance()
{
	static World *instance = new World();
	return instance;
}

Rectangle * World::getWorldBounds()
{
	static Rectangle * WORLD_BOUNDS = new Rectangle(0, 0, WORLD_WIDTH, WORLD_HEIGHT);
	return WORLD_BOUNDS;
}

bool World::isVectorInWorld(Vector2D &position)
{
	return OverlapTester::isPointInRectangle(position, *getWorldBounds());
}

int World::getHealthAdjustmentForWave(int wave, int scalar)
{
    switch(getInstance()->getDifficultyLevel())
	{
	case DIFFICULTY_LEVEL_EASY:
		return scalar * (50 + (wave * wave * 4));
	case DIFFICULTY_LEVEL_NORMAL:
		return scalar * (50 + (wave * wave * 6));
	case DIFFICULTY_LEVEL_HARD:
		return scalar * (50 + (wave * wave * 8));
	default:
		return 1;
	}

	return 1;
}

World::World()
{
	// Use the Reset method to initialize this Singleton
}

void World::reset(int levelIndex, int difficultyLevel)
{
	m_spawnPointsState = World_Spawn_Points_State::COUNTING_DOWN;
	m_fSpawnPointsStateTime = 0;
	m_fWaveWaitTime = 5;
	m_difficultyLevel = difficultyLevel;
	m_iLevelIndex = levelIndex;
	m_iWave = 0;
	m_iScoreEarnedThisFrame = 0;
	m_iTimesCoreShipModuleHitThisFrame = 0;

	m_spawns.clear();
	m_platforms.clear();
	m_creeps.clear();
	m_creepBodyParts.clear();
	m_towers.clear();
	m_projectiles.clear();
	m_projectileParticles.clear();
	m_electricBolts.clear();
	m_lazerBeams.clear();
	m_iceBlasts.clear();
	m_missiles.clear();
	m_explosions.clear();
	m_fireBolts.clear();
	m_toxicClouds.clear();
	m_acidDrops.clear();

	generateWorld();
}

World_Update_Response World::update(float deltaTime)
{
	m_iScoreEarnedThisFrame = 0;
	m_iTimesCoreShipModuleHitThisFrame = 0;

	World_Update_Response response = World_Update_Response::NO_EVENT;

	if (m_spawnPointsState == World_Spawn_Points_State::COUNTING_DOWN)
	{
		m_fSpawnPointsStateTime += deltaTime;

		if (m_fSpawnPointsStateTime > m_fWaveWaitTime)
		{
			spawnNextWave();
			response = World_Update_Response::WAVE_SPAWNED;
		}
	}
	else if (m_spawnPointsState == World_Spawn_Points_State::ALL_POINTS_SPAWNING)
	{
		if (areAllSpawnPointsFinishedSpawning() && m_creeps.size() == 0)
		{
			m_spawnPointsState = World_Spawn_Points_State::COUNTING_DOWN;
			m_fSpawnPointsStateTime = 0;

			response = World_Update_Response::WAVE_COMPLETED;
		}
	}

	for (std::vector<std::unique_ptr<Spawn>>::iterator itr = m_spawns.begin(); itr != m_spawns.end(); itr++)
	{
		(*itr)->update(deltaTime);
	}

	std::vector<Creep *> creepsTemp;
	for (std::vector<std::unique_ptr<Creep>>::iterator itr = m_creeps.begin(); itr != m_creeps.end(); )
	{
		if(FlagUtil::isFlagSet((*itr)->getState(), SET_TO_REMOVE))
		{
			itr = m_creeps.erase(itr);
		}
		else
		{
			(*itr)->update(deltaTime);

			if (FlagUtil::isFlagSet((*itr)->getState(), DEPLOYING))
			{
				(*itr)->deploy(creepsTemp, m_iWave);
			}

			if (FlagUtil::isFlagSet((*itr)->getState(), DEAD))
			{
				m_iScoreEarnedThisFrame += (*itr)->getPointValue();

				(*itr)->scatterCreepBodyParts(m_creepBodyParts);
				(*itr)->remove();

                GameListener::getInstance()->playSound(SOUND_CREEP_DEATH);
			}
			else if (FlagUtil::isFlagSet((*itr)->getState(), GOAL_REACHED))
			{
				m_iTimesCoreShipModuleHitThisFrame++;
				(*itr)->remove();
                
                GameListener::getInstance()->playSound(SOUND_GOAL_HIT);
			}

			++itr;
		}
	}

	if(creepsTemp.size() > 0)
	{
		for (std::vector<Creep *>::iterator itr = creepsTemp.begin(); itr != creepsTemp.end(); itr++)
		{
			m_creeps.push_back(std::unique_ptr<Creep>(*itr));
		}

		creepsTemp.clear();
	}

	for (std::vector<std::unique_ptr<CreepBodyPart>>::iterator itr = m_creepBodyParts.begin(); itr != m_creepBodyParts.end(); )
	{
		(*itr)->update(deltaTime);

		if ((*itr)->remove())
		{
			itr = m_creepBodyParts.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	for (std::vector<std::unique_ptr<Tower>>::iterator itr = m_towers.begin(); itr != m_towers.end(); itr++)
	{
		(*itr)->update(deltaTime, m_creeps);
	}

	for (std::vector<std::unique_ptr<Projectile>>::iterator itr = m_projectiles.begin(); itr != m_projectiles.end(); )
	{
		(*itr)->update(deltaTime, m_creeps);

		if ((*itr)->remove())
		{
			itr = m_projectiles.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	for (std::vector<std::unique_ptr<ElectricBolt>>::iterator itr = m_electricBolts.begin(); itr != m_electricBolts.end(); )
	{
		(*itr)->update(deltaTime, m_creeps, m_platforms, m_projectiles);

		if ((*itr)->remove())
		{
			itr = m_electricBolts.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	for (std::vector<std::unique_ptr<Missile>>::iterator itr = m_missiles.begin(); itr != m_missiles.end(); )
	{
		(*itr)->update(deltaTime, m_creeps, m_explosions);

		if ((*itr)->remove())
		{
			itr = m_missiles.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	for (std::vector<std::unique_ptr<FireBolt>>::iterator itr = m_fireBolts.begin(); itr != m_fireBolts.end(); )
	{
		(*itr)->update(deltaTime, m_creeps);

		if ((*itr)->remove())
		{
			itr = m_fireBolts.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	for (std::vector<std::unique_ptr<AcidDrop>>::iterator itr = m_acidDrops.begin(); itr != m_acidDrops.end(); )
	{
		(*itr)->update(deltaTime);

		if ((*itr)->remove())
		{
			itr = m_acidDrops.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	for (std::vector<std::unique_ptr<ToxicCloud>>::iterator itr = m_toxicClouds.begin(); itr != m_toxicClouds.end(); )
	{
		(*itr)->update(deltaTime, m_creeps);

		if ((*itr)->remove())
		{
			itr = m_toxicClouds.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	for (std::vector<std::unique_ptr<Explosion>>::iterator itr = m_explosions.begin(); itr != m_explosions.end(); )
	{
		(*itr)->update(deltaTime, m_creeps);

		if ((*itr)->remove())
		{
			itr = m_explosions.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	for (std::vector<std::unique_ptr<ProjectileParticle>>::iterator itr = m_projectileParticles.begin(); itr != m_projectileParticles.end(); )
	{
		(*itr)->update(deltaTime);

		if ((*itr)->remove())
		{
			itr = m_projectileParticles.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	return response;
}

bool World::handleTouchUp(Vector2D &touchPoint)
{
	if (areAllSpawnPointsFinishedSpawning() && isTouchingUpInsideSpawnPoint(touchPoint))
	{
		spawnNextWave();
		return true;
	}

	return false;
}

void World::updateTowerCursor(TowerCursor &towerCursor)
{
	for (std::vector<std::unique_ptr<WorldPlatform>>::iterator itr = m_platforms.begin(); itr != m_platforms.end(); itr++)
	{
		if (!(*itr)->holdsTower() && OverlapTester::doRectanglesOverlap(towerCursor.getDisplayBounds(), (*itr)->getBounds()))
		{
			towerCursor.acquirePositionLock(itr->get());
			return;
		}
	}
}

void World::updateTouchCursor(TouchCursor &touchCursor)
{
	for (std::vector<std::unique_ptr<WorldPlatform>>::iterator itr = m_platforms.begin(); itr != m_platforms.end(); itr++)
	{
		if ((*itr)->holdsTower() && OverlapTester::doRectanglesOverlap(touchCursor.getDisplayBounds(), (*itr)->getBounds()))
		{
			touchCursor.acquirePositionLock((*itr)->getTower());
			return;
		}
	}
}

bool World::placeTower(TowerCursor &towerCursor)
{
	if (towerCursor.isLockAcquired())
	{
		m_towers.push_back(std::unique_ptr<Tower>(towerCursor.createTower()));
		towerCursor.getLockedWorldPlatform()->setTower(m_towers.back().get());
        
        GameListener::getInstance()->playSound(SOUND_PLACE_TOWER);
        
		towerCursor.reset();
		return true;
	}

	return false;
}

void World::removeSelectedTower(TouchCursor &touchCursor)
{
	if(touchCursor.isTowerLockAcquired())
	{
		int towerID = touchCursor.getSelectedTower()->getID();

		for (std::vector<std::unique_ptr<WorldPlatform>>::iterator itr = m_platforms.begin(); itr != m_platforms.end(); itr++)
		{
			if ((*itr)->holdsTower() && (*itr)->getTower()->getID() == towerID)
			{
				(*itr)->setTower(nullptr);
				touchCursor.setVisibility(false);
				for (std::vector<std::unique_ptr<Tower>>::iterator itr = m_towers.begin(); itr != m_towers.end(); itr++)
				{
					if((*itr)->getID() == towerID)
					{
						(*itr)->onRemove();
						itr = m_towers.erase(itr);
						break;
					}
				}

				return;
			}
		}
	}
}

std::vector<std::unique_ptr<Spawn>> & World::getSpawns()
{
	return m_spawns;
}

std::vector<std::unique_ptr<WorldPlatform>> & World::getPlatforms()
{
	return m_platforms;
}

std::vector<std::unique_ptr<Creep>> & World::getCreeps()
{
	return m_creeps;
}

std::vector<std::unique_ptr<CreepBodyPart>> & World::getCreepBodyParts()
{
	return m_creepBodyParts;
}

std::vector<std::unique_ptr<Tower>> & World::getTowers()
{
	return m_towers;
}

std::vector<std::unique_ptr<Projectile>> & World::getProjectiles()
{
	return m_projectiles;
}

std::vector<std::unique_ptr<ProjectileParticle>> & World::getProjectileParticles()
{
	return m_projectileParticles;
}

std::vector<std::unique_ptr<ElectricBolt>> & World::getElectricBolts()
{
	return m_electricBolts;
}

std::vector<std::unique_ptr<LazerBeam>> & World::getLazerBeams()
{
	return m_lazerBeams;
}

std::vector<std::unique_ptr<IceBlast>> & World::getIceBlasts()
{
	return m_iceBlasts;
}

std::vector<std::unique_ptr<Missile>> & World::getMissiles()
{
	return m_missiles;
}

std::vector<std::unique_ptr<Explosion>> & World::getExplosions()
{
	return m_explosions;
}

std::vector<std::unique_ptr<FireBolt>> & World::getFireBolts()
{
	return m_fireBolts;
}

std::vector<std::unique_ptr<ToxicCloud>> & World::getToxicClouds()
{
	return m_toxicClouds;
}

std::vector<std::unique_ptr<AcidDrop>> & World::getAcidDrops()
{
	return m_acidDrops;
}

int World::getDifficultyLevel()
{
	return m_difficultyLevel;
}

World_Spawn_Points_State World::getSpawnPointsState()
{
	return m_spawnPointsState;
}

int World::getSpawnNextWaveTimerArcDegrees()
{
	return m_fSpawnPointsStateTime > m_fWaveWaitTime ? 360 : (int) (360 * (m_fSpawnPointsStateTime / m_fWaveWaitTime));
}

int World::getWave()
{
	return m_iWave;
}

int World::getScoredEarnedThisFrame()
{
	return m_iScoreEarnedThisFrame;
}

int World::getTimesCoreShipModuleHitThisFrame()
{
	return m_iTimesCoreShipModuleHitThisFrame;
}

bool World::isAtLeastOnePlatformAvailable()
{
	for (std::vector<std::unique_ptr<WorldPlatform>>::iterator itr = getPlatforms().begin(); itr != getPlatforms().end(); itr++)
	{
		if (!(*itr)->holdsTower())
		{
			return true;
		}
	}

	return false;
}

// Private Methods

void World::generateWorld()
{
	int row = 8;
	int spawnPointIndex = 0;
	std::string column = "";
	std::vector<std::string> rows = LevelUtils::getRowsForLevelIndex(m_iLevelIndex);

	for (unsigned int r = 0; r < rows.size(); r++)
	{
		std::vector<std::string> currentRow = VectorUtils::split(rows.at(r), ',');
		for (unsigned int c = 0; c < currentRow.size(); c++)
		{
			column = currentRow.at(c);

			if (column[0] == 'p')
			{
				m_platforms.push_back(std::unique_ptr<WorldPlatform>(new WorldPlatform(c + GAME_X, row + GAME_Y, getPlatformTypeForStringID(column))));
			}
			else if (column == "spp")
			{
				m_spawns.push_back(std::unique_ptr<Spawn>(new Spawn(c + GAME_X, row + GAME_Y, m_iLevelIndex, spawnPointIndex++)));
			}
		}

		row--;
	}
}

void World::spawnNextWave()
{
	m_iWave++;

	if (m_spawnPointsState == World_Spawn_Points_State::ALL_POINTS_SPAWNING)
	{
		m_iScoreEarnedThisFrame += m_iWave;
	}
	else if (m_fSpawnPointsStateTime < m_fWaveWaitTime)
	{
		m_iScoreEarnedThisFrame += (int) (m_iWave * (m_fWaveWaitTime - m_fSpawnPointsStateTime) / m_fWaveWaitTime);
	}

	for (std::vector<std::unique_ptr<Spawn>>::iterator itr = m_spawns.begin(); itr != m_spawns.end(); itr++)
	{
		(*itr)->spawnNextWave(m_iWave);
		(*itr)->getSpawnNextWaveTimer().m_fRadius = 0.4f;
	}

	m_spawnPointsState = World_Spawn_Points_State::ALL_POINTS_SPAWNING;

    GameListener::getInstance()->playSound(SOUND_BEGIN_WAVE);
}

bool World::isTouchingUpInsideSpawnPoint(Vector2D &touchPoint)
{
	for (std::vector<std::unique_ptr<Spawn>>::iterator itr = m_spawns.begin(); itr != m_spawns.end(); itr++)
	{
		if(OverlapTester::isPointInRectangle(touchPoint, (*itr)->getBounds()))
		{
			return true;
		}
	}

	return false;
}

bool World::areAllSpawnPointsFinishedSpawning()
{
	for (std::vector<std::unique_ptr<Spawn>>::iterator itr = m_spawns.begin(); itr != m_spawns.end(); itr++)
	{
		if ((*itr)->getState() == Spawn_State::SPAWNING)
		{
			return false;
		}
	}

	return true;
}

World_Platform_Type World::getPlatformTypeForStringID(std::string &id)
{
	if (id == "pso")
	{
		return World_Platform_Type::SOLO;
	}
	else if (id == "ptl")
	{
		return World_Platform_Type::TOP_LEFT;
	}
	else if (id == "ptr")
	{
		return World_Platform_Type::TOP_RIGHT;
	}
	else if (id == "pbl")
	{
		return World_Platform_Type::BOTTOM_LEFT;
	}
	else if (id == "pbr")
	{
		return World_Platform_Type::BOTTOM_RIGHT;
	}
	else if (id == "pcp")
	{
		return World_Platform_Type::CENTER;
	}
	else if (id == "php")
	{
		return World_Platform_Type::HORIZONTAL;
	}
	else if (id == "pvp")
	{
		return World_Platform_Type::VERTICAL;
	}
	else if (id == "ptt")
	{
		return World_Platform_Type::TOP_THREE_WAY;
	}
	else if (id == "pbt")
	{
		return World_Platform_Type::BOTTOM_THREE_WAY;
	}
	else if (id == "plt")
	{
		return World_Platform_Type::LEFT_THREE_WAY;
	}
	else if (id == "prt")
	{
		return World_Platform_Type::RIGHT_THREE_WAY;
	}
	else if (id == "pet")
	{
		return World_Platform_Type::END_TOP;
	}
	else if (id == "peb")
	{
		return World_Platform_Type::END_BOTTOM;
	}
	else if (id == "pel")
	{
		return World_Platform_Type::END_LEFT;
	}
	else
	{
		return World_Platform_Type::END_RIGHT;
	}
}