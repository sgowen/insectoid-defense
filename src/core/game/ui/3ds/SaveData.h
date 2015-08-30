//
//  SaveData.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 8/26/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__SaveData__
#define __insectoiddefense__SaveData__

#include <vector>

class SaveData
{
public:
    static SaveData * getInstance();

    void loadGame();

    void saveGame();

    int getHighScore(int difficulty, int level);

    int getHighWave(int difficulty, int level);

    void saveHighScore(int highscore, int highWave, int difficulty, int level);

private:
    std::vector<int> HIGH_SCORES_EASY;
    std::vector<int> HIGH_SCORES_NORMAL;
    std::vector<int> HIGH_SCORES_HARD;

    std::vector<int> HIGH_WAVES_EASY;
    std::vector<int> HIGH_WAVES_NORMAL;
    std::vector<int> HIGH_WAVES_HARD;

    // ctor, copy ctor, and assignment should be private in a Singleton
    SaveData();
    SaveData(const SaveData&);
    SaveData& operator=(const SaveData&);
};

#endif /* defined(__insectoiddefense__SaveData__) */
