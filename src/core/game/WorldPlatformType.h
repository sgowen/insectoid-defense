//
//  WorldPlatformType.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/14/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__World_Platform_Type__
#define __insectoiddefense__World_Platform_Type__ 

typedef enum
{
	SOLO,
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT,
	CENTER,
	HORIZONTAL,
	VERTICAL,
	TOP_THREE_WAY,
	BOTTOM_THREE_WAY,
	LEFT_THREE_WAY,
	RIGHT_THREE_WAY,
	END_TOP,
	END_BOTTOM,
	END_LEFT,
	END_RIGHT
} World_Platform_Type;

#endif /* defined(__insectoiddefense__World_Platform_Type__) */