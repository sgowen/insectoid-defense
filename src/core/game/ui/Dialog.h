//
//  Dialog.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/6/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__Dialog__
#define __insectoiddefense__Dialog__

#include "PhysicalEntity.h"
#include <string>

class Text;
class Rectangle;

class Dialog : public PhysicalEntity
{
public:
	Dialog(std::string title, std::string leftButton, std::string rightButton);

    bool isTouchingLeftButton(Vector2D &touchPoint);
    
    bool isTouchingRightButton(Vector2D &touchPoint);

	Text& getTitle();

	Text& getLeftButton();

	Text& getRightButton();

private:
	std::unique_ptr<Text> m_title;
	std::unique_ptr<Text> m_leftButton;
    std::unique_ptr<Text> m_rightButton;
	std::unique_ptr<Rectangle> m_leftButtonBounds;
    std::unique_ptr<Rectangle> m_rightButtonBounds;
};

#endif /* defined(__insectoiddefense__Dialog__) */