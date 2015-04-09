//
//  LevelWaveRequirementMapper.m
//  insectoid-defense
//
//  Created by Stephen Gowen on 7/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#import "LevelWaveRequirementMapper.h"

@implementation LevelWaveRequirementMapper

+ (int)getWaveRequirementForLevelIndex:(int)levelIndex
{
    switch(levelIndex)
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

+ (NSString *)getLockedDescriptionStringForLevelIndex:(int)levelIndex
{
    switch(levelIndex)
    {
        case 1:
            return NSLocalizedString(@"level_2_locked", nil);
        case 2:
            return NSLocalizedString(@"level_3_locked", nil);
        case 3:
            return NSLocalizedString(@"level_4_locked", nil);
        case 4:
            return NSLocalizedString(@"level_5_locked", nil);
        case 5:
            return NSLocalizedString(@"level_6_locked", nil);
        case 6:
            return NSLocalizedString(@"level_7_locked", nil);
        case 7:
            return NSLocalizedString(@"level_8_locked", nil);
        case 8:
            return NSLocalizedString(@"level_9_locked", nil);
        case 9:
            return NSLocalizedString(@"level_10_locked", nil);
        default:
            return @"";
    }
}

+ (NSString *)getLevelUnLockedMessageStringForLevelIndex:(int)levelIndex
{
    switch(levelIndex)
    {
        case 0:
            return NSLocalizedString(@"level_2_unlocked", nil);
        case 1:
            return NSLocalizedString(@"level_3_unlocked", nil);
        case 2:
            return NSLocalizedString(@"level_4_unlocked", nil);
        case 3:
            return NSLocalizedString(@"level_5_unlocked", nil);
        case 4:
            return NSLocalizedString(@"level_6_unlocked", nil);
        case 5:
            return NSLocalizedString(@"level_7_unlocked", nil);
        case 6:
            return NSLocalizedString(@"level_8_unlocked", nil);
        case 7:
            return NSLocalizedString(@"level_9_unlocked", nil);
        case 8:
            return NSLocalizedString(@"level_10_unlocked", nil);
        case 9:
            return NSLocalizedString(@"game_cleared", nil);
        default:
            return @"";
    }
}

@end