//
//  DSLineBatcher.h
//  gowengamedev-framework
//
//  Created by Stephen Gowen on 8/25/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#ifndef __gowengamedev__DSLineBatcher__
#define __gowengamedev__DSLineBatcher__

#include "LineBatcher.h"

class DSLineBatcher : public LineBatcher
{
public:
    DSLineBatcher();
    
    virtual void beginBatch();
    
    virtual void endBatch();
    
    virtual void renderLine(float originX, float originY, float endX, float endY, Color &color);
};

#endif /* defined(__gowengamedev__DSLineBatcher__) */
