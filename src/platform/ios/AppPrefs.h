//
//  AppPrefs.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

@interface AppPrefs : NSObject
{
    
}

+ (id)getInstance;

- (void)setString:(NSString *)value forKey:(NSString *)key;

- (void)setInt:(int)value forKey:(NSString *)key;

- (void)setBool:(BOOL)value forKey:(NSString *)key;

- (NSString *)getString:(NSString *)key;

- (int)getInt:(NSString *)key;

- (BOOL)getBool:(NSString *)key;

@end