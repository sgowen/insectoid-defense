//
//  UniqueIDUtil.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/27/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__UniqueIDUtil__
#define __insectoiddefense__UniqueIDUtil__

class UniqueIDUtil
{
public:
	static int getUniqueTowerID()
	{
		static int towerID = 0;
		return towerID++;
	}

	static int getUniqueLazerBeamID()
	{
		static int lazerBeamID = 0;
		return lazerBeamID++;
	}
};

#endif /* defined(__insectoiddefense__UniqueIDUtil__) */