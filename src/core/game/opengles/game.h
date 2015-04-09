//
//  game.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef GAME_H
#define GAME_H

void init(int levelIndex, int difficulty, bool isRunningIOS8);

void on_surface_created(int pixelWidth, int pixelHeight);

void on_surface_changed(int pixelWidth, int pixelHeight, int dpWidth, int dpHeight);

void on_resume();

void on_pause();

void update(float deltaTime);

void present();

void on_touch_down(float raw_touch_x, float raw_touch_y);

void on_touch_dragged(float raw_touch_x, float raw_touch_y);

void on_touch_up(float raw_touch_x, float raw_touch_y);

short get_current_music_id();

short get_current_sound_id();

int get_state();

void clear_state();

int get_level_index();

int get_difficulty();

int get_wave();

int get_score();

bool is_at_max_health();

bool handle_on_back_pressed();

#endif /* GAME_H */