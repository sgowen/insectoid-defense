//
//  SaveData.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

@interface SaveData : NSObject
{
    // Empty
}

+ (BOOL)hasTutorialBeenViewedForLevelIndex:(int)levelIndex;

+ (void)setTutorialViewedForLevelIndex:(int)levelIndex;

+ (int)getHighScoreForDifficultyLevel:(int)dl andLevelIndex:(int)levelIndex;

+ (int)getHighWaveForDifficultyLevel:(int)dl andLevelIndex:(int)levelIndex;

+ (void)saveHighScore:(int)highscore andHighWave:(int)wave forDifficultyLevel:(int)dl andLevelIndex:(int)levelIndex;

@end