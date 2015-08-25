//
//  GameScreen.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "GameScreen.h"
#include "GameListener.h"
#include "TouchEvent.h"
#include "Vector2D.h"
#include "Renderer.h"
#include "Assets.h"
#include "ResourceConstants.h"
#include "Font.h"
#include "SpriteBatcher.h"
#include "RectangleBatcher.h"
#include "LineBatcher.h"
#include "CircleBatcher.h"
#include "LevelUtils.h"
#include "BackgroundElements.h"
#include "World.h"
#include "TimeButton.h"
#include "Dialog.h"
#include "TouchCursor.h"
#include "Text.h"
#include "CoreShipModule.h"
#include "Circle.h"
#include "TowerCursor.h"
#include "TowerCostMapper.h"
#include "GameListener.h"
#include "ResourceConstants.h"
#include "TowerOptionButton.h"
#include "Tower.h"
#include "ShipModule.h"
#include "Asteroid.h"
#include "Rectangle.h"
#include "ScreenState.h"
#include "CoreShipModule.h"

#include <sstream>

GameScreen::GameScreen(int levelIndex, int difficulty)
{
    m_iLevelIndex = levelIndex;
    m_iDifficulty = difficulty;
    m_iPointsScalar = LevelUtils::getPointsScalarForDifficulty(difficulty);
    
    init();
}

void GameScreen::init()
{
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    m_touchEventsPool.push_back(TouchEvent(0, 0, Touch_Type::DOWN));
    
    m_backgroundElements = std::unique_ptr<BackgroundElements>(new BackgroundElements(m_iLevelIndex));
    World::getInstance()->reset(m_iLevelIndex, m_iDifficulty);
    
    m_timeButton = std::unique_ptr<TimeButton>(new TimeButton(1.1925f, 10.40375f, 2.385f, 1.1925f));
    m_pausedDialog = std::unique_ptr<Dialog>(new Dialog("Paused!", "Exit", "Resume"));
    m_gameOverDialog = std::unique_ptr<Dialog>(new Dialog("Game Over!", "Exit", "Retry"));
    
    m_touchPoint = std::unique_ptr<Vector2D>(new Vector2D());
    m_touchCursor = std::unique_ptr<TouchCursor>(new TouchCursor(0, 0));
    
    m_iFunds = LevelUtils::calculateStartingFunds(m_iLevelIndex, m_iDifficulty);
    std::stringstream ss;
    ss << "$" << m_iFunds;
    
    m_iScore = 0;
    std::string scoreString = "00000000";
    m_iScoreLength = scoreString.length();
    
    m_scoreText = std::unique_ptr<Text>(new Text(scoreString, 0.15f, 9.6f, 0.30f, 0.30f, 1, 1, 1, 1));
    m_statusText = std::unique_ptr<Text>(new Text("Wave:  0", 0.15f, 9.28f, 0.30f, 0.30f, 1, 1, 1, 1));
    m_fundsText = std::unique_ptr<Text>(new Text(ss.str(), 14.605f, 10.675f, 0.30f, 0.30f, 0, 1, 0, 1));
    m_adjustFundsText = std::unique_ptr<Text>(new Text("", m_fundsText->getX(), m_fundsText->getY() - 0.32f, m_fundsText->getWidth(), m_fundsText->getHeight(), 1, 0, 0, 1));
    
    updateFundsTextAndTowerCursors();
    
    m_gameState = RUNNING;
    m_iScreenState = SCREEN_STATE_NORMAL;
}

void GameScreen::onResume()
{
	if(m_gameState == RUNNING)
	{
        Assets::getInstance()->setMusicId(MUSIC_PLAY_MAP_SPACE);
        
        platformResume();
	}
}

void GameScreen::onPause()
{
    m_gameState = Game_State::PAUSED;
    
    Assets::getInstance()->setMusicId(MUSIC_STOP);
    
    platformPause();
}

