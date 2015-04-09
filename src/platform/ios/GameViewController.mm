//
//  GameViewController.m
//  insectoid-defense
//
//  Created by Stephen Gowen on 9/5/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#import "GameViewController.h"
#import "Logger.h"
#import "Music.h"
#import "Sound.h"
#import "GGDDeviceUtil.h"
#import "LevelWaveRequirementMapper.h"
#import "UIView+Toast.h"
#import "SaveData.h"

// C++
#include "game.h"
#include "ResourceConstants.h"
#include "DifficultyLevel.h"
#include "ScreenState.h"

@interface GameViewController ()
{
    bool _isMinimumWaveRequirementMet;
}

@property (strong, nonatomic) EAGLContext *context;
@property (strong, nonatomic) Music *bgm;
@property (strong, nonatomic) Sound *acidDropSound;
@property (strong, nonatomic) Sound *beginWaveSound;
@property (strong, nonatomic) Sound *creepDeathSound;
@property (strong, nonatomic) Sound *dragTowerSound;
@property (strong, nonatomic) Sound *electricBoltSound;
@property (strong, nonatomic) Sound *explosionSound;
@property (strong, nonatomic) Sound *fireBoltSound;
@property (strong, nonatomic) Sound *goalHitSound;
@property (strong, nonatomic) Sound *iceBlastSound;
@property (strong, nonatomic) Sound *lazerBeamSound;
@property (strong, nonatomic) Sound *missileLaunchSound;
@property (strong, nonatomic) Sound *placeTowerSound;
@property (strong, nonatomic) Sound *plasmaBangSound;
@property (strong, nonatomic) Sound *sellTowerSound;
@property (strong, nonatomic) Sound *towerUpgradedSound;
@property (strong, nonatomic) Sound *toxicCloudSound;

@end

@implementation GameViewController

static Logger *logger = nil;
static bool isRunningiOS8 = false;

