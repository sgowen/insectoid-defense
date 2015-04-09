//
//  LevelSelectionViewController.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 7/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#import "LevelTableViewCell.h"

@interface LevelSelectionViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>
{
    
}

@property (strong, nonatomic) IBOutlet UIImageView *shipImageView;
@property (strong, nonatomic) IBOutlet UIScrollView *levelInfoScrollView;
@property (strong, nonatomic) IBOutlet UILabel *levelDescriptionLabel;
@property (strong, nonatomic) IBOutlet UISegmentedControl *difficultyLevelsSegmentedControl;
@property (strong, nonatomic) IBOutlet UITableView *levelsTableView;
@property (strong, nonatomic) IBOutlet UIButton *backButton;
@property (strong, nonatomic) IBOutlet UIButton *startButton;

- (IBAction)difficultyLevelChanged:(id)sender;
- (IBAction)backTouchUpInside:(id)sender;
- (IBAction)startTouchUpInside:(id)sender;

- (LevelTableViewCell *)loadCellAtIndexPath:(NSIndexPath *)indexPath;

- (void)selectCellAtIndexPath:(NSIndexPath *)indexPath;

@end