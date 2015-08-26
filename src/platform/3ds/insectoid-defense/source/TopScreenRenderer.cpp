//
//  TopScreenRenderer.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 8/25/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#include "TopScreenRenderer.h"
#include "DSSpriteBatcher.h"
#include "DSLineBatcher.h"
#include "GameConstants.h"
#include "ResourceConstants.h"
#include "SpriteBatcher.h"
#include "RectangleBatcher.h"
#include "Line.h"
#include "Circle.h"
#include "Color.h"
#include "CircleBatcher.h"
#include "TextureRegion.h"
#include "Assets.h"
#include "Vector2D.h"
#include "Font.h"
#include "TextureWrapper.h"
#include "Rectangle.h"
#include "PhysicalEntity.h"
#include "World.h"
#include "BackgroundElements.h"
#include "TouchCursor.h"
#include "TimeButton.h"
#include "Text.h"
#include "Dialog.h"
#include "Asteroid.h"
#include "ShipModule.h"
#include "CoreShipModule.h"
#include "Spawn.h"
#include "WorldPlatform.h"
#include "Creep.h"
#include "Tower.h"
#include "Missile.h"
#include "IceBlast.h"
#include "FireBolt.h"
#include "AcidDrop.h"
#include "LazerBeam.h"
#include "ElectricBolt.h"
#include "Projectile.h"
#include "Explosion.h"
#include "CreepBodyPartType.h"
#include "ToxicCloud.h"
#include "CreepBodyPart.h"
#include "Creep.h"
#include "GameConstants.h"
#include "ProjectileParticle.h"
#include "TowerCursor.h"
#include "TowerOptionButton.h"

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
        unsigned int bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */
        unsigned char pixel_data[];
    } top_screen_title;
}

sf2d_texture *topScreenTitleTex;

TopScreenRenderer::TopScreenRenderer(gfxScreen_t screen, int screenWidth, int screenHeight) : m_screen(screen)
{
    m_font = std::unique_ptr<Font>(new Font(FONT_TEXTURE_REGION_X, FONT_TEXTURE_REGION_Y, FONT_GLYPHS_PER_ROW, FONT_GLYPH_WIDTH, FONT_GLYPH_HEIGHT, TEXTURE_SIZE_512x512, TEXTURE_SIZE_512x512));
    m_spriteBatcher = std::unique_ptr<DSSpriteBatcher>(new DSSpriteBatcher(screen, screenWidth, screenHeight));
    m_lineBatcher = std::unique_ptr<DSLineBatcher>(new DSLineBatcher(screen, screenWidth, screenHeight));

    topScreenTitleTex = sf2d_create_texture_mem_RGBA8(top_screen_title.pixel_data, top_screen_title.width, top_screen_title.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);

    m_topScreenTitleTexture = std::unique_ptr<TextureWrapper>(new TextureWrapper(topScreenTitleTex));
}

void TopScreenRenderer::beginFrame()
{
    sf2d_start_frame(m_screen, GFX_LEFT);
}

void TopScreenRenderer::render()
{
    static TextureRegion tr = TextureRegion(0.0f, 0.0f, 400.0f, 196.0f, 512.0f, 512.0f);
    m_spriteBatcher->beginBatch();
    m_spriteBatcher->drawSprite(GAME_WIDTH / 2, (GAME_HEIGHT - 2) / 2 + 2, GAME_WIDTH, GAME_HEIGHT - 2, 0, tr);
    m_spriteBatcher->endBatchWithTexture(*m_topScreenTitleTexture);
}

void TopScreenRenderer::renderDividerLine()
{
    static Line line = Line(0, 2, GAME_WIDTH, 2);
    static Color color = Color(1, 1, 1, 1);
    m_lineBatcher->beginBatch();
    m_lineBatcher->renderLine(line, color);
    m_lineBatcher->endBatch();
}

void TopScreenRenderer::renderText(TextureWrapper &textureWrapper, Text &t)
{
    m_spriteBatcher->beginBatch();

    std::string text = t.getText();
    m_font->renderText(*m_spriteBatcher, text, t.getX(), t.getY(), t.getWidth(), t.getHeight(), t.getColor());

    m_spriteBatcher->endBatchWithTexture(textureWrapper);
}

void TopScreenRenderer::endFrame()
{
    sf2d_end_frame();
}

void TopScreenRenderer::cleanUp()
{
    sf2d_free_texture(topScreenTitleTex);
}