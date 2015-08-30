//
//  SaveData.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 8/26/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#include "SaveData.h"
#include "DifficultyLevel.h"

extern "C"
{
#include "filesystem.h"
#include <stdio.h>
}

SaveData * SaveData::getInstance()
{
    static SaveData *saveData = new SaveData();

    return saveData;
}

void SaveData::loadGame()
{
    FILE *fp = 0;
    fp = openFile("insectoid.sav", "rb+");
    if (fp != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            fread((void *) &HIGH_SCORES_EASY[i], sizeof (int), 1, fp);
            fread((void *) &HIGH_SCORES_NORMAL[i], sizeof (int), 1, fp);
            fread((void *) &HIGH_SCORES_HARD[i], sizeof (int), 1, fp);

            fread((void *) &HIGH_WAVES_EASY[i], sizeof (int), 1, fp);
            fread((void *) &HIGH_WAVES_NORMAL[i], sizeof (int), 1, fp);
            fread((void *) &HIGH_WAVES_HARD[i], sizeof (int), 1, fp);
        }

        fclose(fp);
    }
}

void SaveData::saveGame()
{
    FILE *fp = 0;
    fp = openFile("insectoid.sav", "wb+");
    if (fp != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            fwrite((void *) &HIGH_SCORES_EASY[i], sizeof (int), 1, fp);
            fwrite((void *) &HIGH_SCORES_NORMAL[i], sizeof (int), 1, fp);
            fwrite((void *) &HIGH_SCORES_HARD[i], sizeof (int), 1, fp);

            fwrite((void *) &HIGH_WAVES_EASY[i], sizeof (int), 1, fp);
            fwrite((void *) &HIGH_WAVES_NORMAL[i], sizeof (int), 1, fp);
            fwrite((void *) &HIGH_WAVES_HARD[i], sizeof (int), 1, fp);
        }

        fflush(fp);
        fclose(fp);
    }
}

int SaveData::getHighScore(int difficulty, int level)
{
    switch (difficulty)
    {
    case DIFFICULTY_LEVEL_EASY:
        return HIGH_SCORES_EASY[level];
    case DIFFICULTY_LEVEL_NORMAL:
        return HIGH_SCORES_NORMAL[level];
    case DIFFICULTY_LEVEL_HARD:
        return HIGH_SCORES_HARD[level];
    default:
        return 0;
    }
}

int SaveData::getHighWave(int difficulty, int level)
{
    switch (difficulty)
    {
    case DIFFICULTY_LEVEL_EASY:
        return HIGH_WAVES_EASY[level];
    case DIFFICULTY_LEVEL_NORMAL:
        return HIGH_WAVES_NORMAL[level];
    case DIFFICULTY_LEVEL_HARD:
        return HIGH_WAVES_HARD[level];
    default:
        return 0;
    }
}

void SaveData::saveHighScore(int highscore, int highWave, int difficulty, int level)
{
    bool dataUpdated = false;

    int highestScore = getHighScore(difficulty, level);

    if (highscore > highestScore)
    {
        dataUpdated = true;

        switch (difficulty)
        {
        case DIFFICULTY_LEVEL_EASY:
            HIGH_SCORES_EASY[level] = highscore;
            break;
        case DIFFICULTY_LEVEL_NORMAL:
            HIGH_SCORES_NORMAL[level] = highscore;
            break;
        case DIFFICULTY_LEVEL_HARD:
            HIGH_SCORES_HARD[level] = highscore;
            break;
        }
    }

    int highestWave = getHighWave(difficulty, level);

    if (highWave > highestWave)
    {
        dataUpdated = true;

        switch (difficulty)
        {
        case DIFFICULTY_LEVEL_EASY:
            HIGH_WAVES_EASY[level] = highWave;
            break;
        case DIFFICULTY_LEVEL_NORMAL:
            HIGH_WAVES_NORMAL[level] = highWave;
            break;
        case DIFFICULTY_LEVEL_HARD:
            HIGH_WAVES_HARD[level] = highWave;
            break;
        }
    }

    if (dataUpdated)
    {
        saveGame();
    }
}

SaveData::SaveData()
{
    // Hide Constructor for Singleton
    for (int i = 0; i < 10; i++)
    {
        HIGH_SCORES_EASY.push_back(0);
        HIGH_SCORES_NORMAL.push_back(0);
        HIGH_SCORES_HARD.push_back(0);

        HIGH_WAVES_EASY.push_back(0);
        HIGH_WAVES_NORMAL.push_back(0);
        HIGH_WAVES_HARD.push_back(0);
    }
}