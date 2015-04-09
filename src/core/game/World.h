//
//  World.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 9/11/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__World__
#define __insectoiddefense__World__

#include "DifficultyLevel.h"
#include "WorldPlatformType.h"
#include "WorldSpawnPointsState.h"
#include "WorldUpdateResponse.h"
#include "Color.h"

#include <vector>
#include <memory>

class OverlapTester;
class Spawn;
class CreepBodyPart;
class WorldPlatform;
class Creep;
class Tower;
class Projectile;
class Rectangle;
class Vector2D;
class TowerCursor;
class TouchCursor;
class ProjectileParticle;
class ElectricBolt;
class LazerBeam;
class IceBlast;
class Missile;
class Explosion;
class FireBolt;
class ToxicCloud;
class AcidDrop;

class World
{
public:
	static Color getSpawnTimerColor()
	{
        Color color = Color(1, 1, 1, 0.25f);
		return color;
	}

	static World * getInstance();

	static Rectangle * getWorldBounds();

	static bool isVectorInWorld(Vector2D &position);

	static int getHealthAdjustmentForWave(int wave, int scalar);

	World();

	void reset(int levelIndex = 0, int difficultyLevel = DIFFICULTY_LEVEL_NORMAL);

	World_Update_Response update(float deltaTime);

	bool handleTouchUp(Vector2D &touchPoint);

	void updateTowerCursor(TowerCursor &towerCursor);

	void updateTouchCursor(TouchCursor &touchCursor);

	bool placeTower(TowerCursor &towerCursor);

	void removeSelectedTower(TouchCursor &touchCursor);

	std::vector<std::unique_ptr<Spawn>> & getSpawns();

	std::vector<std::unique_ptr<WorldPlatform>> & getPlatforms();

	std::vector<std::unique_ptr<Creep>> & getCreeps();

	std::vector<std::unique_ptr<CreepBodyPart>> & getCreepBodyParts();

	std::vector<std::unique_ptr<Tower>> & getTowers();

	std::vector<std::unique_ptr<Projectile>> & getProjectiles();

	std::vector<std::unique_ptr<ProjectileParticle>> & getProjectileParticles();

	std::vector<std::unique_ptr<ElectricBolt>> & getElectricBolts();

	std::vector<std::unique_ptr<LazerBeam>> & getLazerBeams();

	std::vector<std::unique_ptr<IceBlast>> & getIceBlasts();

	std::vector<std::unique_ptr<Missile>> & getMissiles();

	std::vector<std::unique_ptr<Explosion>> & getExplosions();

	std::vector<std::unique_ptr<FireBolt>> & getFireBolts();

	std::vector<std::unique_ptr<ToxicCloud>> & getToxicClouds();

	std::vector<std::unique_ptr<AcidDrop>> & getAcidDrops();

	int getDifficultyLevel();

	World_Spawn_Points_State getSpawnPointsState();

	int getSpawnNextWaveTimerArcDegrees();

	int getWave();

	int getScoredEarnedThisFrame();

	int getTimesCoreShipModuleHitThisFrame();

	bool isAtLeastOnePlatformAvailable();

private:
	World_Spawn_Points_State m_spawnPointsState;
	float m_fSpawnPointsStateTime;
	float m_fWaveWaitTime;
	int m_difficultyLevel;
	int m_iLevelIndex;
	int m_iWave;
	int m_iScoreEarnedThisFrame;
	int m_iTimesCoreShipModuleHitThisFrame;

	std::vector<std::unique_ptr<Spawn>> m_spawns;
	std::vector<std::unique_ptr<WorldPlatform>> m_platforms;
	std::vector<std::unique_ptr<Creep>> m_creeps;
	std::vector<std::unique_ptr<CreepBodyPart>> m_creepBodyParts;
	std::vector<std::unique_ptr<Tower>> m_towers;
	std::vector<std::unique_ptr<Projectile>> m_projectiles;
	std::vector<std::unique_ptr<ProjectileParticle>> m_projectileParticles;
	std::vector<std::unique_ptr<ElectricBolt>> m_electricBolts;
	std::vector<std::unique_ptr<LazerBeam>> m_lazerBeams;
	std::vector<std::unique_ptr<IceBlast>> m_iceBlasts;
	std::vector<std::unique_ptr<Missile>> m_missiles;
	std::vector<std::unique_ptr<Explosion>> m_explosions;
	std::vector<std::unique_ptr<FireBolt>> m_fireBolts;
	std::vector<std::unique_ptr<ToxicCloud>> m_toxicClouds;
	std::vector<std::unique_ptr<AcidDrop>> m_acidDrops;

	void generateWorld();

	void spawnNextWave();

	bool isTouchingUpInsideSpawnPoint(Vector2D &touchPoint);

	bool areAllSpawnPointsFinishedSpawning();

	World_Platform_Type getPlatformTypeForStringID(std::string &id);
};

#endif /* defined(__insectoiddefense__World__) */