//
//  OpenGLESRenderer.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__OpenGLESRenderer__
#define __insectoiddefense__OpenGLESRenderer__

#include "Renderer.h"

class OpenGLESRenderer : public Renderer
{
public:
    OpenGLESRenderer(int width, int height);
    
    virtual void clearScreenWithColor(float r, float g, float b, float a);
    
    virtual void beginFrame();
    
    virtual void endFrame();
    
    virtual void cleanUp();
};

#endif /* defined(__insectoiddefense__OpenGLESRenderer__) */