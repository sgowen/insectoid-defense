//
//  DSCircleBatcher.cpp
//  gowengamedev-framework
//
//  Created by Stephen Gowen on 8/25/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#define DEGREE_SPACING 6

#include "DSCircleBatcher.h"
#include "macros.h"
#include "Circle.h"
#include "Vector2D.h"
#include "math.h"

DSCircleBatcher::DSCircleBatcher() : CircleBatcher()
{
    // Empty
}

void DSCircleBatcher::renderCircle(Circle &circle, Color &color)
{
//    OGLESManager->m_colorVertices.clear();
    
    int numPointsOnCircle = 0;
    
    for (int i = 0; i < 360; i += DEGREE_SPACING)
    {
        float rad = DEGREES_TO_RADIANS(i);
        float cos = cosf(rad);
        float sin = sinf(rad);
        
//        OGLESManager->addVertexCoordinate(cos * circle.m_fRadius + circle.getCenter().getX(), sin * circle.m_fRadius + circle.getCenter().getY(), 0, color.red, color.green, color.blue, color.alpha);
        
        numPointsOnCircle++;
    }
    
    endBatch(numPointsOnCircle);
}

void DSCircleBatcher::renderPartialCircle(Circle &circle, int arcDegrees, Color &color)
{
//    OGLESManager->m_colorVertices.clear();
    
//    OGLESManager->addVertexCoordinate(circle.getCenter().getX(), circle.getCenter().getY(), 0, color.red, color.green, color.blue, color.alpha);
    
    int numPointsOnCircle = 1;
    
    for (int i = 90 - arcDegrees; i > -270; i -= DEGREE_SPACING)
    {
        float rad = DEGREES_TO_RADIANS(i);
        float cos = cosf(rad);
        float sin = sinf(rad);
        
//        OGLESManager->addVertexCoordinate(cos * circle.m_fRadius + circle.getCenter().getX(), sin * circle.m_fRadius + circle.getCenter().getY(), 0, color.red, color.green, color.blue, color.alpha);
        
        numPointsOnCircle++;
    }
    
    float rad = DEGREES_TO_RADIANS(-270);
    float cos = cosf(rad);
    float sin = sinf(rad);
    
//    OGLESManager->addVertexCoordinate(cos * circle.m_fRadius + circle.getCenter().getX(), sin * circle.m_fRadius + circle.getCenter().getY(), 0, color.red, color.green, color.blue, color.alpha);
    
    numPointsOnCircle++;
    
    endBatch(numPointsOnCircle);
}

void DSCircleBatcher::endBatch(int numPoints)
{
//    OGLESManager->prepareForGeometryRendering();
    
//    glDrawArrays(GL_TRIANGLE_FAN, 0, numPoints);
    
//    OGLESManager->finishGeometryRendering();
}