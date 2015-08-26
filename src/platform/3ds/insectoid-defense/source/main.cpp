//
//  main.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 8/20/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#include <string.h>

#include <3ds.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "DSGameScreen.h"
#include "Vector2D.h"
#include "TouchEvent.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "Assets.h"
#include "OverlapTester.h"
#include "Renderer.h"
#include "LineBatcher.h"
#include "RectangleBatcher.h"
#include "Triangle.h"
#include "Font.h"
#include "SpriteBatcher.h"
#include "LineBatcher.h"
#include "CircleBatcher.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ResourceConstants.h"
#include "BackgroundElements.h"
#include "TimeButton.h"
#include "Dialog.h"
#include "TouchCursor.h"
#include "Text.h"
#include "Asteroid.h"
#include "ShipModule.h"
#include "CoreShipModule.h"
#include "TowerCursor.h"
#include "TowerOptionButton.h"
#include "ScreenState.h"
#include "ResourceConstants.h"

extern "C"
{
#include "sfx.h"
#include "filesystem.h"
}

#define TICKS_PER_SEC (268123480)

int main(int argc, char** argv)
{
    filesystemInit(argc, argv);

    initSound();

    float totalTime = 0;

    SFX_s* acid_drop = createSFX("acid_drop.raw", SOUND_FORMAT_16BIT);
    SFX_s* begin_wave = createSFX("begin_wave.raw", SOUND_FORMAT_16BIT);
    SFX_s* bgm = createSFX("bgm.raw", SOUND_FORMAT_16BIT);
    SFX_s* creep_death = createSFX("creep_death.raw", SOUND_FORMAT_16BIT);
    SFX_s* drag_tower = createSFX("drag_tower.raw", SOUND_FORMAT_16BIT);
    SFX_s* electric_bolt = createSFX("electric_bolt.raw", SOUND_FORMAT_16BIT);
    SFX_s* explosion = createSFX("explosion.raw", SOUND_FORMAT_16BIT);
    SFX_s* fire_bolt = createSFX("fire_bolt.raw", SOUND_FORMAT_16BIT);
    SFX_s* goal_hit = createSFX("goal_hit.raw", SOUND_FORMAT_16BIT);
    SFX_s* ice_blast = createSFX("ice_blast.raw", SOUND_FORMAT_16BIT);
    SFX_s* lazer_beam = createSFX("lazer_beam.raw", SOUND_FORMAT_16BIT);
    SFX_s* missile_launch = createSFX("missile_launch.raw", SOUND_FORMAT_16BIT);
    SFX_s* place_tower = createSFX("place_tower.raw", SOUND_FORMAT_16BIT);
    SFX_s* plasma_bang = createSFX("plasma_bang.raw", SOUND_FORMAT_16BIT);
    SFX_s* sell_tower = createSFX("sell_tower.raw", SOUND_FORMAT_16BIT);
    SFX_s* tower_upgraded = createSFX("tower_upgraded.raw", SOUND_FORMAT_16BIT);
    SFX_s* toxic_cloud = createSFX("toxic_cloud.raw", SOUND_FORMAT_16BIT);

    DSGameScreen gameScreen = DSGameScreen(0, 0, 400, 240, 320, 240);

    gameScreen.onResume();

    u64 lastTick = svcGetSystemTick();

    touchPosition lastTouchPosition = {0, 0};

    // Main loop
    while (aptMainLoop())
    {
        u64 newTick = svcGetSystemTick();
        float deltaTime = ((float) (newTick - lastTick)) / TICKS_PER_SEC;
        lastTick = newTick;

        hidScanInput();

        touchPosition touch;

        //Read the touch screen coordinates
        hidTouchRead(&touch);

        if (lastTouchPosition.px == 0 && lastTouchPosition.py == 0)
        {
            if (touch.px != 0 && touch.py != 0)
            {
                gameScreen.onTouch(Touch_Type::DOWN, touch.px, touch.py);
            }
        }
        else
        {
            if (touch.px == 0 && touch.py == 0)
            {
                gameScreen.onTouch(Touch_Type::UP, lastTouchPosition.px, lastTouchPosition.py);
            }
            else
            {
                gameScreen.onTouch(Touch_Type::DRAGGED, touch.px, touch.py);
            }
        }

        lastTouchPosition.px = touch.px;
        lastTouchPosition.py = touch.py;

        u32 kDown = hidKeysDown();
        if (kDown & KEY_START)
        {
            gameScreen.onTouch(Touch_Type::UP, 25, 13); // Simulating a touch on the pause button
        }

        bool exit = false;
        int screenState = gameScreen.getState();
        switch (screenState)
        {
        case SCREEN_STATE_WAVE_COMPLETED:
            // Display a notification depending on # of waves completed
            gameScreen.clearState();
        case SCREEN_STATE_NORMAL:
            gameScreen.update(deltaTime);
            break;
        case SCREEN_STATE_GAME_OVER:
            // TODO, save score
            gameScreen.clearState();
            break;
        case SCREEN_STATE_EXIT:
            exit = true;
            break;
        default:
            break;
        }

        totalTime += deltaTime;

        if (exit)
        {
            break; // break in order to return to hbmenu
        }

        gameScreen.render();

        // Handle Sound for this frame
        short soundId;
        while ((soundId = gameScreen.getCurrentSoundId()) > 0)
        {
            switch (soundId)
            {
            case SOUND_ACID_DROP:
                playSFX(acid_drop);
                break;
            case SOUND_BEGIN_WAVE:
                playSFX(begin_wave);
                break;
            case SOUND_CREEP_DEATH:
                playSFX(creep_death);
                break;
            case SOUND_DRAG_TOWER:
                playSFX(drag_tower);
                break;
            case SOUND_ELECTRIC_BOLT:
                playSFX(electric_bolt);
                break;
            case SOUND_EXPLOSION:
                playSFX(explosion);
                break;
            case SOUND_FIRE_BOLT:
                playSFX(fire_bolt);
                break;
            case SOUND_GOAL_HIT:
                playSFX(goal_hit);
                break;
            case SOUND_ICE_BLAST:
                playSFX(ice_blast);
                break;
            case SOUND_LAZER_BEAM:
                playSFX(lazer_beam);
                break;
            case SOUND_MISSILE_LAUNCH:
                playSFX(missile_launch);
                break;
            case SOUND_PLACE_TOWER:
                playSFX(place_tower);
                break;
            case SOUND_PLASMA_BANG:
                playSFX(plasma_bang);
                break;
            case SOUND_SELL_TOWER:
                playSFX(sell_tower);
                break;
            case SOUND_TOWER_UPGRADED:
                playSFX(tower_upgraded);
                break;
            case SOUND_TOXIC_CLOUD:
                playSFX(toxic_cloud);
                break;
            default:
                continue;
            }
        }

        // Handle any Music changes for this frame
        short musicId = gameScreen.getCurrentMusicId();
        switch (musicId)
        {
        case MUSIC_STOP:
            // fixme: How do I stop music?
            break;
        case MUSIC_PLAY_MAP_SPACE:
            playMusic(bgm);
            totalTime = 0;
            break;
        default:
            break;
        }

        if (totalTime > 32)
        {
            playMusic(bgm);
            totalTime = 0;
        }
    }

    exitSound();

    gameScreen.exit();

    return 0;
}