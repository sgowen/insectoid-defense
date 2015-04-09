//
//  SaveData.m
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#import "SaveData.h"
#import "AppPrefs.h"
#include "DifficultyLevel.h"

@implementation SaveData

static NSArray *HIGH_SCORES_EASY;
static NSArray *HIGH_SCORES_NORMAL;
static NSArray *HIGH_SCORES_HARD;

static NSArray *HIGH_WAVES_EASY;
static NSArray *HIGH_WAVES_NORMAL;
static NSArray *HIGH_WAVES_HARD;

static NSArray *TUTORIAL_VIEWED_FOR_LEVEL;

+ (void)initialize
{
    HIGH_SCORES_EASY = [[NSArray alloc] initWithObjects:
                        @"high_score_level_one_easy",
                        @"high_score_level_two_easy",
                        @"high_score_level_three_easy",
                        @"high_score_level_four_easy",
                        @"high_score_level_five_easy",
                        @"high_score_level_six_easy",
                        @"high_score_level_seven_easy",
                        @"high_score_level_eight_easy",
                        @"high_score_level_nine_easy",
                        @"high_score_level_ten_easy",
                        nil];
    
    HIGH_SCORES_NORMAL = [[NSArray alloc] initWithObjects:
                          @"high_score_level_one_normal",
                          @"high_score_level_two_normal",
                          @"high_score_level_three_normal",
                          @"high_score_level_four_normal",
                          @"high_score_level_five_normal",
                          @"high_score_level_six_normal",
                          @"high_score_level_seven_normal",
                          @"high_score_level_eight_normal",
                          @"high_score_level_nine_normal",
                          @"high_score_level_ten_normal",
                          nil];
    
    HIGH_SCORES_HARD = [[NSArray alloc] initWithObjects:
                        @"high_score_level_one_hard",
                        @"high_score_level_two_hard",
                        @"high_score_level_three_hard",
                        @"high_score_level_four_hard",
                        @"high_score_level_five_hard",
                        @"high_score_level_six_hard",
                        @"high_score_level_seven_hard",
                        @"high_score_level_eight_hard",
                        @"high_score_level_nine_hard",
                        @"high_score_level_ten_hard",
                        nil];
    
    HIGH_WAVES_EASY = [[NSArray alloc] initWithObjects:
                       @"high_wave_level_one_easy",
                       @"high_wave_level_two_easy",
                       @"high_wave_level_three_easy",
                       @"high_wave_level_four_easy",
                       @"high_wave_level_five_easy",
                       @"high_wave_level_six_easy",
                       @"high_wave_level_seven_easy",
                       @"high_wave_level_eight_easy",
                       @"high_wave_level_nine_easy",
                       @"high_wave_level_ten_easy",
                       nil];
    
    HIGH_WAVES_NORMAL = [[NSArray alloc] initWithObjects:
                         @"high_wave_level_one_normal",
                         @"high_wave_level_two_normal",
                         @"high_wave_level_three_normal",
                         @"high_wave_level_four_normal",
                         @"high_wave_level_five_normal",
                         @"high_wave_level_six_normal",
                         @"high_wave_level_seven_normal",
                         @"high_wave_level_eight_normal",
                         @"high_wave_level_nine_normal",
                         @"high_wave_level_ten_normal",
                         nil];
    
    HIGH_WAVES_HARD = [[NSArray alloc] initWithObjects:
                       @"high_wave_level_one_hard",
                       @"high_wave_level_two_hard",
                       @"high_wave_level_three_hard",
                       @"high_wave_level_four_hard",
                       @"high_wave_level_five_hard",
                       @"high_wave_level_six_hard",
                       @"high_wave_level_seven_hard",
                       @"high_wave_level_eight_hard",
                       @"high_wave_level_nine_hard",
                       @"high_wave_level_ten_hard",
                       nil];
    
    TUTORIAL_VIEWED_FOR_LEVEL = [[NSArray alloc] initWithObjects:
                                 @"level_one_tutorial_viewed",
                                 @"level_two_tutorial_viewed",
                                 @"level_three_tutorial_viewed",
                                 @"level_four_tutorial_viewed",
                                 @"level_five_tutorial_viewed",
                                 @"level_six_tutorial_viewed",
                                 @"level_seven_tutorial_viewed",
                                 @"level_eight_tutorial_viewed",
                                 @"level_nine_tutorial_viewed",
                                 @"level_ten_tutorial_viewed",
                                 nil];
}


+ (BOOL)hasTutorialBeenViewedForLevelIndex:(int)levelIndex
{
    return [[AppPrefs getInstance] getBool:TUTORIAL_VIEWED_FOR_LEVEL[levelIndex]];
}

+ (void)setTutorialViewedForLevelIndex:(int)levelIndex
{
    [[AppPrefs getInstance] setBool:YES forKey:TUTORIAL_VIEWED_FOR_LEVEL[levelIndex]];
}

+ (int)getHighScoreForDifficultyLevel:(int)dl andLevelIndex:(int)levelIndex
{
    return [[AppPrefs getInstance] getInt:[self getHighScoresKeysForDifficultyLevel:dl][levelIndex]];
}

+ (int)getHighWaveForDifficultyLevel:(int)dl andLevelIndex:(int)levelIndex
{
    return [[AppPrefs getInstance] getInt:[self getHighWavesKeysForDifficultyLevel:dl][levelIndex]];
}

+ (void)saveHighScore:(int)highscore andHighWave:(int)wave forDifficultyLevel:(int)dl andLevelIndex:(int)levelIndex
{
    int highestScore = [self getHighScoreForDifficultyLevel:dl andLevelIndex:levelIndex];
    
    if (highscore > highestScore)
    {
        [[AppPrefs getInstance] setInt:highscore forKey:[self getHighScoresKeysForDifficultyLevel:dl][levelIndex]];
    }
    
    int highestWave = [self getHighWaveForDifficultyLevel:dl andLevelIndex:levelIndex];
    
    if(wave > highestWave)
    {
        [[AppPrefs getInstance] setInt:wave forKey:[self getHighWavesKeysForDifficultyLevel:dl][levelIndex]];
    }
}

+ (NSArray *)getHighScoresKeysForDifficultyLevel:(int)difficultyLevel
{
    switch (difficultyLevel)
    {
        case DIFFICULTY_LEVEL_EASY:
            return HIGH_SCORES_EASY;
        case DIFFICULTY_LEVEL_NORMAL:
            return HIGH_SCORES_NORMAL;
        case DIFFICULTY_LEVEL_HARD:
            return HIGH_SCORES_HARD;
        default:
            return nil;
    }
}

+ (NSArray *)getHighWavesKeysForDifficultyLevel:(int)difficultyLevel
{
    switch (difficultyLevel)
    {
        case DIFFICULTY_LEVEL_EASY:
            return HIGH_WAVES_EASY;
        case DIFFICULTY_LEVEL_NORMAL:
            return HIGH_WAVES_NORMAL;
        case DIFFICULTY_LEVEL_HARD:
            return HIGH_WAVES_HARD;
        default:
            return nil;
    }
}

@end