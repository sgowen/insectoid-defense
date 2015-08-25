//
//  TowerOptionButton.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/28/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "TowerOptionButton.h"
#include "OverlapTester.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "Text.h"

TowerOptionButton::TowerOptionButton(float x, float y, std::string buttonText, float borderRed, float borderGreen, float borderBlue, float borderAlpha, float textRed, float textGreen, float textBlue, float textAlpha)
{
	float width = 1.40f;
	float height = 1.20f;

	m_border = std::unique_ptr<Rectangle>(new Rectangle(x, y, width, height));
	m_buttonText = std::unique_ptr<Text>(new Text(buttonText, x + 0.10f, y + 0.90f, 0.20f, 0.26f, textRed, textGreen, textBlue, textAlpha));
	m_fundsText = std::unique_ptr<Text>(new Text("", x + width / 5, y + 0.40f, 0.30f, 0.37f, textRed, textGreen, textBlue, textAlpha));

	m_fBorderRed = borderRed;
	m_fBorderGreen = borderGreen;
	m_fBorderBlue = borderBlue;
	m_fBorderAlpha = borderAlpha;
}

bool TowerOptionButton::isTouching(Vector2D &touchPoint)
{
	return OverlapTester::isPointInRectangle(touchPoint, *m_border);
}

Rectangle & TowerOptionButton::getBorder()
{
	return *m_border;
}

Color TowerOptionButton::getBorderColor()
{
	Color color = Color(m_fBorderRed, m_fBorderGreen, m_fBorderBlue, m_fBorderAlpha);
	return color;
}

void TowerOptionButton::setBorderColor(float borderRed, float borderGreen, float borderBlue, float borderAlpha)
{
	m_fBorderRed = borderRed;
	m_fBorderGreen = borderGreen;
	m_fBorderBlue = borderBlue;
	m_fBorderAlpha = borderAlpha;
}

Color TowerOptionButton::getTextColor()
{
	return m_buttonText->getColor();
}
	
void TowerOptionButton::setTextColor(float textRed, float textGreen, float textBlue, float textAlpha)
{
	m_buttonText->setColor(textRed, textGreen, textBlue, textAlpha);
	m_fundsText->setColor(textRed, textGreen, textBlue, textAlpha);
}

Text & TowerOptionButton::getButtonText()
{
	return *m_buttonText;
}

Text & TowerOptionButton::getFundsText()
{
	return *m_fundsText;
}