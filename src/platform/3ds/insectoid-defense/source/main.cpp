//
//  main.cpp
//  tappyplane
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

#define TICKS_PER_SEC (268123480)

int main(int argc, char** argv)
{
    DSGameScreen gameScreen = DSGameScreen(0, 0, 400, 240, 320, 240);

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
                // TODO, play sound
                break;
            case SOUND_BEGIN_WAVE:
                // TODO, play sound
                break;
            case SOUND_CREEP_DEATH:
                // TODO, play sound
                break;
            case SOUND_DRAG_TOWER:
                // TODO, play sound
                break;
            case SOUND_ELECTRIC_BOLT:
                // TODO, play sound
                break;
            case SOUND_EXPLOSION:
                // TODO, play sound
                break;
            case SOUND_FIRE_BOLT:
                // TODO, play sound
                break;
            case SOUND_GOAL_HIT:
                // TODO, play sound
                break;
            case SOUND_ICE_BLAST:
                // TODO, play sound
                break;
            case SOUND_LAZER_BEAM:
                // TODO, play sound
                break;
            case SOUND_MISSILE_LAUNCH:
                // TODO, play sound
                break;
            case SOUND_PLACE_TOWER:
                // TODO, play sound
                break;
            case SOUND_PLASMA_BANG:
                // TODO, play sound
                break;
            case SOUND_SELL_TOWER:
                // TODO, play sound
                break;
            case SOUND_TOWER_UPGRADED:
                // TODO, play sound
                break;
            case SOUND_TOXIC_CLOUD:
                // TODO, play sound
                break;
            default:
                continue;
            }
        }

        // Handle any Music changes for this frame
        bool loadedNewTrack = false;
        short musicId = gameScreen.getCurrentMusicId();
        switch (musicId)
        {
        case MUSIC_STOP:
            // TODO, stop music
            break;
        case MUSIC_PLAY_MAP_SPACE:
            // TODO, play music
            loadedNewTrack = true;
            break;
        default:
            break;
        }

        if (loadedNewTrack)
        {
            // Set looping, volume if necessary, and play the track
        }
    }

    gameScreen.exit();

    return 0;
}