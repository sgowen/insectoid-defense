//
//  Sound.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#import <AudioToolbox/AudioServices.h>

@interface Sound : NSObject
{
@private
    NSString *fileName;
    SystemSoundID *soundID;
    int maxNumPlays;
    int soundIndex;
}

- (id)initWithSoundNamed:(NSString *)fileName fromBundle:(NSBundle *)bundle andMaxNumOfSimultaneousPlays:(int)mnsp;

- (void)play;

- (NSString *)getFileName;

@end