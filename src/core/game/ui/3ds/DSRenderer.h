//
//  DSRenderer.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 8/20/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__DSRenderer__
#define __insectoiddefense__DSRenderer__

#include "Renderer.h"

#include <3ds.h>

class DSRenderer : public Renderer
{
public:
    DSRenderer(gfxScreen_t screen, int screenWidth, int screenHeight);

    ~DSRenderer();

    virtual void clearScreenWithColor(float r, float g, float b, float a);

    virtual void beginFrame();

    virtual void endFrame();

    virtual void cleanUp();
    
private:
    gfxScreen_t m_screen;
};

#endif /* defined(__insectoiddefense__DSRenderer__) */
