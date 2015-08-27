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

void printLevelNameAndHighscore(int difficulty, int level, PrintConsole &screen)
{
    consoleSelect(&screen);
    switch (level)
    {
    case 0:
        printf("\x1b[19;0H1. Invasion!         ");
        break;
    case 1:
        printf("\x1b[19;0H2. Freeze or Burn    ");
        break;
    case 2:
        printf("\x1b[19;0H3. Hull Damage       ");
        break;
    case 3:
        printf("\x1b[19;0H4. Clear a Path      ");
        break;
    case 4:
        printf("\x1b[19;0H5. Hangar Breach     ");
        break;
    case 5:
        printf("\x1b[19;0H6. Divided           ");
        break;
    case 6:
        printf("\x1b[19;0H7. Blitzkrieg        ");
        break;
    case 7:
        printf("\x1b[19;0H8. Full-scale War    ");
        break;
    case 8:
        printf("\x1b[19;0H9. Sabotoge          ");
        break;
    case 9:
        printf("\x1b[19;0H10. Finale           ");
        break;
    }

    printf("\x1b[19;21H| score: ");
    printf("\x1b[19;30H%d", SaveData::getInstance()->getHighScore(difficulty, level));
    printf("\x1b[19;39H wave: ");
    printf("\x1b[19;45H%d", SaveData::getInstance()->getHighWave(difficulty, level));
}

int getWaveRequirementForLevelIndex(int level)
{
    switch (level)
    {
    case 0:
        return 20;
    case 1:
        return 30;
    case 2:
        return 30;
    case 3:
        return 30;
    case 4:
        return 20;
    case 5:
        return 30;
    case 6:
        return 20;
    case 7:
        return 50;
    case 8:
        return 40;
    case 9:
        return 60;
    default:
        return 1337;
    }
}

void printLevelDescription(int difficulty, int level, PrintConsole &screen)
{
    consoleSelect(&screen);

    int highWave = SaveData::getInstance()->getHighWave(difficulty, level);
    int waveRequirement = getWaveRequirementForLevelIndex(level - 1);

    if (level == 0 || highWave > waveRequirement)
    {
        switch (level)
        {
        case 0:
            printf("\x1b[0;0HInsectoids have ambushed our star cruiser on our way back to Earth! Most of our weapon systems have already been knocked offline or destroyed entirely. The entire ship is infested, including the civilian quarters. Drive them out!");
            break;
        case 1:
            printf("\x1b[0;0HThe Insectoids are nearly out of the civilian quarters, but now we must face their fire armada. They have trapped our best scientists. Fortunately, we have repaired our Freeze Tower, which can force enemies to move slower. Also, it appears that Red Insectoids in particular are very weak to the effects of this tower. Rescue the scientists!");
            break;
        case 2:
            printf("\x1b[0;0HThere is a new type of green Insectoid eating away at our ship's hull. They repair damage from attacks rather quickly. Fortunately, we were able to bring our missiles back online. We can use them to obliterate the enemy! Be careful though, because missiles are ineffective against Red Insectoids and are unable to target the Blue Insectoids.");
            break;
        case 3:
            printf("\x1b[0;0HWe are unable to transport our civilians off the ship until we establish a safe path for them to the hangar. The scientists we rescued have developed a new Fire tower that can prevent the Green Insectoid from regenerating. Also, any Blue Insectoids caught on fire can be targetted by missiles! Clear a path to the hangar!");
            break;
        case 4:
            printf("\x1b[0;0HWe have been cut off from our own hangar, crippling our attack. If we do not reclaim the hangar soon, we will lose our momentum in this fight. The scientists have developed a new Green Tower harnessed from a Green Insectoid we captured in our previous battle. However, we are uncertain of its abilities. In any case, clean out the hangar!");
            break;
        case 5:
            printf("\x1b[0;0HThe hangar is ours, but it is in bad shape. The majority of our equipment has been seized and relocated to the bridge, where the Insectoids are regrouping to isolate us in the hangar. We are unable to get the hangar operational again until we reclaim our equipment!");
            break;
        case 6:
            printf("\x1b[0;0HA new yellow Insectoid has penetrated our industrial sector. Unfortunately for us, it appears to be twice as fast as the others. The Insectoids are going to destroy our supplies if we do not act quickly! Early analysis indicates that this Insectoid is resistant to electric attacks but is highly vulnerable to the Green Tower. Good luck!");
            break;
        case 7:
            printf("\x1b[0;0HOur hangar has been repaired, and the civilians have been sent down to our home planet. After retreating for several weeks, the enemy is approaching again. This appears to be their largest attack yet. We are in a much better position now than ever before to fight them, but prepare for the worst...");
            break;
        case 8:
            printf("\x1b[0;0HWhile we were distracted with the battle topside, the enemy has sabotoged our propulsion system. Unfortunately, we can only afford to send a small team for this, since we are mostly occupied by the larger battle, but we absolutely must regain control of those engines. Otherwise, we will fall out of orbit with our planet and lose our only chance to come home alive!");
            break;
        case 9:
            printf("\x1b[0;0HWe have prevented additional damage to our engines, but we have slowed down enough for the entire Insectoid army to surround us. Our scientists have engineered a bomb that can destroy them all in one shot. All we need to do is fend them off while it is prepared for deployment and our engines are repaired. Pull this off, and we will be able to escape while the Insectoids are wiped out for good!");
            break;
        }
    }
    else
    {
        printf("\x1b[0;0H                                                                                                                                                                                                                                                                                                                                                                                                                ");

        switch (level)
        {
        case 1:
            printf("\x1b[0;0HReach wave 20 or higher in Invasion! to unlock!");
            break;
        case 2:
            printf("\x1b[0;0HReach wave 30 or higher in Freeze or Burn to unlock!");
            break;
        case 3:
            printf("\x1b[0;0HReach wave 30 or higher in Hull Damage to unlock!");
            break;
        case 4:
            printf("\x1b[0;0HReach wave 30 or higher in Clear a Path to unlock!");
            break;
        case 5:
            printf("\x1b[0;0HReach wave 20 or higher in Hangar Breach to unlock!");
            break;
        case 6:
            printf("\x1b[0;0HReach wave 30 or higher in Divided to unlock!");
            break;
        case 7:
            printf("\x1b[0;0HReach wave 20 or higher in Blitzkrieg to unlock!");
            break;
        case 8:
            printf("\x1b[0;0HReach wave 50 or higher in Full-scale War to unlock!");
            break;
        case 9:
            printf("\x1b[0;0HReach wave 40 or higher in Sabotoge to unlock!");
            break;
        }
    }
}

