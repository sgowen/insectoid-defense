//
//  LevelSelectionViewController.m
//  insectoid-defense
//
//  Created by Stephen Gowen on 7/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#import "LevelSelectionViewController.h"
#import "ViewUtils.h"
#import "Music.h"
#import "LevelTableViewCell.h"
#import "GameViewController.h"
#import "SaveData.h"
#import "LevelWaveRequirementMapper.h"
#import "LevelTableViewCell.h"

@interface LevelSelectionViewController ()

@property (strong, nonatomic) Music *bgm;
@property (assign, nonatomic) int levelIndex;
@property (assign, nonatomic) int difficultyLevel;

@end

@implementation LevelSelectionViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self.levelsTableView setDataSource:self];
    [self.levelsTableView setDelegate:self];
    
    UIFont *font = [UIFont fontWithName:@"Astrolyte" size:12.0f];
    NSDictionary *attributes = [NSDictionary dictionaryWithObject:font forKey:NSFontAttributeName];
    [self.difficultyLevelsSegmentedControl setTitleTextAttributes:attributes forState:UIControlStateNormal];
    
    [ViewUtils setAstrolytFontForView:self.view];
    
    self.difficultyLevel = 1;
    self.bgm = [[Music alloc] initWithMusicNamed:@"level_selection_bgm" fromBundle:[NSBundle mainBundle]];
    [self.bgm setLooping:true];
    [self.bgm setVolume:1.0f];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    [self.levelsTableView reloadData];
    [self.bgm play];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    [self.bgm stop];
}

- (BOOL)shouldAutorotate
{
    return TRUE;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)orient
{
    return orient == UIInterfaceOrientationLandscapeRight;
}

- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation
{
    return UIInterfaceOrientationLandscapeRight;
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"Level_Select_To_Game"])
    {
        GameViewController *gameViewController = (GameViewController *)segue.destinationViewController;
        gameViewController.levelIndex = self.levelIndex;
        gameViewController.difficultyLevel = self.difficultyLevel;
    }
    
    [super prepareForSegue:segue sender:sender];
}

#pragma IBAction methods

- (IBAction)difficultyLevelChanged:(id)sender
{
    UISegmentedControl *sc = (UISegmentedControl *)sender;
    self.difficultyLevel = sc.selectedSegmentIndex == 0 ? 0 : sc.selectedSegmentIndex == 1 ? 1 : 2;
    [self.levelsTableView reloadData];
    
    self.levelInfoScrollView.hidden = YES;
    self.startButton.hidden = YES;
    [self.shipImageView setImage:[UIImage imageNamed:@"ship_default.png"]];
}

- (IBAction)backTouchUpInside:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)startTouchUpInside:(id)sender
{
    [self performSegueWithIdentifier:@"Level_Select_To_Game" sender:self];
}

#pragma <UITableViewDataSource> methods

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 10;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    LevelTableViewCell *cell = (LevelTableViewCell *)[tableView dequeueReusableCellWithIdentifier:[LevelTableViewCell getIdentifier]];
    
    cell = [self loadCellAtIndexPath:indexPath];
    
    [ViewUtils setAstrolytFontForView:cell];
    
    return cell;
}

#pragma <UITableViewDelegate> methods

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    for (LevelTableViewCell *cell in self.levelsTableView.visibleCells)
    {
        [cell deselect];
    }
    
    LevelTableViewCell *cell = (LevelTableViewCell *)[self.levelsTableView cellForRowAtIndexPath:indexPath];
    [cell select];
    
    self.levelIndex = (int)indexPath.row;
    NSString *shipImageFileName = [NSString stringWithFormat:@"ship_level_%i.png", ((int)indexPath.row + 1)];
    [self.shipImageView setImage:[UIImage imageNamed:shipImageFileName]];
    self.levelInfoScrollView.hidden = NO;
    
    [self selectCellAtIndexPath:indexPath];
    
    CGFloat originalLabelWidth = self.levelDescriptionLabel.frame.size.width;
    [self.levelDescriptionLabel sizeToFit];
    self.levelDescriptionLabel.frame = CGRectMake(self.levelDescriptionLabel.frame.origin.x, self.levelDescriptionLabel.frame.origin.y, originalLabelWidth, self.levelDescriptionLabel.frame.size.height);
    
    CGSize scrollViewSize = self.levelInfoScrollView.frame.size;
    CGSize levelDescriptionLabelSize = self.levelDescriptionLabel.frame.size;
    CGFloat levelDescriptionLabelY = self.levelDescriptionLabel.frame.origin.y;
    self.levelInfoScrollView.contentSize = CGSizeMake(scrollViewSize.width, levelDescriptionLabelY + levelDescriptionLabelSize.height);
    
    [ViewUtils setAstrolytFontForView:self.view];
}

- (LevelTableViewCell *)loadCellAtIndexPath:(NSIndexPath *)indexPath
{
    if((int)indexPath.row == 0 || [SaveData getHighWaveForDifficultyLevel:self.difficultyLevel andLevelIndex:((int)indexPath.row - 1)] >= [LevelWaveRequirementMapper getWaveRequirementForLevelIndex:((int)indexPath.row - 1)])
    {
        NSArray *topLevelObjects = [[NSBundle mainBundle] loadNibNamed:[LevelTableViewCell getLevelUnlockedNibName] owner:self options:nil];
        LevelTableViewCell *cell = [topLevelObjects objectAtIndex:0];
        [cell configureWithDifficultyLevel:self.difficultyLevel andLevelIndex:(int)indexPath.row setStatsText:true];
        
        return cell;
    }
    else
    {
        NSArray *topLevelObjects = [[NSBundle mainBundle] loadNibNamed:[LevelTableViewCell getLevelLockedNibName] owner:self options:nil];
        LevelTableViewCell *cell = [topLevelObjects objectAtIndex:0];
        [cell configureWithDifficultyLevel:self.difficultyLevel andLevelIndex:(int)indexPath.row setStatsText:false];
        
        return cell;
    }
}

- (void)selectCellAtIndexPath:(NSIndexPath *)indexPath
{
    if((int)indexPath.row == 0 || [SaveData getHighWaveForDifficultyLevel:self.difficultyLevel andLevelIndex:((int)indexPath.row - 1)] >= [LevelWaveRequirementMapper getWaveRequirementForLevelIndex:((int)indexPath.row - 1)])
    {
        NSString *levelDescription = [NSString stringWithFormat:@"level_description_%i", self.levelIndex];
        self.levelDescriptionLabel.text = NSLocalizedString(levelDescription, nil);
        self.startButton.hidden = NO;
    }
    else
    {
        self.levelDescriptionLabel.text = [LevelWaveRequirementMapper getLockedDescriptionStringForLevelIndex:(int)indexPath.row];
        self.startButton.hidden = YES;
    }
}

@end