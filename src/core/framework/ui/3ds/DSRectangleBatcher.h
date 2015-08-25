//
//  DSRectangleBatcher.h
//  gowengamedev-framework
//
//  Created by Stephen Gowen on 8/25/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#ifndef __gowengamedev__DSRectangleBatcher__
#define __gowengamedev__DSRectangleBatcher__

#include "RectangleBatcher.h"

class DSRectangleBatcher : public RectangleBatcher
{
public:
    DSRectangleBatcher(bool isFill);
    
    virtual void beginBatch();
    
    virtual void endBatch();
    
    virtual void renderRectangle(float x1, float y1, float x2, float y2, Color &color);
};

#endif /* defined(__gowengamedev__DSRectangleBatcher__) */
