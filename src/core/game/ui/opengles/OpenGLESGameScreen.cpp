//
//  OpenGLESGameScreen.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "macros.h"
#include "OpenGLESGameScreen.h"
#include "TouchEvent.h"
#include "Vector2D.h"
#include "OpenGLESRenderer.h"
#include "OpenGLESManager.h"
#include "GameConstants.h"
#include "Font.h"
#include "SpriteBatcher.h"
#include "RectangleBatcher.h"
#include "LineBatcher.h"
#include "CircleBatcher.h"
#include "GameListener.h"
#include "BackgroundElements.h"
#include "TimeButton.h"
#include "Dialog.h"
#include "TouchCursor.h"
#include "Text.h"
#include "Asteroid.h"
#include "ShipModule.h"
#include "CoreShipModule.h"
#include "TowerCursor.h"
#include "Rectangle.h"
#include "TowerOptionButton.h"
#include "Circle.h"

OpenGLESGameScreen::OpenGLESGameScreen(int levelIndex, int difficulty) : GameScreen(levelIndex, difficulty)
{
    // Empty
}

void OpenGLESGameScreen::initGraphics(int screenWidth, int screenHeight)
{
    OGLESManager->init(screenWidth, screenHeight, GAME_WIDTH, GAME_HEIGHT);
    
    m_renderer = std::unique_ptr<OpenGLESRenderer>(new OpenGLESRenderer());
}

void OpenGLESGameScreen::platformResume()
{
    // Empty
}

void OpenGLESGameScreen::platformPause()
{
    // Empty
}
