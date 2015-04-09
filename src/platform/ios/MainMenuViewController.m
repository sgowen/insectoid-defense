//
//  MainMenuViewController.m
//  insectoid-defense
//
//  Created by Stephen Gowen on 7/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#import "MainMenuViewController.h"
#import "ViewUtils.h"
#import "SaveData.h"
#import "UIView+Toast.h"

@implementation MainMenuViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [ViewUtils setAstrolytFontForView:self.view];
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

#pragma mark <IBAction>

- (IBAction)playTouchUpInside:(id)sender
{
    [self performSegueWithIdentifier:@"Main_To_Level_Select" sender:self];
}

- (IBAction)howToPlayTouchUpInside:(id)sender
{
    NSURL *url = [NSURL URLWithString:@"https://s3.amazonaws.com/insectoiddefense/insectoid-defense-how-to-play/index.html"];
    [[UIApplication sharedApplication] openURL:url];
}

@end