void GameScreen::update(float deltaTime)
{
    for (std::vector<TouchEvent>::iterator itr = m_touchEvents.begin(); itr != m_touchEvents.end(); itr++)
    {
        if (m_touchEventsPool.size() < 50)
        {
            m_touchEventsPool.push_back(*itr);
        }
    }
    
    m_touchEvents.clear();
    m_touchEvents.swap(m_touchEventsBuffer);
    m_touchEventsBuffer.clear();
    
    m_backgroundElements->update(deltaTime);
    
    switch(m_gameState)
    {
        case RUNNING:
            updateRunning(deltaTime * m_timeButton->getSpeedScalar());
            updateInputRunning();
            
            if(World::getInstance()->getScoredEarnedThisFrame() > 0)
            {
                addToScore(World::getInstance()->getScoredEarnedThisFrame());
            }
            
            if(World::getInstance()->getTimesCoreShipModuleHitThisFrame() > 0)
            {
                for(int i = 0; i < World::getInstance()->getTimesCoreShipModuleHitThisFrame(); i++)
                {
                    coreShipModuleHit();
                }
            }
            break;
        case PAUSED:
            updateInputPaused();
            break;
        case GAME_OVER:
            updateInputGameOver();
            break;
    }
}

void GameScreen::render()
{
    m_renderer->clearScreenWithColor(0, 0, 0, 1);
    
    m_renderer->beginFrame();
    
    m_renderer->renderBackground(*m_backgroundElements);
    
    m_renderer->renderBackgroundOverlay(*m_backgroundElements, *m_timeButton);
    
    m_renderer->renderWorldAndTouchCursor(*World::getInstance(), *m_touchCursor);
    
    m_renderer->renderTowerMenu(*m_backgroundElements);
    
    m_renderer->renderText(*m_statusText);
    m_renderer->renderText(*m_scoreText);
    m_renderer->renderText(*m_fundsText);
    m_renderer->renderText(*m_adjustFundsText);
    
    if (m_gameState == PAUSED)
    {
        m_renderer->renderDialog(*m_pausedDialog);
    }
    else if (m_gameState == GAME_OVER)
    {
        m_renderer->renderDialog(*m_gameOverDialog);
    }
    
    m_renderer->endFrame();
}

int GameScreen::getLevelIndex()
{
    return m_iLevelIndex;
}

int GameScreen::getDifficulty()
{
    return m_iDifficulty;
}

int GameScreen::getWave()
{
    return World::getInstance()->getWave();
}

int GameScreen::getScore()
{
    return m_iScore;
}

bool GameScreen::isAtMaxHealth()
{
    return m_backgroundElements->getCoreShipModule().isAtMaxHealth();
}

int GameScreen::getState()
{
	return m_iScreenState;
}

void GameScreen::clearState()
{
    m_iScreenState = SCREEN_STATE_NORMAL;
}

short GameScreen::getCurrentSoundId()
{
    short playThisSound = Assets::getInstance()->getFirstSoundId();
    Assets::getInstance()->eraseFirstSoundId();
    return playThisSound;
}

short GameScreen::getCurrentMusicId()
{
    short musicId = Assets::getInstance()->getMusicId();
    Assets::getInstance()->setMusicId(0);
    return musicId;
}

void GameScreen::onTouch(Touch_Type type, float raw_touch_x, float raw_touch_y)
{
    if (type == Touch_Type::DRAGGED && m_touchEventsBuffer.size() > 3)
    {
        return;
    }
    
    addTouchEventForType(type, raw_touch_x, raw_touch_y);
}

#pragma mark <Private>

TouchEvent GameScreen::newTouchEvent()
{
    if (m_touchEventsPool.size() == 0)
    {
        return TouchEvent(0, 0, Touch_Type::DOWN);
    }
    else
    {
        TouchEvent touchEvent = m_touchEventsPool.back();
        m_touchEventsPool.pop_back();
        return touchEvent;
    }
}

void GameScreen::addTouchEventForType(Touch_Type touchType, float x, float y)
{
    TouchEvent touchEvent = newTouchEvent();
    touchEvent.setTouchType(touchType);
    touchEvent.setX(x);
    touchEvent.setY(y);
    
    m_touchEventsBuffer.push_back(touchEvent);
}

