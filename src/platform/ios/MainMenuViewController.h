//
//  MainMenuViewController.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 7/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

@interface MainMenuViewController : UIViewController
{
    
}

@property (strong, nonatomic) IBOutlet UILabel *titleLabel;
@property (strong, nonatomic) IBOutlet UIButton *playButton;

- (IBAction)playTouchUpInside:(id)sender;
- (IBAction)howToPlayTouchUpInside:(id)sender;

@end