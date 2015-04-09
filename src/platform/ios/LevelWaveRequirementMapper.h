//
//  LevelWaveRequirementMapper.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 7/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

@interface LevelWaveRequirementMapper : NSObject
{
    // Empty
}

+ (int)getWaveRequirementForLevelIndex:(int)levelIndex;

+ (NSString *)getLockedDescriptionStringForLevelIndex:(int)levelIndex;

+ (NSString *)getLevelUnLockedMessageStringForLevelIndex:(int)levelIndex;

@end