void showDifficultyLevelSelectionOutput(int difficulty, bool difficultyChosen, int level, PrintConsole &topScreen, PrintConsole &bottomScreen)
{
    consoleSelect(&topScreen);

    printf("\x1b[0;0H                                                  "); // Clears file IO info

    printf("\x1b[12;7H Select a Difficulty using the D-Pad");

    switch (difficulty)
    {
    case DIFFICULTY_LEVEL_EASY:
        printf("\x1b[14;22H EASY ");
        break;
    case DIFFICULTY_LEVEL_NORMAL:
        printf("\x1b[14;22HNORMAL");
        break;
    case DIFFICULTY_LEVEL_HARD:
        printf("\x1b[14;22H HARD ");
        break;
    }

    if (difficultyChosen)
    {
        printf("\x1b[17;10HSelect a Level using the D-Pad");

        printLevelNameAndHighscore(difficulty, level, topScreen);
        printLevelDescription(difficulty, level, bottomScreen);
    }
    else
    {
        printf("\x1b[17;0H                                                  ");
        printf("\x1b[19;0H                                                  ");
        printf("\x1b[20;0H                                                  ");

        consoleSelect(&bottomScreen);
        printf("\x1b[0;0H                                                                                                                                                                                                                                                                                                                                                                                                                ");
    }

    printf("\n\n");
}

int main(int argc, char** argv)
{
    // Initialize services
    gfxInitDefault();
    filesystemInit(argc, argv);

    PrintConsole topScreen, bottomScreen;

    // Initialize console for both screen using the two different PrintConsole we have defined
    consoleInit(GFX_TOP, &topScreen);
    consoleInit(GFX_BOTTOM, &bottomScreen);

    bool difficultyChosen = false;
    bool levelChosen = false;
    int difficulty = DIFFICULTY_LEVEL_NORMAL;
    int level = 0;

    SaveData::getInstance()->loadGame();

    // Main Menu loop
    while (aptMainLoop())
    {
        hidScanInput();

        u32 kDown = hidKeysDown();
        if (kDown & KEY_START)
        {
            break; // break in order to return to hbmenu
        }

        showDifficultyLevelSelectionOutput(difficulty, difficultyChosen, level, topScreen, bottomScreen);

        if (difficultyChosen)
        {
            if (kDown & KEY_A)
            {
                int highWave = SaveData::getInstance()->getHighWave(difficulty, level);
                int waveRequirement = getWaveRequirementForLevelIndex(level - 1);

                levelChosen = level == 0 || highWave > waveRequirement;
            }

            if (kDown & KEY_B)
            {
                difficultyChosen = false;
            }

            if ((kDown & KEY_DRIGHT) || (kDown & KEY_DDOWN))
            {
                level++;
                if (level > 9)
                {
                    level = 0;
                }
            }

            if ((kDown & KEY_DLEFT) || (kDown & KEY_DUP))
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

            if ((kDown & KEY_DLEFT) || (kDown & KEY_DUP))
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

            // Initialize console for both screen using the two different PrintConsole we have defined
            consoleInit(GFX_TOP, &topScreen);
            consoleInit(GFX_BOTTOM, &bottomScreen);

            difficultyChosen = false;
            levelChosen = false;
            difficulty = DIFFICULTY_LEVEL_NORMAL;
            level = 0;
        }
    }

    return 0;
}