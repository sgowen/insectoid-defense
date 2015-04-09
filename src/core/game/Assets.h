//
//  Assets.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__Assets__
#define __insectoiddefense__Assets__

#define MAX_SOUNDS_TO_PLAY_PER_FRAME 3

#include <vector>

#include "ShipModuleType.h"
#include "AsteroidType.h"
#include "TowerType.h"

class TextureRegion;
class Tower;
class Creep;
class WorldPlatform;
class Spawn;
class Projectile;
class CreepBodyPart;
class CoreShipModule;
class ProjectileParticle;
class ElectricBolt;
class IceBlast;
class Explosion;
class Missile;
class FireBolt;
class AcidDrop;

class Assets
{
public:
	static Assets * getInstance();
    
    static TextureRegion& getBackgroundLeftSource();
    
    static TextureRegion& getBackgroundRightSource();
    
    static TextureRegion& getAsteroidSourceForType(Asteroid_Type type);
    
    static TextureRegion& getTimeButtonSourceForSpeedScalar(int speedScalar);
    
    static TextureRegion& getShipModuleSource(Ship_Module_Type ship);
    
    static TextureRegion& getCoreShipModuleSource(CoreShipModule &coreShipModule);
    
    static TextureRegion& getTowerMenuBackgroundSource();
    
    static TextureRegion& getDialogSource();
    
    static TextureRegion& getSpawnSource(Spawn &spawn);
    
    static TextureRegion& getPlatformSource(WorldPlatform &platform);
    
    static TextureRegion& getCreepSource(Creep &creep, bool initOnly);
    
    static TextureRegion& getCreepHealthBarSource(Creep &creep);
    
    static TextureRegion& getCreepBodyPartSource(CreepBodyPart &creepBodyPart);
    
    static TextureRegion& getTowerSource(Tower &tower);
    
    static TextureRegion& getTowerSource(Tower_Type towerType, int towerStage);
    
    static TextureRegion& getProjectileSource(Projectile &projectile);
    
    static TextureRegion& getProjectileParticleSource(ProjectileParticle &projectileParticle);
    
    static TextureRegion& getElectricBoltSource(ElectricBolt &electricBolt);
    
    static TextureRegion& getIceBlastSource(IceBlast &iceBlast);
    
    static TextureRegion& getExplosionSource(Explosion &explosion);
    
    static TextureRegion& getMissileSource(Missile &missile);
    
    static TextureRegion& getFireBoltSource(FireBolt &fireBolt);
    
    static TextureRegion& getAcidDropSource(AcidDrop &acidDrop);
    
    void setMusicId(short musicId);
    
    short getMusicId();
    
    short getFirstSoundId();
    
    void addSoundIdToPlayQueue(short soundId);
    
    void eraseFirstSoundId();

private:
    Assets();
    
    static int getKeyFrameNumber(float stateTime, float cycleTime, std::vector<float> &frameDurations);
    
    std::vector<short> m_sSoundIds;
    short m_sMusicId;
};

#endif /* defined(__insectoiddefense__Assets__) */