//
//  DSRenderer.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 8/20/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#include "DSRenderer.h"
#include "DSSpriteBatcher.h"
#include "DSRectangleBatcher.h"
#include "DSLineBatcher.h"
#include "DSCircleBatcher.h"
#include "Font.h"
#include "TextureWrapper.h"
#include "GameConstants.h"

#include <sstream>
#include <3ds.h>
#include <sf2d.h>
#include <stdio.h>
#include <string.h>

extern "C"
{
    extern const struct
    {
        unsigned int width;
        unsigned int height;
        unsigned int bytes_per_pixel;
        unsigned char pixel_data[];
    } background;

    extern const struct
    {
        unsigned int width;
        unsigned int height;
        unsigned int bytes_per_pixel;
        unsigned char pixel_data[];
    } creeps;

    extern const struct
    {
        unsigned int width;
        unsigned int height;
        unsigned int bytes_per_pixel;
        unsigned char pixel_data[];
    } spawn_platforms_projectiles_towers;

    extern const struct
    {
        unsigned int width;
        unsigned int height;
        unsigned int bytes_per_pixel;
        unsigned char pixel_data[];
    } loose_objects_explosions;

    extern const struct
    {
        unsigned int width;
        unsigned int height;
        unsigned int bytes_per_pixel;
        unsigned char pixel_data[];
    } top_level_ui;
}

sf2d_texture *backgroundTex;
sf2d_texture *creepsTex;
sf2d_texture *spawnPlatformsProjectilesTowersTex;
sf2d_texture *looseObjectsTex;
sf2d_texture *topLevelUiTex;

DSRenderer::DSRenderer(gfxScreen_t screen, int screenWidth, int screenHeight) : Renderer(), m_screen(screen)
{
    m_spriteBatcher = std::unique_ptr<DSSpriteBatcher>(new DSSpriteBatcher(screen, screenWidth, screenHeight));
    m_rectangleBatcher = std::unique_ptr<DSRectangleBatcher>(new DSRectangleBatcher(screen, screenWidth, screenHeight, false));
    m_lineBatcher = std::unique_ptr<DSLineBatcher>(new DSLineBatcher(screen, screenWidth, screenHeight));
    m_circleBatcher = std::unique_ptr<DSCircleBatcher>(new DSCircleBatcher());

    backgroundTex = sf2d_create_texture_mem_RGBA8(background.pixel_data, background.width, background.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
    creepsTex = sf2d_create_texture_mem_RGBA8(creeps.pixel_data, creeps.width, creeps.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
    spawnPlatformsProjectilesTowersTex = sf2d_create_texture_mem_RGBA8(spawn_platforms_projectiles_towers.pixel_data, spawn_platforms_projectiles_towers.width, spawn_platforms_projectiles_towers.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
    looseObjectsTex = sf2d_create_texture_mem_RGBA8(loose_objects_explosions.pixel_data, loose_objects_explosions.width, loose_objects_explosions.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
    topLevelUiTex = sf2d_create_texture_mem_RGBA8(top_level_ui.pixel_data, top_level_ui.width, top_level_ui.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);

    m_backgroundTexture = std::unique_ptr<TextureWrapper>(new TextureWrapper(backgroundTex));
    m_creepsTexture = std::unique_ptr<TextureWrapper>(new TextureWrapper(creepsTex));
    m_spawnPlatformsProjectilesTowersTexture = std::unique_ptr<TextureWrapper>(new TextureWrapper(spawnPlatformsProjectilesTowersTex));
    m_looseObjectsTexture = std::unique_ptr<TextureWrapper>(new TextureWrapper(looseObjectsTex));
    m_topLevelUiTexture = std::unique_ptr<TextureWrapper>(new TextureWrapper(topLevelUiTex));
}

DSRenderer::~DSRenderer()
{
    cleanUp();
}

void DSRenderer::clearScreenWithColor(float r, float g, float b, float a)
{
    sf2d_set_clear_color(RGBA8((int) (r * 255), (int) (g * 255), (int) (b * 255), (int) (a * 255)));
}

void DSRenderer::beginFrame()
{
    sf2d_start_frame(m_screen, GFX_LEFT);
}

void DSRenderer::endFrame()
{
    sf2d_end_frame();

    sf2d_swapbuffers();
}

void DSRenderer::cleanUp()
{
    sf2d_free_texture(backgroundTex);
    sf2d_free_texture(creepsTex);
    sf2d_free_texture(spawnPlatformsProjectilesTowersTex);
    sf2d_free_texture(looseObjectsTex);
    sf2d_free_texture(topLevelUiTex);
}