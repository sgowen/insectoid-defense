//
//  AchievementMapper.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/5/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__AchievementMapper__
#define __insectoiddefense__AchievementMapper__

#include <string>

class AchievementMapper
{
public:
	static std::wstring getUnLockedMessageForLevelIndex(int levelIndex)
	{
		switch (levelIndex)
		{
		case 0:
			return L"Freeze or Burn unlocked!";
		case 1:
			return L"Hull Damage unlocked!";
		case 2:
			return L"Clear a Path unlocked!";
		case 3:
			return L"Hangar Breach unlocked!";
		case 4:
			return L"Divided unlocked!";
		case 5:
			return L"Blitzkrieg unlocked!";
		case 6:
			return L"Full-scale War unlocked!";
		case 7:
			return L"Sabotoge unlocked!";
		case 8:
			return L"Finale unlocked!";
		default:
			return L"";
		}
	}

	static int getWaveRequirementForLevelIndex(int levelIndex)
	{
		switch (levelIndex)
		{
		case 0:
			return 20;
		case 1:
			return 30;
		case 2:
			return 30;
		case 3:
			return 30;
		case 4:
			return 20;
		case 5:
			return 30;
		case 6:
			return 20;
		case 7:
			return 50;
		case 8:
			return 40;
		case 9:
		default:
			return 60;
		}
	}
};

#endif /* defined(__insectoiddefense__AchievementMapper__) */