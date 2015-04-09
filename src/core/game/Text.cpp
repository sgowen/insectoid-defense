//
//  Text.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/6/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "pch.h"
#include "Text.h"

Text::Text(std::string text, float x, float y, float width, float height, float red, float green, float blue, float alpha)
{
	m_strText = text;
	m_fWidth = width;
	m_fHeight = height;
	m_fX = x;
	m_fY = y;

	m_fAlpha = alpha;
	m_fRed = red;
	m_fGreen = green;
	m_fBlue = blue;
}

std::string Text::getText()
{
	return m_strText;
}

void Text::setText(std::string text)
{
	m_strText = text;
}

float Text::getX()
{
	return m_fX;
}

void Text::setX(float x)
{
	m_fX = x;
}

float Text::getY()
{
	return m_fY;
}

void Text::setY(float y)
{
	m_fY = y;
}

float Text::getWidth()
{
	return m_fWidth;
}

float Text::getHeight()
{
	return m_fHeight;
}

Color Text::getColor()
{
    Color color = Color(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	return color;
}

void Text::setColor(float red, float green, float blue, float alpha)
{
	m_fRed = red;
	m_fGreen = green;
	m_fBlue = blue;
	m_fAlpha = alpha;
}