+ (void)initialize
{
    logger = [[Logger alloc] initWithClass:[GameViewController class]];
    isRunningiOS8 = SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0");
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    if (!self.context)
    {
        [logger error:@"Failed to create ES context"];
    }
    
    GLKView *view = (GLKView *)self.view;
    
    view.context = self.context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    view.userInteractionEnabled = YES;
    [view setMultipleTouchEnabled:YES];
    
    self.preferredFramesPerSecond = 60;
    
    self.beginWaveSound = [[Sound alloc] initWithSoundNamed:@"begin_wave.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:1];
    self.dragTowerSound = [[Sound alloc] initWithSoundNamed:@"drag_tower.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:1];
    self.placeTowerSound = [[Sound alloc] initWithSoundNamed:@"place_tower.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:1];
    self.sellTowerSound = [[Sound alloc] initWithSoundNamed:@"sell_tower.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:1];
    self.towerUpgradedSound = [[Sound alloc] initWithSoundNamed:@"tower_upgraded.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:1];
    self.creepDeathSound = [[Sound alloc] initWithSoundNamed:@"creep_death.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:3];
    self.lazerBeamSound = [[Sound alloc] initWithSoundNamed:@"lazer_beam.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:2];
    self.missileLaunchSound = [[Sound alloc] initWithSoundNamed:@"missile_launch.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:4];
    self.explosionSound = [[Sound alloc] initWithSoundNamed:@"explosion.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:4];
    self.iceBlastSound = [[Sound alloc] initWithSoundNamed:@"ice_blast.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:3];
    self.electricBoltSound = [[Sound alloc] initWithSoundNamed:@"electric_bolt.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:5];
    self.plasmaBangSound = [[Sound alloc] initWithSoundNamed:@"plasma_bang.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:5];
    self.fireBoltSound = [[Sound alloc] initWithSoundNamed:@"fire_bolt.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:4];
    self.acidDropSound = [[Sound alloc] initWithSoundNamed:@"acid_drop.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:2];
    self.toxicCloudSound = [[Sound alloc] initWithSoundNamed:@"toxic_cloud.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:2];
    self.goalHitSound = [[Sound alloc] initWithSoundNamed:@"goal_hit.caf" fromBundle:[NSBundle mainBundle] andMaxNumOfSimultaneousPlays:1];
    
    [EAGLContext setCurrentContext:self.context];
    
    CGRect screenBounds = [[UIScreen mainScreen] bounds];
    CGFloat screenScale = [[UIScreen mainScreen] scale];
    CGSize screenSize = CGSizeMake(screenBounds.size.width * screenScale, screenBounds.size.height * screenScale);
    
    CGSize newSize = CGSizeMake(screenSize.width, screenSize.height);
    newSize.width = roundf(newSize.width);
    newSize.height = roundf(newSize.height);
    
    if([Logger isDebugEnabled])
    {
        [logger debug:[NSString stringWithFormat:@"dimension %f x %f", newSize.width, newSize.height]];
    }
    
    init(self.levelIndex, self.difficultyLevel, isRunningiOS8);
    on_surface_created(newSize.width, newSize.height);
    on_surface_changed(newSize.width, newSize.height, [UIScreen mainScreen].applicationFrame.size.width, [UIScreen mainScreen].applicationFrame.size.height);
    on_resume();
    
    
    int highWave = [SaveData getHighWaveForDifficultyLevel:self.difficultyLevel andLevelIndex:self.levelIndex];
    _isMinimumWaveRequirementMet = highWave >= [LevelWaveRequirementMapper getWaveRequirementForLevelIndex:self.levelIndex];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(onPause)
                                                 name:UIApplicationWillResignActiveNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(onResume)
                                                 name:UIApplicationDidBecomeActiveNotification
                                               object:nil];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    [self onPause];
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [touches anyObject];
    CGPoint pos = [touch locationInView: [UIApplication sharedApplication].keyWindow];
    on_touch_down(pos.x, pos.y);
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [touches anyObject];
    CGPoint pos = [touch locationInView: [UIApplication sharedApplication].keyWindow];
    on_touch_dragged(pos.x, pos.y);
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [touches anyObject];
    CGPoint pos = [touch locationInView: [UIApplication sharedApplication].keyWindow];
    on_touch_up(pos.x, pos.y);
}

#pragma mark <GLKViewControllerDelegate>

- (void)update
{
    int screenState = get_state();
    switch (screenState)
    {
        case SCREEN_STATE_WAVE_COMPLETED:
            [self onWaveCompleted];
            clear_state();
        case SCREEN_STATE_NORMAL:
            update(self.timeSinceLastUpdate);
            break;
        case SCREEN_STATE_GAME_OVER:
            [self saveScore];
            clear_state();
            break;
        case SCREEN_STATE_EXIT:
            [self dismissViewControllerAnimated:NO completion:nil];
            break;
        default:
            break;
    }
}

#pragma mark <GLKViewDelegate>

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    present();
    [self handleSound];
    [self handleMusic];
}

#pragma mark <Private>

- (void)handleSound
{
    short soundId;
    while ((soundId = get_current_sound_id()) > 0)
    {
        switch (soundId)
        {
            case SOUND_ACID_DROP:
                [self.acidDropSound play];
                break;
            case SOUND_BEGIN_WAVE:
                [self.beginWaveSound play];
                break;
            case SOUND_CREEP_DEATH:
                [self.creepDeathSound play];
                break;
            case SOUND_DRAG_TOWER:
                [self.dragTowerSound play];
                break;
            case SOUND_ELECTRIC_BOLT:
                [self.electricBoltSound play];
                break;
            case SOUND_EXPLOSION:
                [self.explosionSound play];
                break;
            case SOUND_FIRE_BOLT:
                [self.fireBoltSound play];
                break;
            case SOUND_GOAL_HIT:
                [self.goalHitSound play];
                break;
            case SOUND_ICE_BLAST:
                [self.iceBlastSound play];
                break;
            case SOUND_LAZER_BEAM:
                [self.lazerBeamSound play];
                break;
            case SOUND_MISSILE_LAUNCH:
                [self.missileLaunchSound play];
                break;
            case SOUND_PLACE_TOWER:
                [self.placeTowerSound play];
                break;
            case SOUND_PLASMA_BANG:
                [self.plasmaBangSound play];
                break;
            case SOUND_SELL_TOWER:
                [self.sellTowerSound play];
                break;
            case SOUND_TOWER_UPGRADED:
                [self.towerUpgradedSound play];
                break;
            case SOUND_TOXIC_CLOUD:
                [self.toxicCloudSound play];
                break;
            default:
                continue;
        }
    }
}

- (void)handleMusic
{
    bool loadedNewTrack = false;
    short musicId = get_current_music_id();
    switch (musicId)
    {
        case MUSIC_STOP:
            [self.bgm stop];
            break;
        case MUSIC_PLAY_MAP_SPACE:
            self.bgm = [[Music alloc] initWithMusicNamed:@"bgm" fromBundle:[NSBundle mainBundle]];
            loadedNewTrack = true;
            break;
        default:
            break;
    }
    
    if(loadedNewTrack)
    {
        [self.bgm setLooping:true];
        [self.bgm setVolume:1.0f];
        [self.bgm play];
    }
}

- (void)onWaveCompleted
{
    int wave = get_wave();
    int levelIndex = get_level_index();
    
    if (!_isMinimumWaveRequirementMet && wave >= [LevelWaveRequirementMapper getWaveRequirementForLevelIndex:levelIndex])
    {
        _isMinimumWaveRequirementMet = YES;
        
        NSString *levelUnlockedMessage = NSLocalizedString([LevelWaveRequirementMapper getLevelUnLockedMessageStringForLevelIndex:levelIndex], nil);
        
        [self performSelectorOnMainThread:@selector(showToastWithMessage:) withObject:levelUnlockedMessage waitUntilDone:NO];
    }
}

- (void)saveScore
{
    int score = get_score();
    int wave = get_wave();
    int difficulty = get_difficulty();
    int levelIndex = get_level_index();
    
    [SaveData saveHighScore:score andHighWave:wave forDifficultyLevel:difficulty andLevelIndex:levelIndex];
}

- (void)showToastWithMessage:(NSString *)message
{
    [self.view makeToast:message];
}

- (void)onResume
{
    on_resume();
}

- (void)onPause
{
    [self.bgm stop];
    
    on_pause();
    
    [self saveScore];
}

@end