void GameScreen::updateRunning(float deltaTime)
{
    World_Update_Response response = World::getInstance()->update(deltaTime);
    
    if(response == World_Update_Response::WAVE_SPAWNED)
    {
        waveSpawned();
    }
    else if(response == World_Update_Response::WAVE_COMPLETED)
    {
        waveCompleted();
    }
    
    m_backgroundElements->getCoreShipModule().update(deltaTime);
    
    if (m_backgroundElements->isUpgradeSellMenuShowing() && m_touchCursor->shouldUpdateTowerInformation())
    {
        if (m_touchCursor->isVisible())
        {
            m_touchPoint->set(m_touchCursor->getDisplayCircle().getCenter());
            updateAndHandleTouchCursor();
        }
        
        adjustUpgradeTowerButtonColor();
        adjustUpgradeSellTexts();
    }
}

void GameScreen::updateInputRunning()
{
    for (std::vector<TouchEvent>::iterator itr = m_touchEvents.begin(); itr != m_touchEvents.end(); itr++)
	{
		touchToWorld((*itr));
		
		switch (itr->getTouchType())
		{
            case DOWN:
                if (m_backgroundElements->isUpgradeSellMenuShowing())
                {
                    if (m_backgroundElements->isTouchInTowerSelectionMenuArea(*m_touchPoint))
                    {
                        handleTouchDownInUpgradeSellMenu();
                    }
                    else
                    {
                        m_backgroundElements->setUpgradeSellMenuShowing(false);
                        m_touchCursor->setVisibility(false);
                    }
                }
                else
                {
                    // handle the user selecting a tower
                    if (m_backgroundElements->isTouchInTowerSelectionMenuArea(*m_touchPoint))
                    {
                        int selectedTowerCost;
                        if ((selectedTowerCost = m_backgroundElements->handleTouchDownInTowerSelectionMenu(*m_touchPoint)) > 0)
                        {
                            setAdjustFundsText(selectedTowerCost, false);
                        }
                    }
                }
                continue;
            case DRAGGED:
                if (m_backgroundElements->isUpgradeSellMenuShowing())
                {
                    if (m_backgroundElements->isTouchInTowerSelectionMenuArea(*m_touchPoint))
                    {
                        handleTouchDownInUpgradeSellMenu();
                    }
                }
                else
                {
                    if (m_backgroundElements->isTowerSelected())
                    {
                        m_backgroundElements->setSelectedTowerPosition(*m_touchPoint);
                        World::getInstance()->updateTowerCursor(m_backgroundElements->getSelectedTowerCursor());
                    }
                }
                continue;
            case UP:
                if (m_backgroundElements->isUpgradeSellMenuShowing())
                {
                    if (m_backgroundElements->isTouchInTowerSelectionMenuArea(*m_touchPoint))
                    {
                        handleTouchUpInUpgradeSellMenu();
                    }
                }
                else
                {
                    if (m_backgroundElements->isTowerSelected())
                    {
                        if (World::getInstance()->placeTower(m_backgroundElements->getSelectedTowerCursor()))
                        {
                            m_iFunds -= TowerCostMapper::getCostForTowerType(m_backgroundElements->getSelectedTowerCursor().getTowerType());
                            updateFundsTextAndTowerCursors();
                            m_backgroundElements->reset();
                        }
                        
                        m_adjustFundsText->setText("");
                        m_backgroundElements->reset();
                    }
                    else
                    {
                        updateAndHandleTouchCursor();
                        
                        if (m_touchCursor->isTowerLockAcquired())
                        {
                            m_backgroundElements->setUpgradeSellMenuShowing(true);
                            adjustUpgradeTowerButtonColor();
                            adjustUpgradeSellTexts();
                        }
                        else
                        {
                            if (World::getInstance()->handleTouchUp(*m_touchPoint))
                            {
                                waveCompleted();
                                waveSpawned();
                            }
                            else if(m_timeButton->isTouching(*m_touchPoint))
                            {
                                if(m_timeButton->handleTouch(*m_touchPoint))
                                {
                                    onPause();
                                }
                            }
                        }
                    }
                }
                return;
		}
	}
}

