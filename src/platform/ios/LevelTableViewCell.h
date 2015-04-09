//
//  LevelTableViewCell.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 7/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

@interface LevelTableViewCell : UITableViewCell
{
    // Empty
}

@property (strong, nonatomic) IBOutlet UILabel *levelNameLabel;
@property (strong, nonatomic) IBOutlet UILabel *levelStatsLabel;

+ (NSString *)getIdentifier;

+ (NSString *)getLevelUnlockedNibName;

+ (NSString *)getLevelLockedNibName;

- (void)configureWithDifficultyLevel:(int)dl andLevelIndex:(int)li setStatsText:(bool)setStats;

- (void)select;

- (void)deselect;

@end