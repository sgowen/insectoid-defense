//
//  GameConstants.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 5/13/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#define GAME_WIDTH 15.90f
#define GAME_HEIGHT 11.00f

#define WORLD_WIDTH 11
#define WORLD_HEIGHT 9

#define GAME_X 0.80f
#define GAME_Y 0.60f

#define DIRECTION_RIGHT 0
#define DIRECTION_UP 1
#define DIRECTION_LEFT 2
#define DIRECTION_DOWN 3

/// Should be moved into separate files

// Creep Params
#define HEALTH_BAR_WIDTH 0.7f
#define HEALTH_BAR_HEIGHT 0.1f
#define SIZE_TO_BOUNDS_RATIO 0.48f
#define TIME_FOR_POISON_DAMAGE 1.0f

// Creep Condition
#define HEALTHY 0
#define FROZEN 1
#define ELECTRIFIED 2
#define ON_FIRE 4
#define FIRE_RECOVERY 8
#define POISONED 16

// Creep State
#define ALIVE 0
#define DEAD 1
#define DEPLOYING 2
#define GOAL_POINT_REACHED 4
#define GOAL_REACHED 8
#define SET_TO_REMOVE 16

// Spawn
#define TIME_TO_SPAWN_CREEP 1.0f

#endif /* GAME_CONSTANTS_H */
