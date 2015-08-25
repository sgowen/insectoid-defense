//
//  OpenGLESGameScreen.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__OpenGLESGameScreen__
#define __insectoiddefense__OpenGLESGameScreen__

#include "GameScreen.h"

class OpenGLESRenderer;

class OpenGLESGameScreen : public GameScreen
{
public:
    OpenGLESGameScreen(int levelIndex, int difficulty);
    
protected:
    void initGraphics(int screenWidth, int screenHeight);
    
    virtual void platformResume();
    
    virtual void platformPause();
};

#endif /* defined(__insectoiddefense__OpenGLESGameScreen__) */
