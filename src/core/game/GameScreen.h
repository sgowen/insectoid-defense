//
//  GameScreen.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <memory>
#include <vector>

#include "GameState.h"

class GameListener;
class TouchEvent;
class Vector2D;
class Renderer;
class BackgroundElements;
class TimeButton;
class Text;
class Dialog;
class TouchCursor;

class GameScreen
{
public:
	GameScreen(int levelIndex, int difficulty);
    
    virtual void touchToWorld(TouchEvent &touchEvent) = 0;
    
    virtual void platformResume() = 0;
    
    virtual void platformPause() = 0;
    
    virtual bool handleOnBackPressed() = 0;
    
    void init();

	void onResume();
	
	void onPause();
    
	void update(float deltaTime, std::vector<TouchEvent> &touchEvents);
    
    void present();
    
    int getLevelIndex();
    
    int getDifficulty();
	
    int getWave();
    
    int getScore();
    
    bool isAtMaxHealth();
    
    int getState();
    
    void clearState();

protected:
    std::unique_ptr<Renderer> m_renderer;
	std::unique_ptr<Vector2D> m_touchPoint;
	Game_State m_gameState;
    int m_iDeviceScreenWidth;
	int m_iDeviceScreenHeight;
	int m_iScreenState;
    
private:
    std::unique_ptr<BackgroundElements> m_backgroundElements;
    std::unique_ptr<TimeButton> m_timeButton;
    std::unique_ptr<Dialog> m_pausedDialog;
    std::unique_ptr<Dialog> m_gameOverDialog;
    std::unique_ptr<TouchCursor> m_touchCursor;
    std::unique_ptr<Text> m_statusText;
    std::unique_ptr<Text> m_scoreText;
    std::unique_ptr<Text> m_fundsText;
    std::unique_ptr<Text> m_adjustFundsText;
    
    int m_iLevelIndex;
    int m_iDifficulty;
    int m_iPointsScalar;
    int m_iFunds;
    int m_iScore;
    unsigned long m_iScoreLength;
    
    void updateRunning(float deltaTime);
    
    void updateInputRunning(std::vector<TouchEvent> &touchEvents);
    void updateInputPaused(std::vector<TouchEvent> &touchEvents);
    void updateInputGameOver(std::vector<TouchEvent> &touchEvents);
    
    void handleTouchDownInUpgradeSellMenu();
    
    void updateAndHandleTouchCursor();
    
    void handleTouchUpInUpgradeSellMenu();
    
    void addToFunds(int addition);
    
    void setAdjustFundsText(int amount, bool isPositive);
    
    void updateFundsTextAndTowerCursors();
    
    void adjustUpgradeTowerButtonColor();
    
    void adjustUpgradeSellTexts();
    
    // Callback methods
    void waveCompleted();
    void waveSpawned();
    void addToScore(int points);
    void coreShipModuleHit();
};

#endif /* GAME_SCREEN_H */