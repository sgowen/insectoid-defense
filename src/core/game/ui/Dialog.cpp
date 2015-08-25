//
//  Dialog.cpp
//  game-framework
//
//  Created by Stephen Gowen on 10/6/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "Dialog.h"
#include "OverlapTester.h"
#include "Text.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "GameConstants.h"

Dialog::Dialog(std::string title, std::string leftButton, std::string rightButton) : PhysicalEntity(GAME_WIDTH / 2, GAME_HEIGHT / 2, GAME_WIDTH / 2, GAME_HEIGHT / 3, 0)
{
    m_title = std::unique_ptr<Text>(new Text(title, m_position->getX() - m_fWidth / 2 + m_fWidth / 13, m_position->getY() + m_fHeight / 3, 0.50f, 0.50f, 1, 1, 1, 1));
    m_leftButton = std::unique_ptr<Text>(new Text(leftButton, m_position->getX() - m_fWidth / 2 + m_fWidth / 6, m_position->getY() - m_fHeight / 6, 0.50f, 0.50f, 1, 1, 1, 0.85f));
    m_rightButton = std::unique_ptr<Text>(new Text(rightButton, m_position->getX() + m_fWidth / 9, m_position->getY() - m_fHeight / 6, 0.50f, 0.50f, 1, 1, 1, 0.85f));
    m_leftButtonBounds = std::unique_ptr<Rectangle>(new Rectangle(m_position->getX() - m_fWidth / 2, m_position->getY() - m_fHeight / 2, m_fWidth / 2, m_fHeight));
    m_rightButtonBounds = std::unique_ptr<Rectangle>(new Rectangle(m_position->getX(), m_position->getY() - m_fHeight / 2, m_fWidth / 2, m_fHeight));
}

bool Dialog::isTouchingLeftButton(Vector2D &touchPoint)
{
    return OverlapTester::isPointInRectangle(touchPoint, *m_leftButtonBounds);
}

bool Dialog::isTouchingRightButton(Vector2D &touchPoint)
{
    return OverlapTester::isPointInRectangle(touchPoint, *m_rightButtonBounds);
}

Text& Dialog::getTitle()
{
    return *m_title;
}

Text& Dialog::getLeftButton()
{
    return *m_leftButton;
}

Text& Dialog::getRightButton()
{
    return *m_rightButton;
}