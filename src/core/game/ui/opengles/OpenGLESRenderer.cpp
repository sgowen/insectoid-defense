//
//  OpenGLESRenderer.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "OpenGLESRenderer.h"
#include "OpenGLESSpriteBatcher.h"
#include "OpenGLESRectangleBatcher.h"
#include "OpenGLESLineBatcher.h"
#include "OpenGLESCircleBatcher.h"
#include "Font.h"
#include "TextureWrapper.h"

extern "C"
{
#include "asset_utils.h"
#include "platform_gl.h"
}

OpenGLESRenderer::OpenGLESRenderer() : Renderer()
{
    m_spriteBatcher = std::unique_ptr<OpenGLESSpriteBatcher>(new OpenGLESSpriteBatcher());
    m_rectangleBatcher = std::unique_ptr<OpenGLESRectangleBatcher>(new OpenGLESRectangleBatcher(false));
    m_lineBatcher = std::unique_ptr<OpenGLESLineBatcher>(new OpenGLESLineBatcher());
    m_circleBatcher = std::unique_ptr<OpenGLESCircleBatcher>(new OpenGLESCircleBatcher());
    
    m_backgroundTexture = std::unique_ptr<TextureWrapper>(new TextureWrapper(load_png_asset_into_texture("background_texture.png")));
    m_creepsTexture = std::unique_ptr<TextureWrapper>(new TextureWrapper(load_png_asset_into_texture("creeps.png")));
    m_spawnPlatformsProjectilesTowersTexture = std::unique_ptr<TextureWrapper>(new TextureWrapper(load_png_asset_into_texture("spawn_platforms_projectiles_towers.png")));
    m_looseObjectsTexture = std::unique_ptr<TextureWrapper>(new TextureWrapper(load_png_asset_into_texture("loose_objects_explosions.png")));
    m_topLevelUiTexture = std::unique_ptr<TextureWrapper>(new TextureWrapper(load_png_asset_into_texture("top_level_ui.png")));
}

void OpenGLESRenderer::clearScreenWithColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void OpenGLESRenderer::beginFrame()
{
    glEnable(GL_TEXTURE_2D);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGLESRenderer::endFrame()
{
    glDisable(GL_BLEND);
    
    glDisable(GL_TEXTURE_2D);
}

void OpenGLESRenderer::cleanUp()
{
    // TODO
}