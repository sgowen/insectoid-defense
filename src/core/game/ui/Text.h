//
//  Text.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/6/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__Text__
#define __insectoiddefense__Text__

#include <string>
#include "Color.h"

class Text
{
public:
	Text(std::string text, float x, float y, float width, float height, float red, float green, float blue, float alpha);

	std::string getText();

	void setText(std::string text);

	float getX();

	void setX(float x);

	float getY();

	void setY(float y);

	float getWidth();

	float getHeight();

    Color getColor();

	void setColor(float red, float green, float blue, float alpha);

private:
	std::string m_strText;
	float m_fX;
	float m_fY;
	float m_fWidth;
	float m_fHeight;
	float m_fAlpha;
	float m_fRed;
	float m_fGreen;
	float m_fBlue;
};

#endif /* defined(__insectoiddefense__Text__) */