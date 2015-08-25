//
//  TowerOptionButton.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/28/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__TowerOptionButton__
#define __insectoiddefense__TowerOptionButton__


#include "Color.h"

#include <vector>
#include <memory>

class Rectangle;
class Text;
class Vector2D;

class TowerOptionButton
{
public:
	TowerOptionButton(float x, float y, std::string buttonText, float borderRed, float borderGreen, float borderBlue, float borderAlpha, float textRed, float textGreen, float textBlue, float textAlpha);

	bool isTouching(Vector2D &touchPoint);

	Rectangle & getBorder();

	Color getBorderColor();

	void setBorderColor(float borderRed, float borderGreen, float borderBlue, float borderAlpha);

	Color getTextColor();
	
	void setTextColor(float textRed, float textGreen, float textBlue, float textAlpha);

	Text & getButtonText();

	Text & getFundsText();

private:
	std::unique_ptr<Rectangle> m_border;
	std::unique_ptr<Text> m_buttonText;
	std::unique_ptr<Text> m_fundsText;
	float m_fBorderRed;
	float m_fBorderGreen;
	float m_fBorderBlue;
	float m_fBorderAlpha;
};

#endif /* defined(__insectoiddefense__TowerOptionButton__) */