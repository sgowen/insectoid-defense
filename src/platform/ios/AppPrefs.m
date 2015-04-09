//
//  AppPrefs.m
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/18/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#import "AppPrefs.h"

@implementation AppPrefs

static AppPrefs *instance = nil;

+ (id)getInstance
{
    if(instance == nil)
    {
        instance = [[AppPrefs alloc] init];
    }
    
	return instance;
}

- (void)setString:(NSString *)value forKey:(NSString *)key
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:value forKey:key];
    [userDefaults synchronize];
}

- (void)setInt:(int)value forKey:(NSString *)key
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setInteger:value forKey:key];
    [userDefaults synchronize];
}

- (void)setBool:(BOOL)value forKey:(NSString *)key
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setBool:value forKey:key];
    [userDefaults synchronize];
}

- (NSString *)getString:(NSString *)key
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    return [userDefaults objectForKey:key];
}

- (int)getInt:(NSString *)key
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    return (int)[userDefaults integerForKey:key];
}

- (BOOL)getBool:(NSString *)key
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    return [userDefaults boolForKey:key];
}

@end