void GameScreen::updateInputPaused()
{
    for (std::vector<TouchEvent>::iterator itr = m_touchEvents.begin(); itr != m_touchEvents.end(); itr++)
    {
        touchToWorld((*itr));
        
        switch(itr->getTouchType())
        {
            case DOWN:
                return;
            case DRAGGED:
                continue;
            case UP:
                if(m_pausedDialog->isTouchingRightButton(*m_touchPoint))
                {
                    m_gameState = Game_State::RUNNING;
                    onResume();
                }
                else if(m_pausedDialog->isTouchingLeftButton(*m_touchPoint))
                {
                    m_iScreenState = SCREEN_STATE_EXIT;
                }
                return;
        }
    }
}

void GameScreen::updateInputGameOver()
{
    for (std::vector<TouchEvent>::iterator itr = m_touchEvents.begin(); itr != m_touchEvents.end(); itr++)
    {
        touchToWorld((*itr));
        
        switch(itr->getTouchType())
        {
            case DOWN:
                return;
            case DRAGGED:
                continue;
            case UP:
                if(m_gameOverDialog->isTouchingRightButton(*m_touchPoint))
                {
                    init();
                    onResume();
                }
                else if(m_pausedDialog->isTouchingLeftButton(*m_touchPoint))
                {
                    m_iScreenState = SCREEN_STATE_EXIT;
                }
                return;
        }
    }
}

void GameScreen::handleTouchDownInUpgradeSellMenu()
{
    if (m_touchCursor->isTowerLockAcquired())
    {
        if (m_backgroundElements->getSellTowerButton().isTouching(*m_touchPoint))
        {
            setAdjustFundsText(m_touchCursor->getSelectedTower()->getSellAmount(), true);
        }
        else if (m_backgroundElements->getUpgradeTowerButton().isTouching(*m_touchPoint) && m_touchCursor->canTowerBeUpgraded())
        {
            setAdjustFundsText(m_touchCursor->getSelectedTower()->getUpgradeCost(), false);
        }
        else
        {
            m_adjustFundsText->setText("");
        }
    }
    else
    {
        m_adjustFundsText->setText("");
    }
}

void GameScreen::updateAndHandleTouchCursor()
{
    m_touchCursor->setPosition(*m_touchPoint);
    World::getInstance()->updateTouchCursor(*m_touchCursor);
    m_touchCursor->setVisibility(m_touchCursor->isTowerLockAcquired());
}

void GameScreen::handleTouchUpInUpgradeSellMenu()
{
    if (m_backgroundElements->getSellTowerButton().isTouching(*m_touchPoint))
    {
        addToFunds(m_touchCursor->getSelectedTower()->getSellAmount());
        World::getInstance()->removeSelectedTower(*m_touchCursor);
        m_backgroundElements->setUpgradeSellMenuShowing(false);
        
        GameListener::getInstance()->playSound(SOUND_SELL_TOWER);
    }
    else if (m_backgroundElements->getUpgradeTowerButton().isTouching(*m_touchPoint) && m_touchCursor->canTowerBeUpgraded() && m_touchCursor->canAffordUpgrade(m_iFunds))
    {
        m_iFunds -= m_touchCursor->getSelectedTower()->getUpgradeCost();
        m_touchCursor->getSelectedTower()->upgrade();
        
        GameListener::getInstance()->playSound(SOUND_PLACE_TOWER);
    }
    
    updateFundsTextAndTowerCursors();
    m_adjustFundsText->setText("");
}

void GameScreen::addToFunds(int addition)
{
    m_iFunds += addition;
    
    if (m_iFunds > 999)
    {
        m_iFunds = 999;
    }
}

void GameScreen::setAdjustFundsText(int amount, bool isPositive)
{
    std::stringstream ss;
    ss << "" << amount;
    
    std::string text = ss.str();
    std::string prefix = isPositive ? "+" : "-";
    
    unsigned long padding = m_fundsText->getText().length() - text.length() - 1;
    
    if(padding > 0)
    {
        for (unsigned int i = 0; i < padding; i++)
        {
            prefix.append(" ");
        }
    }
    
    prefix.append(text);
    
    m_adjustFundsText->setText(prefix);
    m_adjustFundsText->setColor(isPositive ? 0 : 1, isPositive ? 1 : 0, 0, 1);
}

