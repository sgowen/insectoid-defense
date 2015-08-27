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
#include "SaveData.h"
#include "DifficultyLevel.h"

extern "C"
{
#include "sfx.h"
#include "filesystem.h"
}

#define TICKS_PER_SEC (268123480)

void saveScore(GameScreen &gameScreen)
{
    int score = gameScreen.getScore();
    int wave = gameScreen.getWave();
    int difficulty = gameScreen.getDifficulty();
    int levelIndex = gameScreen.getLevelIndex();

    SaveData::getInstance()->saveHighScore(score, wave, difficulty, levelIndex);
}

void runGame(int level, int difficulty)
{
    float totalMusicPlaybackTime = 0;

    initSound();

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

    DSGameScreen gameScreen = DSGameScreen(level, difficulty, 400, 240, 320, 240);

    gameScreen.onResume();

    u64 lastTick = svcGetSystemTick();

    touchPosition lastTouchPosition = {0, 0};

    // Game loop
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
            // TODO, display a notification depending on # of waves completed
            gameScreen.clearState();
        case SCREEN_STATE_NORMAL:
            gameScreen.update(deltaTime);
            break;
        case SCREEN_STATE_GAME_OVER:
            saveScore(gameScreen);
            gameScreen.clearState();
            break;
        case SCREEN_STATE_EXIT:
            exit = true;
            break;
        default:
            break;
        }

        totalMusicPlaybackTime += deltaTime;

        if (exit)
        {
            break; // break in order to return to the Level Select screens
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
            totalMusicPlaybackTime = 0;
            break;
        default:
            break;
        }

        if (totalMusicPlaybackTime > 32)
        {
            // Haha, looping background music!
            playMusic(bgm);
            totalMusicPlaybackTime = 0;
        }
    }

    exitSound();

    gameScreen.exit();
}

int main(int argc, char** argv)
{
    filesystemInit(argc, argv);

    SaveData::getInstance()->loadGame();

    // Initialize services
    gfxInitDefault();

    // Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
    consoleInit(GFX_BOTTOM, NULL);

    bool difficultyChosen = false;
    bool levelChosen = false;
    int difficulty = DIFFICULTY_LEVEL_NORMAL;
    int level = 0;

    // Main Menu loop
    while (aptMainLoop())
    {
        hidScanInput();

        u32 kDown = hidKeysDown();
        if (kDown & KEY_START)
        {
            break; // break in order to return to hbmenu
        }

        printf("\x1b[20;15HSelect a Difficulty using the D-Pad");

        switch (difficulty)
        {
        case DIFFICULTY_LEVEL_EASY:
            printf("\x1b[21;20HEASY");
            break;
        case DIFFICULTY_LEVEL_NORMAL:
            printf("\x1b[21;20HNORMAL");
            break;
        case DIFFICULTY_LEVEL_HARD:
            printf("\x1b[21;20HHARD");
            break;
        }

        if (difficultyChosen)
        {
            printf("\x1b[23;15HSelect a Level using the D-Pad");

            switch (level)
            {
            case 0:
                printf("\x1b[24;10H1. Invasion!");
                printf("\x1b[24;30HHighscore: ");
                printf("\x1b[24;42H%d", SaveData::getInstance()->getHighScore(difficulty, 0));
                break;
            case 1:
                printf("\x1b[24;10H2. Freeze or Burn");
                printf("\x1b[24;30HHighscore: ");
                printf("\x1b[24;42H%d", SaveData::getInstance()->getHighScore(difficulty, 1));
                break;
            case 2:
                printf("\x1b[24;10H3. Hull Damage");
                printf("\x1b[24;30HHighscore: ");
                printf("\x1b[24;42H%d", SaveData::getInstance()->getHighScore(difficulty, 2));
                break;
            case 3:
                printf("\x1b[24;10H4. Clear a Path");
                printf("\x1b[24;30HHighscore: ");
                printf("\x1b[24;42H%d", SaveData::getInstance()->getHighScore(difficulty, 3));
                break;
            case 4:
                printf("\x1b[24;10H5. Hangar Breach");
                printf("\x1b[24;30HHighscore: ");
                printf("\x1b[24;42H%d", SaveData::getInstance()->getHighScore(difficulty, 4));
                break;
            case 5:
                printf("\x1b[24;10H6. Divided");
                printf("\x1b[24;30HHighscore: ");
                printf("\x1b[24;42H%d", SaveData::getInstance()->getHighScore(difficulty, 5));
                break;
            case 6:
                printf("\x1b[24;10H7. Blitzkrieg");
                printf("\x1b[24;30HHighscore: ");
                printf("\x1b[24;42H%d", SaveData::getInstance()->getHighScore(difficulty, 6));
                break;
            case 7:
                printf("\x1b[24;10H8. Full-scale War");
                printf("\x1b[24;30HHighscore: ");
                printf("\x1b[24;42H%d", SaveData::getInstance()->getHighScore(difficulty, 7));
                break;
            case 8:
                printf("\x1b[24;10H9. Sabotoge");
                printf("\x1b[24;30HHighscore: ");
                printf("\x1b[24;42H%d", SaveData::getInstance()->getHighScore(difficulty, 8));
                break;
            case 9:
                printf("\x1b[24;10H10. Finale");
                printf("\x1b[24;30HHighscore: ");
                printf("\x1b[24;42H%d", SaveData::getInstance()->getHighScore(difficulty, 9));
                break;
            }

            if (kDown & KEY_A)
            {
                levelChosen = true;
            }

            if ((kDown & KEY_DRIGHT) || (kDown & KEY_DDOWN))
            {
                level++;
                if (level > 9)
                {
                    level = 0;
                }
            }
            else if ((kDown & KEY_DLEFT) || (kDown & KEY_DUP))
            {
                level--;
                if (level < 0)
                {
                    level = 9;
                }
            }
        }
        else
        {
            if (kDown & KEY_A)
            {
                difficultyChosen = true;
            }

            if ((kDown & KEY_DRIGHT) || (kDown & KEY_DDOWN))
            {
                difficulty++;
                if (difficulty > DIFFICULTY_LEVEL_HARD)
                {
                    difficulty = DIFFICULTY_LEVEL_EASY;
                }
            }
            else if ((kDown & KEY_DLEFT) || (kDown & KEY_DUP))
            {
                difficulty--;
                if (difficulty < DIFFICULTY_LEVEL_EASY)
                {
                    difficulty = DIFFICULTY_LEVEL_HARD;
                }
            }
        }

        // Flush and swap framebuffers
        gfxFlushBuffers();
        gfxSwapBuffers();

        //Wait for VBlank
        gspWaitForVBlank();

        if (difficultyChosen && levelChosen)
        {
            // Exit services
            gfxExit();

            runGame(level, difficulty);

            // Initialize services
            gfxInitDefault();

            // Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
            consoleInit(GFX_BOTTOM, NULL);

            difficultyChosen = false;
            levelChosen = false;
            difficulty = DIFFICULTY_LEVEL_NORMAL;
            level = 0;
        }
    }

    return 0;
}