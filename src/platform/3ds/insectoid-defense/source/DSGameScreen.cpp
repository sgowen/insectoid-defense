//
//  DSGameScreen.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 8/20/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#include "DSGameScreen.h"
#include "TouchEvent.h"
#include "Vector2D.h"
#include "DSRenderer.h"
#include "GameConstants.h"
#include "SpriteBatcher.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Font.h"
#include "RectangleBatcher.h"
#include "LineBatcher.h"
#include "CircleBatcher.h"
#include "BackgroundElements.h"
#include "TimeButton.h"
#include "Dialog.h"
#include "TouchCursor.h"
#include "Text.h"
#include "Asteroid.h"
#include "ShipModule.h"
#include "CoreShipModule.h"
#include "TowerCursor.h"
#include "TowerOptionButton.h"
#include "TopScreenRenderer.h"
#include "World.h"

#include <3ds.h>

#include <sf2d.h>

#include <string.h>

DSGameScreen::DSGameScreen(int levelIndex, int difficulty, int topScreenWidth, int topScreenHeight, int bottomScreenWidth, int bottomScreenHeight) : GameScreen(levelIndex, difficulty)
{
    sf2d_init(GAME_WIDTH, GAME_HEIGHT, GAME_WIDTH, GAME_HEIGHT);

    m_renderer = std::unique_ptr<DSRenderer>(new DSRenderer(GFX_BOTTOM, bottomScreenWidth, bottomScreenHeight));
    topScreenRenderer = new TopScreenRenderer(GFX_TOP, 400, 240);

    m_iTopScreenWidth = topScreenWidth;
    m_iTopScreenHeight = topScreenHeight;
    m_iBottomScreenWidth = bottomScreenWidth;
    m_iBottomScreenHeight = bottomScreenHeight;
    
    init();
}

void DSGameScreen::touchToWorld(TouchEvent &touchEvent)
{
    float x = (touchEvent.getX() / (float) m_iBottomScreenWidth) * GAME_WIDTH;
    float y = (((float) m_iBottomScreenHeight) - touchEvent.getY()) / ((float) m_iBottomScreenHeight) * GAME_HEIGHT;

    m_touchPoint->set(x, y);
}

void DSGameScreen::platformResume()
{
    // Empty
}

void DSGameScreen::platformPause()
{
    // Empty
}

void DSGameScreen::init()
{
    GameScreen::init();

    m_scoreText->setX(0.5f);
    m_scoreText->setY(1.5f);
    m_scoreText->setWidth(1.0f);
    m_scoreText->setHeight(1.0f);

    m_statusText->setX(0.5f);
    m_statusText->setY(0.5f);
    m_statusText->setWidth(1.0f);
    m_statusText->setHeight(1.0f);

    m_fundsText->setX(11.9f);
    m_fundsText->setY(1.5f);
    m_fundsText->setWidth(1.0f);
    m_fundsText->setHeight(1.0f);

    m_adjustFundsText->setX(m_fundsText->getX());
    m_adjustFundsText->setY(m_fundsText->getY() - 1.0f);
    m_adjustFundsText->setWidth(m_fundsText->getWidth());
    m_adjustFundsText->setHeight(m_fundsText->getHeight());

    for (std::vector < std::unique_ptr < TowerCursor >> ::iterator itr = m_backgroundElements->getTowerCursors().begin(); itr != m_backgroundElements->getTowerCursors().end(); ++itr)
    {
        (*itr)->getCostText().setHeight(0.44f);
    }
}

void DSGameScreen::render()
{
    m_renderer->clearScreenWithColor(0, 0, 0, 1);

    m_renderer->beginFrame();

    m_renderer->renderBackground(*m_backgroundElements);

    m_renderer->renderBackgroundOverlay(*m_backgroundElements, *m_timeButton);

    m_renderer->renderWorldAndTouchCursor(*World::getInstance(), *m_touchCursor);

    m_renderer->renderTowerMenu(*m_backgroundElements);

    if (m_gameState == PAUSED)
    {
        m_renderer->renderDialog(*m_pausedDialog);
    }
    else if (m_gameState == GAME_OVER)
    {
        m_renderer->renderDialog(*m_gameOverDialog);
    }

    m_renderer->endFrame();

    topScreenRenderer->beginFrame();

    topScreenRenderer->render();
    
    topScreenRenderer->renderDividerLine();

    topScreenRenderer->renderText(m_renderer->getTopLevelUiTexture(), *m_statusText);
    topScreenRenderer->renderText(m_renderer->getTopLevelUiTexture(), *m_scoreText);
    topScreenRenderer->renderText(m_renderer->getTopLevelUiTexture(), *m_fundsText);
    topScreenRenderer->renderText(m_renderer->getTopLevelUiTexture(), *m_adjustFundsText);

    topScreenRenderer->endFrame();
}

void DSGameScreen::exit()
{
    m_renderer->cleanUp();

    sf2d_fini();
}