void GameScreen::updateFundsTextAndTowerCursors()
{
    std::stringstream ss;
    ss << "$" << m_iFunds;
    std::string fundsString = ss.str();
    
    m_fundsText->setText(fundsString);
    m_backgroundElements->handleFundsChanged(m_iFunds, World::getInstance()->isAtLeastOnePlatformAvailable());
    adjustUpgradeTowerButtonColor();
}

void GameScreen::adjustUpgradeTowerButtonColor()
{
    bool canTowerBeUpgraded = m_touchCursor->canTowerBeUpgraded();
    bool canAffordTowerUpgrade = m_touchCursor->canAffordUpgrade(m_iFunds);
    m_backgroundElements->getUpgradeTowerButton().setBorderColor(1, 0, 0, canTowerBeUpgraded ? canAffordTowerUpgrade ? 1 : 0.33f : 0);
    m_backgroundElements->getUpgradeTowerButton().setTextColor(1, 1, 1, canTowerBeUpgraded ? canAffordTowerUpgrade ? 1 : 0.33f : 0);
}

void GameScreen::adjustUpgradeSellTexts()
{
    if (m_touchCursor->isTowerLockAcquired())
    {
        int upgradeCost = m_touchCursor->getSelectedTower()->getUpgradeCost();
        
        std::stringstream ss;
        
        if(upgradeCost < 100)
        {
            ss << " ";
        }
        
        ss << "$" << upgradeCost;
        
        std::string upgradeCostString = ss.str();
        
        m_backgroundElements->getUpgradeTowerButton().getFundsText().setText(upgradeCostString);
        
        int sellAmount = m_touchCursor->getSelectedTower()->getSellAmount();
        std::stringstream ss2;
        if(sellAmount < 100)
        {
            ss2 << " ";
        }
        
        if(sellAmount < 10)
        {
            ss2 << " ";
        }
        
        ss2 << "$" << sellAmount;
        
        std::string sellAmountString = ss2.str();
        m_backgroundElements->getSellTowerButton().getFundsText().setText(sellAmountString);
    }
}

#pragma mark <World Callback>

void GameScreen::waveCompleted()
{
    m_iScreenState = SCREEN_STATE_WAVE_COMPLETED;
}

void GameScreen::waveSpawned()
{
    std::stringstream ss;
    
    ss << "Wave:";
    
    if(World::getInstance()->getWave() < 10)
    {
        ss << "  ";
    }
    else if(World::getInstance()->getWave() < 100)
    {
        ss << " ";
    }
    
    ss << "" << World::getInstance()->getWave();
    
    std::string statusString = ss.str();
    m_statusText->setText(statusString);
}

void GameScreen::addToScore(int points)
{
    m_iScore += (points * m_iPointsScalar);
    addToFunds(points);
    
    std::stringstream ss;
    ss << "" << m_iScore;
    std::string rawScoreString = ss.str();
    unsigned long length = rawScoreString.length();
    std::stringstream ss2;
    for (unsigned int i = 0; i < (m_iScoreLength - length); i++)
    {
        ss2 << "0";
    }
    
    ss2 << "" << m_iScore;
    
    std::string scoreString = ss2.str();
    m_scoreText->setText(scoreString);
    
    updateFundsTextAndTowerCursors();
}

void GameScreen::coreShipModuleHit()
{
    m_backgroundElements->getCoreShipModule().takeDamage();
    
    if (m_backgroundElements->getCoreShipModule().isGameOver())
    {
        onPause();
        m_gameState = Game_State::GAME_OVER;
        m_iScreenState = SCREEN_STATE_GAME_OVER;
        m_backgroundElements->reset();
        m_timeButton->setSpeedScalar(0);
        m_adjustFundsText->setText("");
    }
}