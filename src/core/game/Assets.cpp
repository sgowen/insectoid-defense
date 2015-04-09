//
//  Assets.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "Assets.h"
#include "TextureRegion.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "Tower.h"
#include "Creep.h"
#include "WorldPlatform.h"
#include "Spawn.h"
#include "Projectile.h"
#include "CreepBodyPart.h"
#include "CoreShipModule.h"
#include "ProjectileParticle.h"
#include "ElectricBolt.h"
#include "IceBlast.h"
#include "Explosion.h"
#include "Missile.h"
#include "FireBolt.h"
#include "AcidDrop.h"
#include "ResourceConstants.h"
#include "BossCreep.h"

Assets * Assets::getInstance()
{
    static Assets *assets = new Assets();
    return assets;
}

TextureRegion& Assets::getBackgroundLeftSource()
{
    static TextureRegion backgroundLeftSource = TextureRegion(4, 216, 600, 400, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    return backgroundLeftSource;
}

TextureRegion& Assets::getBackgroundRightSource()
{
    static TextureRegion backgroundRightSource = TextureRegion(4, 620, 600, 400, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    return backgroundRightSource;
}

TextureRegion& Assets::getAsteroidSourceForType(Asteroid_Type type)
{
    if(type == Asteroid_Type::GRAY)
    {
        static TextureRegion grayAsteroidSource = TextureRegion(892, 485, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        return grayAsteroidSource;
    }
    else
    {
        static TextureRegion brownAsteroidSource = TextureRegion(930, 632, 90, 90, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        return brownAsteroidSource;
    }
}

TextureRegion& Assets::getTimeButtonSourceForSpeedScalar(int speedScalar)
{
    static TextureRegion timeButton0Source = TextureRegion(2,   2, 90, 45, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion timeButton1Source = TextureRegion(2,  51, 90, 45, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion timeButton2Source = TextureRegion(2, 100, 90, 45, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion timeButton3Source = TextureRegion(2, 149, 90, 45, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    switch(speedScalar)
    {
        case 0:
            return timeButton0Source;
        case 1:
            return timeButton1Source;
        case 2:
            return timeButton2Source;
        case 3:
            return timeButton3Source;
    }
    
    return timeButton0Source;
}

TextureRegion& Assets::getShipModuleSource(Ship_Module_Type ship)
{
    static TextureRegion CIVILIAN_ONE_shipModuleSource = TextureRegion(336, 86, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion CIVILIAN_TWO_shipModuleSource = TextureRegion(336, 2, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion ENGINE_ONE_shipModuleSource = TextureRegion(560, 86, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion ENGINE_TWO_shipModuleSource = TextureRegion(672, 86, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion FACTORY_ONE_shipModuleSource = TextureRegion(224, 2, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion FACTORY_TWO_shipModuleSource = TextureRegion(224, 86, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion HANGAR_ONE_shipModuleSource = TextureRegion(560, 2, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion HANGAR_TWO_shipModuleSource = TextureRegion(448, 2, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion REGULAR_ONE_shipModuleSource = TextureRegion(784, 170, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion REGULAR_TWO_shipModuleSource = TextureRegion(784, 86, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion REGULAR_THREE_shipModuleSource = TextureRegion(784, 2, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion SHIP_AFFILIATION_shipModuleSource = TextureRegion(448, 86, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion SIDE_TOP_shipModuleSource = TextureRegion(112, 2, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    switch(ship)
    {
        case CIVILIAN_ONE:
            return CIVILIAN_ONE_shipModuleSource;
        case CIVILIAN_TWO:
            return CIVILIAN_TWO_shipModuleSource;
        case ENGINE_ONE:
            return ENGINE_ONE_shipModuleSource;
        case ENGINE_TWO:
            return ENGINE_TWO_shipModuleSource;
        case FACTORY_ONE:
            return FACTORY_ONE_shipModuleSource;
        case FACTORY_TWO:
            return FACTORY_TWO_shipModuleSource;
        case HANGAR_ONE:
            return HANGAR_ONE_shipModuleSource;
        case HANGAR_TWO:
            return HANGAR_TWO_shipModuleSource;
        case REGULAR_ONE:
            return REGULAR_ONE_shipModuleSource;
        case REGULAR_TWO:
            return REGULAR_TWO_shipModuleSource;
        case REGULAR_THREE:
            return REGULAR_THREE_shipModuleSource;
        case SHIP_AFFILIATION:
            return SHIP_AFFILIATION_shipModuleSource;
        case SIDE_TOP:
            return SIDE_TOP_shipModuleSource;
        default:
            return SIDE_TOP_shipModuleSource;
    }
}

TextureRegion& Assets::getCoreShipModuleSource(CoreShipModule &coreShipModule)
{
    static TextureRegion coreshipModule_10_healthSource = TextureRegion(620, 260, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreshipModule_9_healthSource = TextureRegion(732, 260, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreshipModule_8_healthSource = TextureRegion(620, 344, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreshipModule_7_healthSource = TextureRegion(732, 344, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreshipModule_6_healthSource = TextureRegion(620, 428, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreshipModule_5_healthSource = TextureRegion(732, 428, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreshipModule_4_healthSource = TextureRegion(620, 512, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreshipModule_3_healthSource = TextureRegion(732, 512, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreshipModule_2_healthSource = TextureRegion(620, 596, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreshipModule_1_healthSource = TextureRegion(732, 596, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreshipModule_0_healthSource = TextureRegion(620, 680, 108, 80, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    if(coreShipModule.getState() == Core_Ship_Module_State::TAKING_DAMAGE)
    {
        return coreshipModule_0_healthSource;
    }
    
    switch(coreShipModule.getRemainingHealth())
    {
        case 10:
            return coreshipModule_10_healthSource;
        case 9:
            return coreshipModule_9_healthSource;
        case 8:
            return coreshipModule_8_healthSource;
        case 7:
            return coreshipModule_7_healthSource;
        case 6:
            return coreshipModule_6_healthSource;
        case 5:
            return coreshipModule_5_healthSource;
        case 4:
            return coreshipModule_4_healthSource;
        case 3:
            return coreshipModule_3_healthSource;
        case 2:
            return coreshipModule_2_healthSource;
        case 1:
            return coreshipModule_1_healthSource;
        case 0:
            return coreshipModule_0_healthSource;
        default:
            return coreshipModule_0_healthSource;
    }
}

TextureRegion& Assets::getTowerMenuBackgroundSource()
{
    static TextureRegion towerMenuBackgroundSource = TextureRegion(960, 4, 60, 400, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    return towerMenuBackgroundSource;
}

TextureRegion& Assets::getDialogSource()
{
    static TextureRegion dialogSource = TextureRegion(0, 381, 386, 126, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    return dialogSource;
}

TextureRegion& Assets::getSpawnSource(Spawn &spawn)
{
    static std::vector<TextureRegion> spawn_sources;
    if(spawn_sources.size() == 0)
    {
        static TextureRegion spawn_source_1 = TextureRegion(0, 74, 70, 70, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion spawn_source_2 = TextureRegion(74, 74, 70, 70, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion spawn_source_3 = TextureRegion(148, 74, 70, 70, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion spawn_source_4 = TextureRegion(222, 74, 70, 70, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion spawn_source_5 = TextureRegion(296, 74, 70, 70, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion spawn_source_6 = TextureRegion(370, 74, 70, 70, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        spawn_sources.push_back(spawn_source_1);
        spawn_sources.push_back(spawn_source_2);
        spawn_sources.push_back(spawn_source_3);
        spawn_sources.push_back(spawn_source_4);
        spawn_sources.push_back(spawn_source_5);
        spawn_sources.push_back(spawn_source_6);
    }
    
    static float cycleTime = 1.0f;
    static std::vector<float> spawn_frames;
    if(spawn_frames.size() == 0)
    {
        spawn_frames.push_back(0.2f);
        spawn_frames.push_back(0.2f);
        spawn_frames.push_back(0.2f);
        spawn_frames.push_back(0.2f);
        spawn_frames.push_back(0.2f);
    }
    
    if(spawn.getState() == IDLE)
    {
        return spawn_sources.at(5);
    }
    else
    {
        return spawn_sources.at(getKeyFrameNumber(spawn.getStateTime(), cycleTime, spawn_frames));
    }
}

TextureRegion& Assets::getPlatformSource(WorldPlatform &platform)
{
    static TextureRegion platform_s   = TextureRegion(464, 212, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_tl  = TextureRegion(364, 362, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_tr  = TextureRegion(464, 362, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_bl  = TextureRegion(364, 462, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_br  = TextureRegion(464, 462, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_c   = TextureRegion(414, 412, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_h   = TextureRegion(464, 312, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_v   = TextureRegion(414, 312, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_ttw = TextureRegion(414, 362, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_btw = TextureRegion(414, 462, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_ltw = TextureRegion(364, 412, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_rtw = TextureRegion(464, 412, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_et  = TextureRegion(364, 262, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_eb  = TextureRegion(364, 312, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_el  = TextureRegion(414, 262, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion platform_er  = TextureRegion(464, 262, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    switch(platform.getType())
    {
        case SOLO:
            return platform_s;
        case TOP_LEFT:
            return platform_tl;
        case TOP_RIGHT:
            return platform_tr;
        case BOTTOM_LEFT:
            return platform_bl;
        case BOTTOM_RIGHT:
            return platform_br;
        case CENTER:
            return platform_c;
        case HORIZONTAL:
            return platform_h;
        case VERTICAL:
            return platform_v;
        case TOP_THREE_WAY:
            return platform_ttw;
        case BOTTOM_THREE_WAY:
            return platform_btw;
        case LEFT_THREE_WAY:
            return platform_ltw;
        case RIGHT_THREE_WAY:
            return platform_rtw;
        case END_TOP:
            return platform_et;
        case END_BOTTOM:
            return platform_eb;
        case END_LEFT:
            return platform_el;
        default:
            return platform_er;
    }
}

TextureRegion& Assets::getCreepSource(Creep &creep, bool initOnly)
{
    static std::vector<TextureRegion> blueCreepOneSources;
    if(blueCreepOneSources.size() == 0)
    {
        static TextureRegion blueCreepOneSource1 = TextureRegion(46 * 0, 0, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion blueCreepOneSource2 = TextureRegion(46 * 1, 0, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion blueCreepOneSource3 = TextureRegion(46 * 2, 0, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion blueCreepOneSource4 = TextureRegion(46 * 3, 0, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion blueCreepOneSource5 = TextureRegion(46 * 4, 0, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion blueCreepOneSource6 = TextureRegion(46 * 5, 0, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        blueCreepOneSources.push_back(blueCreepOneSource1);
        blueCreepOneSources.push_back(blueCreepOneSource2);
        blueCreepOneSources.push_back(blueCreepOneSource3);
        blueCreepOneSources.push_back(blueCreepOneSource4);
        blueCreepOneSources.push_back(blueCreepOneSource5);
        blueCreepOneSources.push_back(blueCreepOneSource6);
    }
    
    static std::vector<TextureRegion> blueCreepTwoSources;
    if(blueCreepTwoSources.size() == 0)
    {
        static TextureRegion blueCreepTwoSource1 = TextureRegion(46 * 6, 0, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion blueCreepTwoSource2 = TextureRegion(46 * 7, 0, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion blueCreepTwoSource3 = TextureRegion(46 * 8, 0, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion blueCreepTwoSource4 = TextureRegion(46 * 9, 0, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        blueCreepTwoSources.push_back(blueCreepTwoSource1);
        blueCreepTwoSources.push_back(blueCreepTwoSource2);
        blueCreepTwoSources.push_back(blueCreepTwoSource3);
        blueCreepTwoSources.push_back(blueCreepTwoSource4);
    }
    
    static std::vector<TextureRegion> blueCreepThreeSources;
    if(blueCreepThreeSources.size() == 0)
    {
        static TextureRegion blueCreepThreeSource1 = TextureRegion(46 * 0, 46 * 4, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion blueCreepThreeSource2 = TextureRegion(46 * 1, 46 * 4, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion blueCreepThreeSource3 = TextureRegion(46 * 2, 46 * 4, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion blueCreepThreeSource4 = TextureRegion(46 * 3, 46 * 4, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        blueCreepThreeSources.push_back(blueCreepThreeSource1);
        blueCreepThreeSources.push_back(blueCreepThreeSource2);
        blueCreepThreeSources.push_back(blueCreepThreeSource3);
        blueCreepThreeSources.push_back(blueCreepThreeSource4);
    }
    
    static std::vector<TextureRegion> redCreepOneSources;
    if(redCreepOneSources.size() == 0)
    {
        static TextureRegion redCreepOneSource1 = TextureRegion(46 * 0, 46 * 2, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion redCreepOneSource2 = TextureRegion(46 * 1, 46 * 2, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion redCreepOneSource3 = TextureRegion(46 * 2, 46 * 2, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion redCreepOneSource4 = TextureRegion(46 * 3, 46 * 2, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion redCreepOneSource5 = TextureRegion(46 * 4, 46 * 2, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion redCreepOneSource6 = TextureRegion(46 * 5, 46 * 2, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        redCreepOneSources.push_back(redCreepOneSource1);
        redCreepOneSources.push_back(redCreepOneSource2);
        redCreepOneSources.push_back(redCreepOneSource3);
        redCreepOneSources.push_back(redCreepOneSource4);
        redCreepOneSources.push_back(redCreepOneSource5);
        redCreepOneSources.push_back(redCreepOneSource6);
    }
    
    static std::vector<TextureRegion> redCreepTwoSources;
    if(redCreepTwoSources.size() == 0)
    {
        static TextureRegion redCreepTwoSource1 = TextureRegion(46 * 6, 46 * 2, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion redCreepTwoSource2 = TextureRegion(46 * 7, 46 * 2, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion redCreepTwoSource3 = TextureRegion(46 * 8, 46 * 2, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion redCreepTwoSource4 = TextureRegion(46 * 9, 46 * 2, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        redCreepTwoSources.push_back(redCreepTwoSource1);
        redCreepTwoSources.push_back(redCreepTwoSource2);
        redCreepTwoSources.push_back(redCreepTwoSource3);
        redCreepTwoSources.push_back(redCreepTwoSource4);
    }
    
    static std::vector<TextureRegion> redCreepThreeSources;
    if(redCreepThreeSources.size() == 0)
    {
        static TextureRegion redCreepThreeSource1 = TextureRegion(46 * 0, 46 * 6, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion redCreepThreeSource2 = TextureRegion(46 * 1, 46 * 6, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion redCreepThreeSource3 = TextureRegion(46 * 2, 46 * 6, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion redCreepThreeSource4 = TextureRegion(46 * 3, 46 * 6, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        redCreepThreeSources.push_back(redCreepThreeSource1);
        redCreepThreeSources.push_back(redCreepThreeSource2);
        redCreepThreeSources.push_back(redCreepThreeSource3);
        redCreepThreeSources.push_back(redCreepThreeSource4);
    }
    
    static std::vector<TextureRegion> greenCreepOneSources;
    if(greenCreepOneSources.size() == 0)
    {
        static TextureRegion greenCreepOneSource1 = TextureRegion(46 * 0, 46 * 1, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion greenCreepOneSource2 = TextureRegion(46 * 1, 46 * 1, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion greenCreepOneSource3 = TextureRegion(46 * 2, 46 * 1, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion greenCreepOneSource4 = TextureRegion(46 * 3, 46 * 1, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion greenCreepOneSource5 = TextureRegion(46 * 4, 46 * 1, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion greenCreepOneSource6 = TextureRegion(46 * 5, 46 * 1, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        greenCreepOneSources.push_back(greenCreepOneSource1);
        greenCreepOneSources.push_back(greenCreepOneSource2);
        greenCreepOneSources.push_back(greenCreepOneSource3);
        greenCreepOneSources.push_back(greenCreepOneSource4);
        greenCreepOneSources.push_back(greenCreepOneSource5);
        greenCreepOneSources.push_back(greenCreepOneSource6);
    }
    
    static std::vector<TextureRegion> greenCreepTwoSources;
    if(greenCreepTwoSources.size() == 0)
    {
        static TextureRegion greenCreepTwoSource1 = TextureRegion(46 * 6, 46 * 1, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion greenCreepTwoSource2 = TextureRegion(46 * 7, 46 * 1, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion greenCreepTwoSource3 = TextureRegion(46 * 8, 46 * 1, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion greenCreepTwoSource4 = TextureRegion(46 * 9, 46 * 1, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        greenCreepTwoSources.push_back(greenCreepTwoSource1);
        greenCreepTwoSources.push_back(greenCreepTwoSource2);
        greenCreepTwoSources.push_back(greenCreepTwoSource3);
        greenCreepTwoSources.push_back(greenCreepTwoSource4);
    }
    
    static std::vector<TextureRegion> greenCreepThreeSources;
    if(greenCreepThreeSources.size() == 0)
    {
        static TextureRegion greenCreepThreeSource1 = TextureRegion(46 * 0, 46 * 5, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion greenCreepThreeSource2 = TextureRegion(46 * 1, 46 * 5, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion greenCreepThreeSource3 = TextureRegion(46 * 2, 46 * 5, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion greenCreepThreeSource4 = TextureRegion(46 * 3, 46 * 5, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        greenCreepThreeSources.push_back(greenCreepThreeSource1);
        greenCreepThreeSources.push_back(greenCreepThreeSource2);
        greenCreepThreeSources.push_back(greenCreepThreeSource3);
        greenCreepThreeSources.push_back(greenCreepThreeSource4);
    }
    
    static std::vector<TextureRegion> yellowCreepOneSources;
    if(yellowCreepOneSources.size() == 0)
    {
        static TextureRegion yellowCreepOneSource1 = TextureRegion(46 * 0, 46 * 3, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion yellowCreepOneSource2 = TextureRegion(46 * 1, 46 * 3, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion yellowCreepOneSource3 = TextureRegion(46 * 2, 46 * 3, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion yellowCreepOneSource4 = TextureRegion(46 * 3, 46 * 3, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion yellowCreepOneSource5 = TextureRegion(46 * 4, 46 * 3, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion yellowCreepOneSource6 = TextureRegion(46 * 5, 46 * 3, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        yellowCreepOneSources.push_back(yellowCreepOneSource1);
        yellowCreepOneSources.push_back(yellowCreepOneSource2);
        yellowCreepOneSources.push_back(yellowCreepOneSource3);
        yellowCreepOneSources.push_back(yellowCreepOneSource4);
        yellowCreepOneSources.push_back(yellowCreepOneSource5);
        yellowCreepOneSources.push_back(yellowCreepOneSource6);
    }
    
    static std::vector<TextureRegion> yellowCreepTwoSources;
    if(yellowCreepTwoSources.size() == 0)
    {
        static TextureRegion yellowCreepTwoSource1 = TextureRegion(46 * 6, 46 * 3, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion yellowCreepTwoSource2 = TextureRegion(46 * 7, 46 * 3, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion yellowCreepTwoSource3 = TextureRegion(46 * 8, 46 * 3, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion yellowCreepTwoSource4 = TextureRegion(46 * 9, 46 * 3, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        yellowCreepTwoSources.push_back(yellowCreepTwoSource1);
        yellowCreepTwoSources.push_back(yellowCreepTwoSource2);
        yellowCreepTwoSources.push_back(yellowCreepTwoSource3);
        yellowCreepTwoSources.push_back(yellowCreepTwoSource4);
    }
    
    static std::vector<TextureRegion> yellowCreepThreeSources;
    if(yellowCreepThreeSources.size() == 0)
    {
        static TextureRegion yellowCreepThreeSource1 = TextureRegion(46 * 0, 46 * 7, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion yellowCreepThreeSource2 = TextureRegion(46 * 1, 46 * 7, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion yellowCreepThreeSource3 = TextureRegion(46 * 2, 46 * 7, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion yellowCreepThreeSource4 = TextureRegion(46 * 3, 46 * 7, 46, 46, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        yellowCreepThreeSources.push_back(yellowCreepThreeSource1);
        yellowCreepThreeSources.push_back(yellowCreepThreeSource2);
        yellowCreepThreeSources.push_back(yellowCreepThreeSource3);
        yellowCreepThreeSources.push_back(yellowCreepThreeSource4);
    }
    
    static std::vector<TextureRegion> bossCreepSources;
    if(bossCreepSources.size() == 0)
    {
        static TextureRegion bossCreepSource1 = TextureRegion(0, 380, 64, 64, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion bossCreepSource2 = TextureRegion(68, 380, 64, 64, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion bossCreepSource3 = TextureRegion(136, 380, 64, 64, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        static TextureRegion bossCreepSource4 = TextureRegion(204, 380, 64, 64, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        
        bossCreepSources.push_back(bossCreepSource1);
        bossCreepSources.push_back(bossCreepSource2);
        bossCreepSources.push_back(bossCreepSource3);
        bossCreepSources.push_back(bossCreepSource4);
    }
    
    static float creep1CycleTime = 2.6f;
    static std::vector<float> creep1Frames;
    if(creep1Frames.size() == 0)
    {
        creep1Frames.push_back(1.0f);
        creep1Frames.push_back(0.2f);
        creep1Frames.push_back(0.1f);
        creep1Frames.push_back(1.0f);
        creep1Frames.push_back(0.1f);
        creep1Frames.push_back(0.2f);
    }
    
    static float creep2CycleTime = 2.0f;
    static std::vector<float> creep2Frames;
    if(creep2Frames.size() == 0)
    {
        creep2Frames.push_back(0.2f);
        creep2Frames.push_back(1.0f);
        creep2Frames.push_back(0.2f);
        creep2Frames.push_back(0.6f);
    }
    
    static float creep3CycleTime = 1.6f;
    static std::vector<float> creep3Frames;
    if(creep3Frames.size() == 0)
    {
        creep3Frames.push_back(1.0f);
        creep3Frames.push_back(0.2f);
        creep3Frames.push_back(0.2f);
        creep3Frames.push_back(0.2f);
    }
    
    static float bossCreepCycleTime = 2.0f;
    static std::vector<float> bossCreepFrames;
    if(bossCreepFrames.size() == 0)
    {
        bossCreepFrames.push_back(0.25f);
        bossCreepFrames.push_back(0.25f);
        bossCreepFrames.push_back(0.5f);
        bossCreepFrames.push_back(1.0f);
    }
    
    if(initOnly)
    {
        static TextureRegion DUMMMY = TextureRegion(0, 0, 0, 0, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
        return DUMMMY;
    }
    
    switch(creep.getCreepType())
    {
        case BLUE_CREEP_ONE:
            return blueCreepOneSources.at(getKeyFrameNumber(creep.getStateTime(), creep1CycleTime, creep1Frames));
        case BLUE_CREEP_TWO:
            return blueCreepTwoSources.at(getKeyFrameNumber(creep.getStateTime(), creep2CycleTime, creep2Frames));
        case BLUE_CREEP_THREE:
            return blueCreepThreeSources.at(getKeyFrameNumber(creep.getStateTime(), creep3CycleTime, creep3Frames));
        case RED_CREEP_ONE:
            return redCreepOneSources.at(getKeyFrameNumber(creep.getStateTime(), creep1CycleTime, creep1Frames));
        case RED_CREEP_TWO:
            return redCreepTwoSources.at(getKeyFrameNumber(creep.getStateTime(), creep2CycleTime, creep2Frames));
        case RED_CREEP_THREE:
            return redCreepThreeSources.at(getKeyFrameNumber(creep.getStateTime(), creep3CycleTime, creep3Frames));
        case GREEN_CREEP_ONE:
            return greenCreepOneSources.at(getKeyFrameNumber(creep.getStateTime(), creep1CycleTime, creep1Frames));
        case GREEN_CREEP_TWO:
            return greenCreepTwoSources.at(getKeyFrameNumber(creep.getStateTime(), creep2CycleTime, creep2Frames));
        case GREEN_CREEP_THREE:
            return greenCreepThreeSources.at(getKeyFrameNumber(creep.getStateTime(), creep3CycleTime, creep3Frames));
        case YELLOW_CREEP_ONE:
            return yellowCreepOneSources.at(getKeyFrameNumber(creep.getStateTime(), creep1CycleTime, creep1Frames));
        case YELLOW_CREEP_TWO:
            return yellowCreepTwoSources.at(getKeyFrameNumber(creep.getStateTime(), creep2CycleTime, creep2Frames));
        case YELLOW_CREEP_THREE:
            return yellowCreepThreeSources.at(getKeyFrameNumber(creep.getStateTime(), creep3CycleTime, creep3Frames));
        default:
            return bossCreepSources.at(getKeyFrameNumber(creep.getStateTime(), bossCreepCycleTime, bossCreepFrames));
    }
}

TextureRegion& Assets::getCreepHealthBarSource(Creep &creep)
{
    static TextureRegion creepHealthBarSource1 = TextureRegion(312, 190, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource2 = TextureRegion(312, 210, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource3 = TextureRegion(312, 230, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource4 = TextureRegion(312, 250, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource5 = TextureRegion(312, 270, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource6 = TextureRegion(312, 290, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource7 = TextureRegion(312, 310, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource8 = TextureRegion(312, 330, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource9 = TextureRegion(312, 350, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource10 = TextureRegion(312, 370, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource11 = TextureRegion(312, 390, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource12 = TextureRegion(312, 410, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource13 = TextureRegion(312, 430, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource14 = TextureRegion(312, 450, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource15 = TextureRegion(312, 470, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    static TextureRegion creepHealthBarSource16 = TextureRegion(312, 490, 200, 20, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512);
    
    switch(creep.getHealthBarFrame())
    {
        case 0:
            return creepHealthBarSource1;
        case 1:
            return creepHealthBarSource2;
        case 2:
            return creepHealthBarSource3;
        case 3:
            return creepHealthBarSource4;
        case 4:
            return creepHealthBarSource5;
        case 5:
            return creepHealthBarSource6;
        case 6:
            return creepHealthBarSource7;
        case 7:
            return creepHealthBarSource8;
        case 8:
            return creepHealthBarSource9;
        case 9:
            return creepHealthBarSource10;
        case 10:
            return creepHealthBarSource11;
        case 11:
            return creepHealthBarSource12;
        case 12:
            return creepHealthBarSource13;
        case 13:
            return creepHealthBarSource14;
        case 14:
            return creepHealthBarSource15;
        case 15:
        default:
            return creepHealthBarSource16;
    }
}

TextureRegion& Assets::getCreepBodyPartSource(CreepBodyPart &creepBodyPart)
{
    static TextureRegion leftWingCreep1 = TextureRegion(5 * 46, 0 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion headCreep1 = TextureRegion(0 * 46, 0 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion rightWingCreep1 = TextureRegion(1 * 46, 3 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion tailCreep1 = TextureRegion(0 * 46, 3 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion lowerLeftWingBlueCreep1 = TextureRegion(6 * 46, 0 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreBlueCreep1 = TextureRegion(1 * 46, 0 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion lowerRightWingBlueCreep1 = TextureRegion(2 * 46, 3 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion lowerLeftWingGreenCreep1 = TextureRegion(7 * 46, 0 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreGreenCreep1 = TextureRegion(2 * 46, 0 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion lowerRightWingGreenCreep1 = TextureRegion(3 * 46, 3 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion lowerLeftWingRedCreep1 = TextureRegion(8 * 46, 0 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreRedCreep1 = TextureRegion(3 * 46, 0 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion lowerRightWingRedCreep1 = TextureRegion(4 * 46, 3 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion lowerLeftWingYellowCreep1 = TextureRegion(9 * 46, 0 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreYellowCreep1 = TextureRegion(4 * 46, 0 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion lowerRightWingYellowCreep1 = TextureRegion(5 * 46, 3 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion leftWingCreep2 = TextureRegion(5 * 46, 1 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion lowerLeftWingCreep2 = TextureRegion(7 * 46, 1 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion headCreep2 = TextureRegion(0 * 46, 1 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion rightWingCreep2 = TextureRegion(6 * 46, 1 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion lowerRightWingCreep2 = TextureRegion(8 * 46, 1 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion assBlueCreep2 = TextureRegion(1 * 46, 1 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion assGreenCreep2 = TextureRegion(2 * 46, 1 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion assRedCreep2 = TextureRegion(3 * 46, 1 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion assYellowCreep2 = TextureRegion(4 * 46, 1 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion leftArmCreep3 = TextureRegion(0 * 46, 4 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion headCreep3 = TextureRegion(0 * 46, 2 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion bodyCreep3 = TextureRegion(5 * 46, 2 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion rightArmCreep3 = TextureRegion(1 * 46, 4 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion leftChargeBlueCreep3 = TextureRegion(1 * 46, 2 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion rightChargeBlueCreep3 = TextureRegion(6 * 46, 2 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion leftChargeGreenCreep3 = TextureRegion(2 * 46, 2 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion rightChargeGreenCreep3 = TextureRegion(7 * 46, 2 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion leftChargeRedCreep3 = TextureRegion(3 * 46, 2 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion rightChargeRedCreep3 = TextureRegion(8 * 46, 2 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion leftChargeYellowCreep3 = TextureRegion(4 * 46, 2 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion rightChargeYellowCreep3 = TextureRegion(9 * 46, 2 * 46, 46, 46, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion leftUpperWingBossCreep = TextureRegion(640, 512, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion leftLowerWingBossCreep = TextureRegion(704, 512, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion leftTailBossCreep = TextureRegion(768, 512, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion coreBossCreep = TextureRegion(832, 512, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion headBossCreep = TextureRegion(640, 576, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion rightTailBossCreep = TextureRegion(704, 576, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion rightLowerWingBossCreep = TextureRegion(768, 576, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion rightUpperWingBossCreep = TextureRegion(832, 576, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    switch(creepBodyPart.getType())
    {
        case LEFT_WING_1:
            return leftWingCreep1;
        case HEAD_1:
            return headCreep1;
        case RIGHT_WING_1:
            return rightWingCreep1;
        case TAIL_1:
            return tailCreep1;
        case LOWER_LEFT_WING_BLUE_1:
            return lowerLeftWingBlueCreep1;
        case CORE_BLUE_1:
            return coreBlueCreep1;
        case LOWER_RIGHT_WING_BLUE_1:
            return lowerRightWingBlueCreep1;
        case LOWER_LEFT_WING_GREEN_1:
            return lowerLeftWingGreenCreep1;
        case CORE_GREEN_1:
            return coreGreenCreep1;
        case LOWER_RIGHT_WING_GREEN_1:
            return lowerRightWingGreenCreep1;
        case LOWER_LEFT_WING_RED_1:
            return lowerLeftWingRedCreep1;
        case CORE_RED_1:
            return coreRedCreep1;
        case LOWER_RIGHT_WING_RED_1:
            return lowerRightWingRedCreep1;
        case LOWER_LEFT_WING_YELLOW_1:
            return lowerLeftWingYellowCreep1;
        case CORE_YELLOW_1:
            return coreYellowCreep1;
        case LOWER_RIGHT_WING_YELLOW_1:
            return lowerRightWingYellowCreep1;
        case LEFT_WING_2:
            return leftWingCreep2;
        case LOWER_LEFT_WING_2:
            return lowerLeftWingCreep2;
        case HEAD_2:
            return headCreep2;
        case RIGHT_WING_2:
            return rightWingCreep2;
        case LOWER_RIGHT_WING_2:
            return lowerRightWingCreep2;
        case ASS_BLUE_2:
            return assBlueCreep2;
        case ASS_GREEN_2:
            return assGreenCreep2;
        case ASS_RED_2:
            return assRedCreep2;
        case ASS_YELLOW_2:
            return assYellowCreep2;
        case LEFT_ARM_3:
            return leftArmCreep3;
        case HEAD_3:
            return headCreep3;
        case BODY_3:
            return bodyCreep3;
        case RIGHT_ARM_3:
            return rightArmCreep3;
        case LEFT_CHARGE_BLUE_3:
            return leftChargeBlueCreep3;
        case RIGHT_CHARGE_BLUE_3:
            return rightChargeBlueCreep3;
        case LEFT_CHARGE_GREEN_3:
            return leftChargeGreenCreep3;
        case RIGHT_CHARGE_GREEN_3:
            return rightChargeGreenCreep3;
        case LEFT_CHARGE_RED_3:
            return leftChargeRedCreep3;
        case RIGHT_CHARGE_RED_3:
            return rightChargeRedCreep3;
        case LEFT_CHARGE_YELLOW_3:
            return leftChargeYellowCreep3;
        case RIGHT_CHARGE_YELLOW_3:
            return rightChargeYellowCreep3;
        case LEFT_UPPER_WING_BOSS:
            return leftUpperWingBossCreep;
        case LEFT_LOWER_WING_BOSS:
            return leftLowerWingBossCreep;
        case LEFT_TAIL_BOSS:
            return leftTailBossCreep;
        case CORE_BOSS:
            return coreBossCreep;
        case HEAD_BOSS:
            return headBossCreep;
        case RIGHT_TAIL_BOSS:
            return rightTailBossCreep;
        case RIGHT_LOWER_WING_BOSS:
            return rightLowerWingBossCreep;
        case RIGHT_UPPER_WING_BOSS:
        default:
            return rightUpperWingBossCreep;
    }
}

TextureRegion& Assets::getTowerSource(Tower &tower)
{
    return getTowerSource(tower.getTowerType(), tower.getStage());
}

TextureRegion& Assets::getTowerSource(Tower_Type towerType, int towerStage)
{
    static TextureRegion projectileTowerStageOneSource = TextureRegion(40 * 0, 432, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion projectileTowerStageTwoSource = TextureRegion(40 * 0, 392, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion projectileTowerStageThreeSource = TextureRegion(40 * 0, 352, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion electricTowerStageOneSource = TextureRegion(40 * 3, 432, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion electricTowerStageTwoSource = TextureRegion(40 * 3, 392, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion electricTowerStageThreeSource = TextureRegion(40 * 3, 352, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion lazerTowerStageOneSource = TextureRegion(40 * 1, 432, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion lazerTowerStageTwoSource = TextureRegion(40 * 1, 392, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion lazerTowerStageThreeSource = TextureRegion(40 * 1, 352, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion iceTowerStageOneSource = TextureRegion(40 * 5, 432, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion iceTowerStageTwoSource = TextureRegion(40 * 5, 392, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion iceTowerStageThreeSource = TextureRegion(40 * 5, 352, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion missileTowerStageOneSource = TextureRegion(40 * 2, 432, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion missileTowerStageTwoSource = TextureRegion(40 * 2, 392, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion missileTowerStageThreeSource = TextureRegion(40 * 2, 352, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion fireTowerStageOneSource = TextureRegion(40 * 6, 432, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion fireTowerStageTwoSource = TextureRegion(40 * 6, 392, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion fireTowerStageThreeSource = TextureRegion(40 * 6, 352, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    static TextureRegion poisonTowerStageOneSource = TextureRegion(40 * 4, 432, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion poisonTowerStageTwoSource = TextureRegion(40 * 4, 392, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    static TextureRegion poisonTowerStageThreeSource = TextureRegion(40 * 4, 352, 40, 40, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
    
    switch(towerType)
    {
        case PROJECTILE_TYPE:
            switch(towerStage)
        {
            case 0:
                return projectileTowerStageOneSource;
            case 1:
                return projectileTowerStageTwoSource;
            default:
                return projectileTowerStageThreeSource;
        }
        case ELECTRIC_TYPE:
            switch(towerStage)
        {
            case 0:
                return electricTowerStageOneSource;
            case 1:
                return electricTowerStageTwoSource;
            default:
                return electricTowerStageThreeSource;
        }
        case LAZER_TYPE:
            switch(towerStage)
        {
            case 0:
                return lazerTowerStageOneSource;
            case 1:
                return lazerTowerStageTwoSource;
            default:
                return lazerTowerStageThreeSource;
        }
        case ICE_TYPE:
            switch(towerStage)
        {
            case 0:
                return iceTowerStageOneSource;
            case 1:
                return iceTowerStageTwoSource;
            default:
                return iceTowerStageThreeSource;
        }
        case MISSILE_TYPE:
            switch(towerStage)
        {
            case 0:
                return missileTowerStageOneSource;
            case 1:
                return missileTowerStageTwoSource;
            default:
                return missileTowerStageThreeSource;
        }
        case FIRE_TYPE:
            switch(towerStage)
        {
            case 0:
                return fireTowerStageOneSource;
            case 1:
                return fireTowerStageTwoSource;
            default:
                return fireTowerStageThreeSource;
        }
        case POISON_TYPE:
        default:
            switch(towerStage)
        {
            case 0:
                return poisonTowerStageOneSource;
            case 1:
                return poisonTowerStageTwoSource;
            default:
                return poisonTowerStageThreeSource;
        }
    }
}

TextureRegion& Assets::getProjectileSource(Projectile &projectile)
{
    static std::vector<TextureRegion> blueProjectileSources;
    if(blueProjectileSources.size() == 0)
    {
        static TextureRegion blueProjectileSource1 = TextureRegion(0, 316, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion blueProjectileSource2 = TextureRegion(16, 316, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion blueProjectileSource3 = TextureRegion(32, 316, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion blueProjectileSource4 = TextureRegion(48, 316, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        blueProjectileSources.push_back(blueProjectileSource1);
        blueProjectileSources.push_back(blueProjectileSource2);
        blueProjectileSources.push_back(blueProjectileSource3);
        blueProjectileSources.push_back(blueProjectileSource4);
    }
    
    static std::vector<TextureRegion> yellowProjectileSources;
    if(yellowProjectileSources.size() == 0)
    {
        static TextureRegion yellowProjectileSource1 = TextureRegion(0, 298, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion yellowProjectileSource2 = TextureRegion(16, 298, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion yellowProjectileSource3 = TextureRegion(32, 298, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion yellowProjectileSource4 = TextureRegion(48, 298, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        yellowProjectileSources.push_back(yellowProjectileSource1);
        yellowProjectileSources.push_back(yellowProjectileSource2);
        yellowProjectileSources.push_back(yellowProjectileSource3);
        yellowProjectileSources.push_back(yellowProjectileSource4);
    }
    
    static float projectileCycleTime = 0.60f;
    static std::vector<float> projectileFrames;
    if(projectileFrames.size() == 0)
    {
        projectileFrames.push_back(0.15f);
        projectileFrames.push_back(0.15f);
        projectileFrames.push_back(0.15f);
        projectileFrames.push_back(0.15f);
    }
    
    if(projectile.getProjectileState() == Projectile_State::GLOWING)
    {
        return yellowProjectileSources.at(getKeyFrameNumber(projectile.getStateTime(), projectileCycleTime, projectileFrames));
    }
    else
    {
        return blueProjectileSources.at(getKeyFrameNumber(projectile.getStateTime(), projectileCycleTime, projectileFrames));
    }
}

TextureRegion& Assets::getProjectileParticleSource(ProjectileParticle &projectileParticle)
{
    static std::vector<TextureRegion> yellowProjectileSources;
    if(yellowProjectileSources.size() == 0)
    {
        static TextureRegion yellowProjectileSource1 = TextureRegion(0, 298, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion yellowProjectileSource2 = TextureRegion(16, 298, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion yellowProjectileSource3 = TextureRegion(32, 298, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion yellowProjectileSource4 = TextureRegion(48, 298, 16, 16, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        yellowProjectileSources.push_back(yellowProjectileSource1);
        yellowProjectileSources.push_back(yellowProjectileSource2);
        yellowProjectileSources.push_back(yellowProjectileSource3);
        yellowProjectileSources.push_back(yellowProjectileSource4);
    }
    
    static float projectileCycleTime = 0.60f;
    static std::vector<float> projectileFrames;
    if(projectileFrames.size() == 0)
    {
        projectileFrames.push_back(0.15f);
        projectileFrames.push_back(0.15f);
        projectileFrames.push_back(0.15f);
        projectileFrames.push_back(0.15f);
    }
    
    return yellowProjectileSources.at(getKeyFrameNumber(projectileParticle.getStateTime(), projectileCycleTime, projectileFrames));
}

TextureRegion& Assets::getElectricBoltSource(ElectricBolt &electricBolt)
{
    static std::vector<TextureRegion> electricBoltSources;
    if(electricBoltSources.size() == 0)
    {
        static TextureRegion electricBoltSource1 = TextureRegion(0, 164, 119, 22, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion electricBoltSource2 = TextureRegion(0, 186, 119, 22, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion electricBoltSource3 = TextureRegion(0, 208, 119, 22, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion electricBoltSource4 = TextureRegion(0, 230, 119, 22, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        electricBoltSources.push_back(electricBoltSource1);
        electricBoltSources.push_back(electricBoltSource2);
        electricBoltSources.push_back(electricBoltSource3);
        electricBoltSources.push_back(electricBoltSource4);
    }
    
    static float electricBoltCycleTime = 0.20f;
    static std::vector<float> electricBoltFrames;
    if(electricBoltFrames.size() == 0)
    {
        electricBoltFrames.push_back(0.05f);
        electricBoltFrames.push_back(0.05f);
        electricBoltFrames.push_back(0.05f);
        electricBoltFrames.push_back(0.05f);
    }
    
    return electricBoltSources.at(getKeyFrameNumber(electricBolt.getStateTime(), electricBoltCycleTime, electricBoltFrames));
}

TextureRegion& Assets::getIceBlastSource(IceBlast &iceBlast)
{
    static std::vector<TextureRegion> iceBlastSources;
    if(iceBlastSources.size() == 0)
    {
        static TextureRegion iceBlastSource1 = TextureRegion(  0, 512, 256, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion iceBlastSource2 = TextureRegion(256, 512, 256, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion iceBlastSource3 = TextureRegion(512, 512, 256, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion iceBlastSource4 = TextureRegion(  0, 640, 256, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion iceBlastSource5 = TextureRegion(256, 640, 256, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion iceBlastSource6 = TextureRegion(512, 640, 256, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        iceBlastSources.push_back(iceBlastSource1);
        iceBlastSources.push_back(iceBlastSource2);
        iceBlastSources.push_back(iceBlastSource3);
        iceBlastSources.push_back(iceBlastSource4);
        iceBlastSources.push_back(iceBlastSource5);
        iceBlastSources.push_back(iceBlastSource6);
    }
    
    static float iceBlastCycleTime = 0.72f;
    static std::vector<float> iceBlastFrames;
    if(iceBlastFrames.size() == 0)
    {
        iceBlastFrames.push_back(0.12f);
        iceBlastFrames.push_back(0.12f);
        iceBlastFrames.push_back(0.12f);
        iceBlastFrames.push_back(0.12f);
        iceBlastFrames.push_back(0.12f);
        iceBlastFrames.push_back(0.12f);
    }
    
    return iceBlastSources.at(getKeyFrameNumber(iceBlast.getStateTime(), iceBlastCycleTime, iceBlastFrames));
}

TextureRegion& Assets::getExplosionSource(Explosion &explosion)
{
    static std::vector<TextureRegion> miniExplosionSources;
    if(miniExplosionSources.size() == 0)
    {
        static TextureRegion miniExplosionSource1 = TextureRegion(0, 640, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource2 = TextureRegion(128, 640, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource3 = TextureRegion(256, 640, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource4 = TextureRegion(384, 640, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource5 = TextureRegion(512, 640, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource6 = TextureRegion(640, 640, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource7 = TextureRegion(768, 640, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource8 = TextureRegion(896, 640, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource9 = TextureRegion(0, 768, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource10 = TextureRegion(128, 768, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource11 = TextureRegion(256, 768, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource12 = TextureRegion(384, 768, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource13 = TextureRegion(512, 768, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource14 = TextureRegion(640, 768, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource15 = TextureRegion(768, 768, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource16 = TextureRegion(896, 768, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion miniExplosionSource17 = TextureRegion(0, 896, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        miniExplosionSources.push_back(miniExplosionSource1);
        miniExplosionSources.push_back(miniExplosionSource2);
        miniExplosionSources.push_back(miniExplosionSource3);
        miniExplosionSources.push_back(miniExplosionSource4);
        miniExplosionSources.push_back(miniExplosionSource5);
        miniExplosionSources.push_back(miniExplosionSource6);
        miniExplosionSources.push_back(miniExplosionSource7);
        miniExplosionSources.push_back(miniExplosionSource8);
        miniExplosionSources.push_back(miniExplosionSource9);
        miniExplosionSources.push_back(miniExplosionSource10);
        miniExplosionSources.push_back(miniExplosionSource11);
        miniExplosionSources.push_back(miniExplosionSource12);
        miniExplosionSources.push_back(miniExplosionSource13);
        miniExplosionSources.push_back(miniExplosionSource14);
        miniExplosionSources.push_back(miniExplosionSource15);
        miniExplosionSources.push_back(miniExplosionSource16);
        miniExplosionSources.push_back(miniExplosionSource17);
    }
    
    static float miniExplosionCycleTime = 0.85f;
    static std::vector<float> miniExplosionFrames;
    if(miniExplosionFrames.size() == 0)
    {
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
        miniExplosionFrames.push_back(0.05f);
    }
    
    static std::vector<TextureRegion> bigExplosionSources;
    if(bigExplosionSources.size() == 0)
    {
        static TextureRegion bigExplosionSource1 = TextureRegion(512, 0, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource2 = TextureRegion(640, 0, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource3 = TextureRegion(768, 0, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource4 = TextureRegion(896, 0, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource5 = TextureRegion(512, 128, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource6 = TextureRegion(640, 128, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource7 = TextureRegion(768, 128, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource8 = TextureRegion(896, 128, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource9 = TextureRegion(512, 256, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource10 = TextureRegion(640, 256, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource11 = TextureRegion(768, 256, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource12 = TextureRegion(896, 256, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource13 = TextureRegion(512, 384, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource14 = TextureRegion(640, 384, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource15 = TextureRegion(768, 384, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource16 = TextureRegion(896, 384, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion bigExplosionSource17 = TextureRegion(512, 512, 128, 128, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        bigExplosionSources.push_back(bigExplosionSource1);
        bigExplosionSources.push_back(bigExplosionSource2);
        bigExplosionSources.push_back(bigExplosionSource3);
        bigExplosionSources.push_back(bigExplosionSource4);
        bigExplosionSources.push_back(bigExplosionSource5);
        bigExplosionSources.push_back(bigExplosionSource6);
        bigExplosionSources.push_back(bigExplosionSource7);
        bigExplosionSources.push_back(bigExplosionSource8);
        bigExplosionSources.push_back(bigExplosionSource9);
        bigExplosionSources.push_back(bigExplosionSource10);
        bigExplosionSources.push_back(bigExplosionSource11);
        bigExplosionSources.push_back(bigExplosionSource12);
        bigExplosionSources.push_back(bigExplosionSource13);
        bigExplosionSources.push_back(bigExplosionSource14);
        bigExplosionSources.push_back(bigExplosionSource15);
        bigExplosionSources.push_back(bigExplosionSource16);
        bigExplosionSources.push_back(bigExplosionSource17);
    }
    
    static float bigExplosionCycleTime = 1.02f;
    static std::vector<float> bigExplosionFrames;
    if(bigExplosionFrames.size() == 0)
    {
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
        bigExplosionFrames.push_back(0.06f);
    }
    
    static std::vector<TextureRegion> deathExplosionSources;
    if(deathExplosionSources.size() == 0)
    {
        static TextureRegion deathExplosionSource1 = TextureRegion(0, 240, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource2 = TextureRegion(79, 240, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource3 = TextureRegion(158, 240, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource4 = TextureRegion(237, 240, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource5 = TextureRegion(316, 240, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource6 = TextureRegion(395, 240, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource7 = TextureRegion(0, 327, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource8 = TextureRegion(79, 327, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource9 = TextureRegion(158, 327, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource10 = TextureRegion(237, 327, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource11 = TextureRegion(316, 327, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource12 = TextureRegion(395, 327, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource13 = TextureRegion(0, 414, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource14 = TextureRegion(79, 414, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource15 = TextureRegion(158, 414, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource16 = TextureRegion(237, 414, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource17 = TextureRegion(316, 414, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource18 = TextureRegion(395, 414, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource19 = TextureRegion(0, 501, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource20 = TextureRegion(79, 501, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource21 = TextureRegion(158, 501, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource22 = TextureRegion(237, 501, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource23 = TextureRegion(316, 501, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion deathExplosionSource24 = TextureRegion(395, 501, 79, 87, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        deathExplosionSources.push_back(deathExplosionSource1);
        deathExplosionSources.push_back(deathExplosionSource2);
        deathExplosionSources.push_back(deathExplosionSource3);
        deathExplosionSources.push_back(deathExplosionSource4);
        deathExplosionSources.push_back(deathExplosionSource5);
        deathExplosionSources.push_back(deathExplosionSource6);
        deathExplosionSources.push_back(deathExplosionSource7);
        deathExplosionSources.push_back(deathExplosionSource8);
        deathExplosionSources.push_back(deathExplosionSource9);
        deathExplosionSources.push_back(deathExplosionSource10);
        deathExplosionSources.push_back(deathExplosionSource11);
        deathExplosionSources.push_back(deathExplosionSource12);
        deathExplosionSources.push_back(deathExplosionSource13);
        deathExplosionSources.push_back(deathExplosionSource14);
        deathExplosionSources.push_back(deathExplosionSource15);
        deathExplosionSources.push_back(deathExplosionSource16);
        deathExplosionSources.push_back(deathExplosionSource17);
        deathExplosionSources.push_back(deathExplosionSource18);
        deathExplosionSources.push_back(deathExplosionSource19);
        deathExplosionSources.push_back(deathExplosionSource20);
        deathExplosionSources.push_back(deathExplosionSource21);
        deathExplosionSources.push_back(deathExplosionSource22);
        deathExplosionSources.push_back(deathExplosionSource23);
        deathExplosionSources.push_back(deathExplosionSource24);
    }
    
    static float deathExplosionCycleTime = 1.2f;
    static std::vector<float> deathExplosionFrames;
    if(deathExplosionFrames.size() == 0)
    {
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
        deathExplosionFrames.push_back(0.05f);
    }
    
    switch(explosion.getType())
    {
        case MINI_DAMAGE:
            return miniExplosionSources.at(getKeyFrameNumber(explosion.getStateTime(), miniExplosionCycleTime, miniExplosionFrames));
        case BIG_DAMAGE:
            return bigExplosionSources.at(getKeyFrameNumber(explosion.getStateTime(), bigExplosionCycleTime, bigExplosionFrames));
        case CREEP_DEATH:
        default:
            return deathExplosionSources.at(getKeyFrameNumber(explosion.getStateTime(), deathExplosionCycleTime, deathExplosionFrames));
    }
}

TextureRegion& Assets::getMissileSource(Missile &missile)
{
    static std::vector<TextureRegion> missileSources;
    if(missileSources.size() == 0)
    {
        static TextureRegion missileSource1 = TextureRegion(848, 0, 176, 25, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion missileSource2 = TextureRegion(848, 25, 176, 25, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion missileSource3 = TextureRegion(848, 50, 176, 25, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion missileSource4 = TextureRegion(848, 75, 176, 25, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        missileSources.push_back(missileSource1);
        missileSources.push_back(missileSource2);
        missileSources.push_back(missileSource3);
        missileSources.push_back(missileSource4);
    }
    
    static float missileCycleTime = 0.20f;
    static std::vector<float> missileFrames;
    if(missileFrames.size() == 0)
    {
        missileFrames.push_back(0.05f);
        missileFrames.push_back(0.05f);
        missileFrames.push_back(0.05f);
        missileFrames.push_back(0.05f);
    }
    
    return missileSources.at(getKeyFrameNumber(missile.getStateTime(), missileCycleTime, missileFrames));
}

TextureRegion& Assets::getFireBoltSource(FireBolt &fireBolt)
{
    static std::vector<TextureRegion> fireBoltSources;
    if(fireBoltSources.size() == 0)
    {
        static TextureRegion fireBoltSource1 = TextureRegion(512, 260, 64, 21, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion fireBoltSource2 = TextureRegion(576, 260, 64, 21, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion fireBoltSource3 = TextureRegion(640, 260, 64, 21, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion fireBoltSource4 = TextureRegion(704, 260, 64, 21, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion fireBoltSource5 = TextureRegion(768, 260, 64, 21, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion fireBoltSource6 = TextureRegion(832, 260, 64, 21, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion fireBoltSource7 = TextureRegion(896, 260, 64, 21, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion fireBoltSource8 = TextureRegion(960, 260, 64, 21, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        fireBoltSources.push_back(fireBoltSource1);
        fireBoltSources.push_back(fireBoltSource2);
        fireBoltSources.push_back(fireBoltSource3);
        fireBoltSources.push_back(fireBoltSource4);
        fireBoltSources.push_back(fireBoltSource5);
        fireBoltSources.push_back(fireBoltSource6);
        fireBoltSources.push_back(fireBoltSource7);
        fireBoltSources.push_back(fireBoltSource8);
    }
    
    static float fireBoltCycleTime = 0.48f;
    static std::vector<float> fireBoltFrames;
    if(fireBoltFrames.size() == 0)
    {
        fireBoltFrames.push_back(0.06f);
        fireBoltFrames.push_back(0.06f);
        fireBoltFrames.push_back(0.06f);
        fireBoltFrames.push_back(0.06f);
        fireBoltFrames.push_back(0.06f);
        fireBoltFrames.push_back(0.06f);
        fireBoltFrames.push_back(0.06f);
        fireBoltFrames.push_back(0.06f);
    }
    
    static std::vector<TextureRegion> burningSources;
    if(burningSources.size() == 0)
    {
        static TextureRegion burningSource1 = TextureRegion(0, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource2 = TextureRegion(64, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource3 = TextureRegion(128, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource4 = TextureRegion(192, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource5 = TextureRegion(256, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource6 = TextureRegion(320, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource7 = TextureRegion(384, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource8 = TextureRegion(448, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource9 = TextureRegion(512, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource10 = TextureRegion(576, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource11 = TextureRegion(640, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource12 = TextureRegion(704, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource13 = TextureRegion(764, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource14 = TextureRegion(828, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource15 = TextureRegion(892, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource16 = TextureRegion(956, 768, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource17 = TextureRegion(0, 832, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource18 = TextureRegion(64, 832, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource19 = TextureRegion(128, 832, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource20 = TextureRegion(192, 832, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource21 = TextureRegion(256, 832, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource22 = TextureRegion(320, 832, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource23 = TextureRegion(384, 832, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource24 = TextureRegion(448, 832, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion burningSource25 = TextureRegion(512, 832, 64, 64, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        burningSources.push_back(burningSource1);
        burningSources.push_back(burningSource2);
        burningSources.push_back(burningSource3);
        burningSources.push_back(burningSource4);
        burningSources.push_back(burningSource5);
        burningSources.push_back(burningSource6);
        burningSources.push_back(burningSource7);
        burningSources.push_back(burningSource8);
        burningSources.push_back(burningSource9);
        burningSources.push_back(burningSource10);
        burningSources.push_back(burningSource11);
        burningSources.push_back(burningSource12);
        burningSources.push_back(burningSource13);
        burningSources.push_back(burningSource14);
        burningSources.push_back(burningSource15);
        burningSources.push_back(burningSource16);
        burningSources.push_back(burningSource17);
        burningSources.push_back(burningSource18);
        burningSources.push_back(burningSource19);
        burningSources.push_back(burningSource20);
        burningSources.push_back(burningSource21);
        burningSources.push_back(burningSource22);
        burningSources.push_back(burningSource23);
        burningSources.push_back(burningSource24);
        burningSources.push_back(burningSource25);
    }
    
    static float burningCycleTime = 1.25f;
    static std::vector<float> burningFrames;
    if(burningFrames.size() == 0)
    {
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
        burningFrames.push_back(0.05f);
    }
    
    if(fireBolt.getFireBoltState() == LAUNCHED)
    {
        return fireBoltSources.at(getKeyFrameNumber(fireBolt.getStateTime(), fireBoltCycleTime, fireBoltFrames));
    }
    else
    {
        return burningSources.at(getKeyFrameNumber(fireBolt.getStateTime(), burningCycleTime, burningFrames));
    }
}

TextureRegion& Assets::getAcidDropSource(AcidDrop &acidDrop)
{
    static std::vector<TextureRegion> acidDropSources;
    if(acidDropSources.size() == 0)
    {
        static TextureRegion acidDropSource1 = TextureRegion(516, 0, 46, 33, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion acidDropSource2 = TextureRegion(516, 37, 46, 33, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion acidDropSource3 = TextureRegion(516, 74, 46, 33, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion acidDropSource4 = TextureRegion(516, 111, 46, 33, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion acidDropSource5 = TextureRegion(516, 148, 46, 33, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion acidDropSource6 = TextureRegion(516, 185, 46, 33, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        static TextureRegion acidDropSource7 = TextureRegion(516, 222, 46, 33, TEXTURE_SIZE_1024x1024, TEXTURE_SIZE_1024x1024);
        
        acidDropSources.push_back(acidDropSource1);
        acidDropSources.push_back(acidDropSource2);
        acidDropSources.push_back(acidDropSource3);
        acidDropSources.push_back(acidDropSource4);
        acidDropSources.push_back(acidDropSource5);
        acidDropSources.push_back(acidDropSource6);
        acidDropSources.push_back(acidDropSource7);
    }
    
    static float acidDropCycleTime = 0.36f;
    static std::vector<float> acidDropFrames;
    if(acidDropFrames.size() == 0)
    {
        acidDropFrames.push_back(0.04f);
        acidDropFrames.push_back(0.04f);
        acidDropFrames.push_back(0.04f);
        acidDropFrames.push_back(0.04f);
        acidDropFrames.push_back(0.04f);
        acidDropFrames.push_back(0.04f);
        acidDropFrames.push_back(0.12f);
    }
    
    return acidDropSources.at(getKeyFrameNumber(acidDrop.getStateTime(), acidDropCycleTime, acidDropFrames));
}

void Assets::setMusicId(short musicId)
{
    m_sMusicId = musicId;
}

short Assets::getMusicId()
{
    return m_sMusicId;
}

short Assets::getFirstSoundId()
{
    return m_sSoundIds.size() > 0 ? m_sSoundIds.front() : 0;
}

void Assets::addSoundIdToPlayQueue(short soundId)
{
    if (m_sSoundIds.size() < MAX_SOUNDS_TO_PLAY_PER_FRAME)
    {
        m_sSoundIds.push_back(soundId);
    }
}

void Assets::eraseFirstSoundId()
{
    if (m_sSoundIds.size() > 0)
    {
        m_sSoundIds.erase(m_sSoundIds.begin());
    }
}

int Assets::getKeyFrameNumber(float stateTime, float cycleTime, std::vector<float> &frameDurations)
{
    if (stateTime > cycleTime && cycleTime > 0)
    {
        while (stateTime > cycleTime)
        {
            stateTime -= cycleTime;
        }
    }

    for (unsigned int i = 0; i < frameDurations.size(); i++)
    {
        if (stateTime < frameDurations.at(i))
        {
            return i;
        }

        stateTime -= frameDurations.at(i);
    }

    return 0;
}

Assets::Assets()
{
    // Hide Constructor for Singleton
    static BossCreep tempBossCreep = BossCreep(0, 0, 0, 0, 0, false);
    Assets::getCreepSource(tempBossCreep, true);
}