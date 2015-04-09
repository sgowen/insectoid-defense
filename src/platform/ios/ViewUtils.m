//
//  ViewUtils.m
//  insectoid-defense
//
//  Created by Stephen Gowen on 7/23/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#import "ViewUtils.h"

@implementation ViewUtils

+ (void)setAstrolytFontForView:(UIView *)view
{
    for (UIView *subview in view.subviews)
    {
        if([subview isKindOfClass:[UILabel class]])
        {
            UILabel *label = (UILabel *)subview;
            CGFloat fontSize = label.font.pointSize;
            [label setFont:[UIFont fontWithName:@"Astrolyte" size:fontSize]];
        }
        else if([subview isKindOfClass:[UIButton class]])
        {
            UILabel *label = ((UIButton *)subview).titleLabel;
            CGFloat fontSize = label.font.pointSize;
            [label setFont:[UIFont fontWithName:@"Astrolyte" size:fontSize]];
        }
        else if(subview.subviews)
        {
            for (UIView *innerSubview in view.subviews)
            {
                [self setAstrolytFontForView:innerSubview];
            }
        }
    }
}

@end