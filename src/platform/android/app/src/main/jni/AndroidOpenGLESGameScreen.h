//
//  AndroidOpenGLESGameScreen.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 7/22/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoid_defense__AndroidOpenGLESGameScreen__
#define __insectoid_defense__AndroidOpenGLESGameScreen__

#include "OpenGLESGameScreen.h"

class AndroidOpenGLESGameScreen : public OpenGLESGameScreen
{
public:
    AndroidOpenGLESGameScreen(int levelIndex, int difficulty);

    void onSurfaceCreated(int screenWidth, int screenHeight);

    void onSurfaceChanged(int screenWidth, int screenHeight);
    
    virtual void touchToWorld(TouchEvent &touchEvent);

    bool handleOnBackPressed();

private:
    int m_iScreenWidth;
    int m_iScreenHeight;
};

#endif /* defined(__insectoid_defense__AndroidOpenGLESGameScreen__) */
