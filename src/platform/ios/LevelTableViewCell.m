//
//  LevelTableViewCell.m
//  insectoid-defense
//
//  Created by Stephen Gowen on 7/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#import "LevelTableViewCell.h"
#import "SaveData.h"

@implementation LevelTableViewCell

static NSString *identifier = @"Level_Cell";
static NSString *unlockedNibName = @"Level_Unlocked_TableViewCell";
static NSString *lockedNibName = @"Level_Locked_TableViewCell";

+ (NSString *)getIdentifier
{
    return identifier;
}

+ (NSString *)getLevelUnlockedNibName
{
    return unlockedNibName;
}

+ (NSString *)getLevelLockedNibName
{
    return lockedNibName;
}

- (void)configureWithDifficultyLevel:(int)dl andLevelIndex:(int)li setStatsText:(bool)setStats;
{
    NSString *levelName = [NSString stringWithFormat:@"level_%i", li];
    self.levelNameLabel.text = NSLocalizedString(levelName, nil);
    
    if(setStats)
    {
        int highscore = [SaveData getHighScoreForDifficultyLevel:dl andLevelIndex:li];
        int wave = [SaveData getHighWaveForDifficultyLevel:dl andLevelIndex:li];
        self.levelStatsLabel.text = [NSString stringWithFormat:NSLocalizedString(@"highscore_wave_format", nil), highscore, wave];
    }
}

- (void)select
{
    [self.levelNameLabel setTextColor:[UIColor greenColor]];
    [self.levelStatsLabel setTextColor:[UIColor greenColor]];
}

- (void)deselect
{
    [self.levelNameLabel setTextColor:[UIColor blackColor]];
    [self.levelStatsLabel setTextColor:[UIColor blackColor]];
}

@end