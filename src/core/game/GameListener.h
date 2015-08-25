//
//  GameListener.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 5/28/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__GameListener__
#define __insectoiddefense__GameListener__

#ifdef GGD_DIRECT_3D
#define strdup _strdup
#endif

#include <vector>

class PlayerPhysicalEntity;

class GameListener
{
public:
    static GameListener * getInstance();

    void playSound(short soundId);
    
private:
    GameListener();
};

#endif /* defined(__insectoiddefense__GameListener__) */