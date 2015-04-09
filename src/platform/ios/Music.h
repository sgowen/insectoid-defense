//
//  Music.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>

@interface Music : NSObject <AVAudioPlayerDelegate>
{
    
}

@property (retain, nonatomic) AVAudioPlayer *player;

- (id)initWithMusicNamed:(NSString *)filename fromBundle:(NSBundle *)bundle;

- (void)play;

- (void)pause;

- (void)stop;

- (void)setLooping:(BOOL)isLooping;

- (void)setVolume:(float)volume;

- (bool)isValid;

- (void)dealloc;

@end