//
//  HardCodedPathGenerator.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/13/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__HardCodedPathGenerator__
#define __insectoiddefense__HardCodedPathGenerator__

#include <vector>
#include "Node.h"

class HardCodedPathGenerator
{
public:
	static std::vector<Node> getHardCodedPathForLevelSpawnPointIndex(int levelIndex, int spawnPointIndex, bool isUsingAltPath, bool isAlt)
	{
		switch(levelIndex)
		{
		case 0:
			return getPathForLevel1(isUsingAltPath);
		case 1:
			return getPathForLevel2(isUsingAltPath);
		case 2:
			return spawnPointIndex == 0 ? getPathForLevel3SpawnIndex0(isUsingAltPath) : getPathForLevel3SpawnIndex1(isUsingAltPath, isAlt);
		case 3:
			return getPathForLevel4(isUsingAltPath);
		case 4:
			return spawnPointIndex == 0 ? getPathForLevel5SpawnIndex0(isUsingAltPath) : getPathForLevel5SpawnIndex1(isUsingAltPath);
		case 5:
			switch (spawnPointIndex)
			{
			case 0:
				return getPathForLevel6SpawnIndex0(isUsingAltPath);
			case 1:
				return getPathForLevel6SpawnIndex1(isUsingAltPath);
			case 2:
				return getPathForLevel6SpawnIndex2(isUsingAltPath);
			case 3:
				return getPathForLevel6SpawnIndex3(isUsingAltPath);
			default:
				return getPathForLevel6SpawnIndex4(isUsingAltPath);
			}
		case 6:
			return getPathForLevel7(isUsingAltPath);
		case 7:
			switch (spawnPointIndex)
			{
			case 0:
				return getPathForLevel8SpawnIndex0(isUsingAltPath);
			case 1:
				return getPathForLevel8SpawnIndex1(isUsingAltPath);
			case 2:
				return getPathForLevel8SpawnIndex2(isUsingAltPath);
			case 3:
				return getPathForLevel8SpawnIndex3(isUsingAltPath);
			default:
				return getPathForLevel8SpawnIndex4(isUsingAltPath);
			}
		case 8:
			return spawnPointIndex == 0 ? getPathForLevel9SpawnIndex0(isUsingAltPath) : getPathForLevel9SpawnIndex1(isUsingAltPath);
		default:
			switch (spawnPointIndex)
			{
			case 0:
				return getPathForLevel10SpawnIndex0(isUsingAltPath);
			case 1:
				return getPathForLevel10SpawnIndex1(isUsingAltPath);
			case 2:
				return getPathForLevel10SpawnIndex2(isUsingAltPath);
			case 3:
				return getPathForLevel10SpawnIndex3(isUsingAltPath);
			case 4:
				return getPathForLevel10SpawnIndex4(isUsingAltPath);
			default:
				return getPathForLevel10SpawnIndex5(isUsingAltPath);
			}
		}
	}

private:
	static std::vector<Node> getPathForLevel1(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(0, 0));
			path.push_back(Node(0, 1));
			path.push_back(Node(0, 2));
			path.push_back(Node(0, 3));
			path.push_back(Node(0, 4));
			path.push_back(Node(0, 5));
			path.push_back(Node(0, 6));
			path.push_back(Node(0, 7));
			path.push_back(Node(1, 7));
			path.push_back(Node(2, 7));
			path.push_back(Node(2, 6));
			path.push_back(Node(2, 5));
			path.push_back(Node(2, 4));
			path.push_back(Node(2, 3));
			path.push_back(Node(2, 2));
			path.push_back(Node(2, 1));
			path.push_back(Node(3, 1));
			path.push_back(Node(4, 1));
			path.push_back(Node(4, 2));
			path.push_back(Node(4, 3));
			path.push_back(Node(4, 4));
			path.push_back(Node(4, 5));
			path.push_back(Node(4, 6));
			path.push_back(Node(4, 7));
			path.push_back(Node(5, 7));
			path.push_back(Node(6, 7));
			path.push_back(Node(7, 7));
			path.push_back(Node(8, 7));
			path.push_back(Node(9, 7));
			path.push_back(Node(9, 6));
			path.push_back(Node(9, 5));
			path.push_back(Node(8, 5));
			path.push_back(Node(7, 5));
			path.push_back(Node(6, 5));
			path.push_back(Node(6, 4));
			path.push_back(Node(6, 3));
			path.push_back(Node(6, 2));
			path.push_back(Node(6, 1));
			path.push_back(Node(6, 0));
			path.push_back(Node(7, 0));
			path.push_back(Node(8, 0));
			path.push_back(Node(8, 1));
			path.push_back(Node(8, 2));
			path.push_back(Node(9, 2));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 1));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel2(bool isUsingAltPath)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(0, 4));
			path.push_back(Node(1, 4));
			path.push_back(Node(2, 4));
			path.push_back(Node(2, 3));
			path.push_back(Node(2, 2));
			path.push_back(Node(2, 1));
			path.push_back(Node(2, 0));
			path.push_back(Node(3, 0));
			path.push_back(Node(4, 0));
			path.push_back(Node(4, 1));
			path.push_back(Node(4, 2));
			path.push_back(Node(4, 3));
			path.push_back(Node(4, 4));
			path.push_back(Node(4, 5));
			path.push_back(Node(4, 6));
			path.push_back(Node(3, 6));
			path.push_back(Node(2, 6));
			path.push_back(Node(1, 6));
			path.push_back(Node(0, 6));
			path.push_back(Node(0, 7));
			path.push_back(Node(0, 8));
			path.push_back(Node(1, 8));
			path.push_back(Node(2, 8));
			path.push_back(Node(3, 8));
			path.push_back(Node(4, 8));
			path.push_back(Node(5, 8));
			path.push_back(Node(5, 7));
			path.push_back(Node(6, 7));
			path.push_back(Node(6, 6));
			path.push_back(Node(6, 5));
			path.push_back(Node(6, 4));
			path.push_back(Node(6, 3));
			path.push_back(Node(7, 3));
			path.push_back(Node(8, 3));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 5));
			path.push_back(Node(8, 6));
			path.push_back(Node(9, 6));
			path.push_back(Node(10, 6));
			path.push_back(Node(10, 5));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 3));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(0, 4));
			pathAlt.push_back(Node(1, 4));
			pathAlt.push_back(Node(2, 4));
			pathAlt.push_back(Node(2, 3));
			pathAlt.push_back(Node(2, 2));
			pathAlt.push_back(Node(2, 1));
			pathAlt.push_back(Node(2, 0));
			pathAlt.push_back(Node(3, 0));
			pathAlt.push_back(Node(4, 0));
			pathAlt.push_back(Node(4, 1));
			pathAlt.push_back(Node(4, 2));
			pathAlt.push_back(Node(4, 3));
			pathAlt.push_back(Node(4, 4));
			pathAlt.push_back(Node(4, 5));
			pathAlt.push_back(Node(4, 6));
			pathAlt.push_back(Node(3, 6));
			pathAlt.push_back(Node(2, 6));
			pathAlt.push_back(Node(1, 6));
			pathAlt.push_back(Node(0, 6));
			pathAlt.push_back(Node(0, 7));
			pathAlt.push_back(Node(0, 8));
			pathAlt.push_back(Node(1, 8));
			pathAlt.push_back(Node(2, 8));
			pathAlt.push_back(Node(3, 8));
			pathAlt.push_back(Node(4, 8));
			pathAlt.push_back(Node(5, 8));
			pathAlt.push_back(Node(5, 7));
			pathAlt.push_back(Node(6, 7));
			pathAlt.push_back(Node(6, 6));
			pathAlt.push_back(Node(6, 5));
			pathAlt.push_back(Node(6, 4));
			pathAlt.push_back(Node(6, 3));
			pathAlt.push_back(Node(7, 3));
			pathAlt.push_back(Node(8, 3));
			pathAlt.push_back(Node(8, 2));
			pathAlt.push_back(Node(8, 1));
			pathAlt.push_back(Node(8, 0));
			pathAlt.push_back(Node(9, 0));
			pathAlt.push_back(Node(10, 0));
			pathAlt.push_back(Node(10, 1));
			pathAlt.push_back(Node(10, 2));
			pathAlt.push_back(Node(10, 3));
		}

		return isUsingAltPath ? pathAlt : path;
	}

	static std::vector<Node> getPathForLevel3SpawnIndex0(bool isUsingAltPath)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(9, 7));
			path.push_back(Node(9, 6));
			path.push_back(Node(8, 6));
			path.push_back(Node(8, 5));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 3));
			path.push_back(Node(8, 2));
			path.push_back(Node(8, 1));
			path.push_back(Node(9, 1));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(9, 7));
			pathAlt.push_back(Node(8, 7));
			pathAlt.push_back(Node(8, 6));
			pathAlt.push_back(Node(8, 5));
			pathAlt.push_back(Node(8, 4));
			pathAlt.push_back(Node(8, 3));
			pathAlt.push_back(Node(8, 2));
			pathAlt.push_back(Node(8, 1));
			pathAlt.push_back(Node(9, 1));
			pathAlt.push_back(Node(10, 1));
			pathAlt.push_back(Node(10, 2));
			pathAlt.push_back(Node(10, 3));
		}

		return isUsingAltPath ? pathAlt : path;
	}

	static std::vector<Node> getPathForLevel3SpawnIndex1(bool isUsingAltPath, bool isAlt)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathTwist;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(0, 6));
			path.push_back(Node(0, 7));
			path.push_back(Node(0, 8));
			path.push_back(Node(1, 8));
			path.push_back(Node(2, 8));
			path.push_back(Node(2, 7));
			path.push_back(Node(3, 7));
			path.push_back(Node(3, 6));

			// LEFT
			path.push_back(Node(3, 5));
			path.push_back(Node(2, 5));
			path.push_back(Node(2, 4));
			path.push_back(Node(2, 3));
			path.push_back(Node(3, 3));
			path.push_back(Node(3, 2));
			path.push_back(Node(4, 2));

			// BOTH
			path.push_back(Node(5, 2));
			path.push_back(Node(5, 1));
			path.push_back(Node(6, 1));
			path.push_back(Node(6, 0));
			path.push_back(Node(7, 0));
			path.push_back(Node(8, 0));
			path.push_back(Node(8, 1));
			path.push_back(Node(9, 1));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
		}

		if(pathTwist.size() == 0)
		{
			pathTwist.push_back(Node(0, 6));
			pathTwist.push_back(Node(0, 7));
			pathTwist.push_back(Node(0, 8));
			pathTwist.push_back(Node(1, 8));
			pathTwist.push_back(Node(2, 8));
			pathTwist.push_back(Node(2, 7));
			pathTwist.push_back(Node(3, 7));
			pathTwist.push_back(Node(3, 6));

			// RIGHT
			pathTwist.push_back(Node(4, 6));
			pathTwist.push_back(Node(5, 6));
			pathTwist.push_back(Node(5, 5));
			pathTwist.push_back(Node(6, 5));
			pathTwist.push_back(Node(6, 4));
			pathTwist.push_back(Node(6, 3));
			pathTwist.push_back(Node(5, 3));

			// BOTH
			pathTwist.push_back(Node(5, 2));
			pathTwist.push_back(Node(5, 1));
			pathTwist.push_back(Node(6, 1));
			pathTwist.push_back(Node(6, 0));
			pathTwist.push_back(Node(7, 0));
			pathTwist.push_back(Node(8, 0));
			pathTwist.push_back(Node(8, 1));
			pathTwist.push_back(Node(9, 1));
			pathTwist.push_back(Node(10, 1));
			pathTwist.push_back(Node(10, 2));
			pathTwist.push_back(Node(10, 3));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(0, 6));
			pathAlt.push_back(Node(0, 5));
			pathAlt.push_back(Node(0, 4));
			pathAlt.push_back(Node(0, 3));
			pathAlt.push_back(Node(0, 2));
			pathAlt.push_back(Node(0, 1));
			pathAlt.push_back(Node(0, 0));
			pathAlt.push_back(Node(1, 0));
			pathAlt.push_back(Node(2, 0));
			pathAlt.push_back(Node(2, 1));
			pathAlt.push_back(Node(3, 1));
			pathAlt.push_back(Node(3, 2));
			pathAlt.push_back(Node(4, 2));
			pathAlt.push_back(Node(5, 2));
			pathAlt.push_back(Node(5, 1));
			pathAlt.push_back(Node(6, 1));
			pathAlt.push_back(Node(6, 0));
			pathAlt.push_back(Node(7, 0));
			pathAlt.push_back(Node(8, 0));
			pathAlt.push_back(Node(8, 1));
			pathAlt.push_back(Node(9, 1));
			pathAlt.push_back(Node(10, 1));
			pathAlt.push_back(Node(10, 2));
			pathAlt.push_back(Node(10, 3));
		}


		return isUsingAltPath ? pathAlt : isAlt ? pathTwist : path;
	}

	static std::vector<Node> getPathForLevel4(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(1, 7));
			path.push_back(Node(1, 6));
			path.push_back(Node(1, 5));
			path.push_back(Node(1, 4));
			path.push_back(Node(1, 3));
			path.push_back(Node(1, 2));
			path.push_back(Node(1, 1));
			path.push_back(Node(2, 1));
			path.push_back(Node(3, 1));
			path.push_back(Node(3, 2));
			path.push_back(Node(3, 3));
			path.push_back(Node(3, 4));
			path.push_back(Node(3, 5));
			path.push_back(Node(3, 6));
			path.push_back(Node(3, 7));
			path.push_back(Node(4, 7));
			path.push_back(Node(5, 7));
			path.push_back(Node(5, 6));
			path.push_back(Node(5, 5));
			path.push_back(Node(5, 4));
			path.push_back(Node(5, 3));
			path.push_back(Node(5, 2));
			path.push_back(Node(5, 1));
			path.push_back(Node(6, 1));
			path.push_back(Node(7, 1));
			path.push_back(Node(7, 2));
			path.push_back(Node(7, 3));
			path.push_back(Node(7, 4));
			path.push_back(Node(7, 5));
			path.push_back(Node(7, 6));
			path.push_back(Node(7, 7));
			path.push_back(Node(8, 7));
			path.push_back(Node(9, 7));
			path.push_back(Node(9, 6));
			path.push_back(Node(9, 5));
			path.push_back(Node(10, 5));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel5SpawnIndex0(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(2, 8));
			path.push_back(Node(1, 8));
			path.push_back(Node(1, 7));
			path.push_back(Node(0, 7));
			path.push_back(Node(0, 6));
			path.push_back(Node(0, 5));
			path.push_back(Node(1, 5));
			path.push_back(Node(2, 5));
			path.push_back(Node(2, 6));
			path.push_back(Node(3, 6));
			path.push_back(Node(4, 6));
			path.push_back(Node(4, 7));
			path.push_back(Node(4, 8));
			path.push_back(Node(5, 8));
			path.push_back(Node(6, 8));
			path.push_back(Node(7, 8));
			path.push_back(Node(8, 8));
			path.push_back(Node(9, 8));
			path.push_back(Node(9, 7));
			path.push_back(Node(10, 7));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel5SpawnIndex1(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(2, 0));
			path.push_back(Node(1, 0));
			path.push_back(Node(1, 1));
			path.push_back(Node(0, 1));
			path.push_back(Node(0, 2));
			path.push_back(Node(0, 3));
			path.push_back(Node(1, 3));
			path.push_back(Node(2, 3));
			path.push_back(Node(2, 2));
			path.push_back(Node(3, 2));
			path.push_back(Node(4, 2));
			path.push_back(Node(4, 1));
			path.push_back(Node(4, 0));
			path.push_back(Node(5, 0));
			path.push_back(Node(6, 0));
			path.push_back(Node(6, 1));
			path.push_back(Node(6, 2));
			path.push_back(Node(6, 3));
			path.push_back(Node(6, 4));
			path.push_back(Node(6, 5));
			path.push_back(Node(6, 6));
			path.push_back(Node(7, 6));
			path.push_back(Node(8, 6));
			path.push_back(Node(8, 5));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 3));
			path.push_back(Node(8, 2));
			path.push_back(Node(8, 1));
			path.push_back(Node(9, 1));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 5));
			path.push_back(Node(10, 6));
			path.push_back(Node(10, 7));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel6SpawnIndex0(bool isUsingAltPath)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(1, 8));
			path.push_back(Node(2, 8));
			path.push_back(Node(2, 7));
			path.push_back(Node(3, 7));
			path.push_back(Node(4, 7));
			path.push_back(Node(5, 7));
			path.push_back(Node(5, 6));
			path.push_back(Node(5, 5));
			path.push_back(Node(4, 5));
			path.push_back(Node(3, 5));
			path.push_back(Node(2, 5));
			path.push_back(Node(1, 5));
			path.push_back(Node(1, 4));
			path.push_back(Node(1, 3));
			path.push_back(Node(2, 3));
			path.push_back(Node(3, 3));
			path.push_back(Node(3, 2));
			path.push_back(Node(3, 1));
			path.push_back(Node(4, 1));
			path.push_back(Node(5, 1));
			path.push_back(Node(6, 1));
			path.push_back(Node(7, 1));
			path.push_back(Node(8, 1));
			path.push_back(Node(9, 1));
			path.push_back(Node(10, 1));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(1, 8));
			pathAlt.push_back(Node(2, 8));
			pathAlt.push_back(Node(2, 7));
			pathAlt.push_back(Node(3, 7));
			pathAlt.push_back(Node(4, 7));
			pathAlt.push_back(Node(5, 7));
			pathAlt.push_back(Node(5, 6));
			pathAlt.push_back(Node(5, 5));
			pathAlt.push_back(Node(4, 5));
			pathAlt.push_back(Node(3, 5));
			pathAlt.push_back(Node(2, 5));
			pathAlt.push_back(Node(1, 5));
			pathAlt.push_back(Node(1, 4));
			pathAlt.push_back(Node(1, 3));
			pathAlt.push_back(Node(1, 2));
			pathAlt.push_back(Node(1, 1));
			pathAlt.push_back(Node(2, 1));
			pathAlt.push_back(Node(3, 1));
			pathAlt.push_back(Node(4, 1));
			pathAlt.push_back(Node(5, 1));
			pathAlt.push_back(Node(6, 1));
			pathAlt.push_back(Node(7, 1));
			pathAlt.push_back(Node(8, 1));
			pathAlt.push_back(Node(9, 1));
			pathAlt.push_back(Node(10, 1));
		}

		return isUsingAltPath ? pathAlt : path;
	}

	static std::vector<Node> getPathForLevel6SpawnIndex1(bool isUsingAltPath)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(3, 8));
			path.push_back(Node(3, 7));
			path.push_back(Node(4, 7));
			path.push_back(Node(5, 7));
			path.push_back(Node(5, 6));
			path.push_back(Node(5, 5));
			path.push_back(Node(4, 5));
			path.push_back(Node(3, 5));
			path.push_back(Node(2, 5));
			path.push_back(Node(1, 5));
			path.push_back(Node(1, 4));
			path.push_back(Node(1, 3));
			path.push_back(Node(2, 3));
			path.push_back(Node(3, 3));
			path.push_back(Node(3, 2));
			path.push_back(Node(3, 1));
			path.push_back(Node(4, 1));
			path.push_back(Node(5, 1));
			path.push_back(Node(6, 1));
			path.push_back(Node(7, 1));
			path.push_back(Node(8, 1));
			path.push_back(Node(9, 1));
			path.push_back(Node(10, 1));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(3, 8));
			pathAlt.push_back(Node(3, 7));
			pathAlt.push_back(Node(4, 7));
			pathAlt.push_back(Node(5, 7));
			pathAlt.push_back(Node(5, 6));
			pathAlt.push_back(Node(5, 5));
			pathAlt.push_back(Node(4, 5));
			pathAlt.push_back(Node(3, 5));
			pathAlt.push_back(Node(2, 5));
			pathAlt.push_back(Node(1, 5));
			pathAlt.push_back(Node(1, 4));
			pathAlt.push_back(Node(1, 3));
			pathAlt.push_back(Node(1, 2));
			pathAlt.push_back(Node(1, 1));
			pathAlt.push_back(Node(2, 1));
			pathAlt.push_back(Node(3, 1));
			pathAlt.push_back(Node(4, 1));
			pathAlt.push_back(Node(5, 1));
			pathAlt.push_back(Node(6, 1));
			pathAlt.push_back(Node(7, 1));
			pathAlt.push_back(Node(8, 1));
			pathAlt.push_back(Node(9, 1));
			pathAlt.push_back(Node(10, 1));
		}

		return isUsingAltPath ? pathAlt : path;
	}

	static std::vector<Node> getPathForLevel6SpawnIndex2(bool isUsingAltPath)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(5, 8));
			path.push_back(Node(5, 7));
			path.push_back(Node(5, 6));
			path.push_back(Node(5, 5));
			path.push_back(Node(4, 5));
			path.push_back(Node(3, 5));
			path.push_back(Node(2, 5));
			path.push_back(Node(1, 5));
			path.push_back(Node(1, 4));
			path.push_back(Node(1, 3));
			path.push_back(Node(1, 2));
			path.push_back(Node(1, 1));
			path.push_back(Node(2, 1));
			path.push_back(Node(3, 1));
			path.push_back(Node(4, 1));
			path.push_back(Node(5, 1));
			path.push_back(Node(6, 1));
			path.push_back(Node(7, 1));
			path.push_back(Node(8, 1));
			path.push_back(Node(9, 1));
			path.push_back(Node(10, 1));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(5, 8));
			pathAlt.push_back(Node(5, 7));
			pathAlt.push_back(Node(5, 6));
			pathAlt.push_back(Node(5, 5));
			pathAlt.push_back(Node(6, 5));
			pathAlt.push_back(Node(7, 5));
			pathAlt.push_back(Node(8, 5));
			pathAlt.push_back(Node(9, 5));
			pathAlt.push_back(Node(10, 5));
			pathAlt.push_back(Node(10, 4));
			pathAlt.push_back(Node(10, 3));
			pathAlt.push_back(Node(9, 3));
			pathAlt.push_back(Node(8, 3));
			pathAlt.push_back(Node(7, 3));
			pathAlt.push_back(Node(6, 3));
			pathAlt.push_back(Node(5, 3));
			pathAlt.push_back(Node(4, 3));
			pathAlt.push_back(Node(3, 3));
			pathAlt.push_back(Node(3, 2));
			pathAlt.push_back(Node(3, 1));
			pathAlt.push_back(Node(4, 1));
			pathAlt.push_back(Node(5, 1));
			pathAlt.push_back(Node(6, 1));
			pathAlt.push_back(Node(7, 1));
			pathAlt.push_back(Node(8, 1));
			pathAlt.push_back(Node(9, 1));
			pathAlt.push_back(Node(10, 1));
		}

		return isUsingAltPath ? pathAlt : path;
	}

	static std::vector<Node> getPathForLevel6SpawnIndex3(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(7, 8));
			path.push_back(Node(7, 7));
			path.push_back(Node(6, 7));
			path.push_back(Node(5, 7));
			path.push_back(Node(5, 6));
			path.push_back(Node(5, 5));
			path.push_back(Node(6, 5));
			path.push_back(Node(7, 5));
			path.push_back(Node(8, 5));
			path.push_back(Node(9, 5));
			path.push_back(Node(10, 5));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 3));
			path.push_back(Node(9, 3));
			path.push_back(Node(8, 3));
			path.push_back(Node(7, 3));
			path.push_back(Node(6, 3));
			path.push_back(Node(5, 3));
			path.push_back(Node(4, 3));
			path.push_back(Node(3, 3));
			path.push_back(Node(3, 2));
			path.push_back(Node(3, 1));
			path.push_back(Node(4, 1));
			path.push_back(Node(5, 1));
			path.push_back(Node(6, 1));
			path.push_back(Node(7, 1));
			path.push_back(Node(8, 1));
			path.push_back(Node(9, 1));
			path.push_back(Node(10, 1));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel6SpawnIndex4(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(9, 8));
			path.push_back(Node(8, 8));
			path.push_back(Node(8, 7));
			path.push_back(Node(7, 7));
			path.push_back(Node(6, 7));
			path.push_back(Node(5, 7));
			path.push_back(Node(5, 6));
			path.push_back(Node(5, 5));
			path.push_back(Node(6, 5));
			path.push_back(Node(7, 5));
			path.push_back(Node(8, 5));
			path.push_back(Node(9, 5));
			path.push_back(Node(10, 5));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 3));
			path.push_back(Node(9, 3));
			path.push_back(Node(8, 3));
			path.push_back(Node(7, 3));
			path.push_back(Node(6, 3));
			path.push_back(Node(5, 3));
			path.push_back(Node(4, 3));
			path.push_back(Node(3, 3));
			path.push_back(Node(3, 2));
			path.push_back(Node(3, 1));
			path.push_back(Node(4, 1));
			path.push_back(Node(5, 1));
			path.push_back(Node(6, 1));
			path.push_back(Node(7, 1));
			path.push_back(Node(8, 1));
			path.push_back(Node(9, 1));
			path.push_back(Node(10, 1));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel7(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(9, 8));
			path.push_back(Node(8, 8));
			path.push_back(Node(7, 8));
			path.push_back(Node(6, 8));
			path.push_back(Node(5, 8));
			path.push_back(Node(4, 8));
			path.push_back(Node(3, 8));
			path.push_back(Node(2, 8));
			path.push_back(Node(1, 8));
			path.push_back(Node(0, 8));
			path.push_back(Node(0, 7));
			path.push_back(Node(0, 6));
			path.push_back(Node(1, 6));
			path.push_back(Node(2, 6));
			path.push_back(Node(3, 6));
			path.push_back(Node(4, 6));
			path.push_back(Node(5, 6));
			path.push_back(Node(6, 6));
			path.push_back(Node(7, 6));
			path.push_back(Node(8, 6));
			path.push_back(Node(8, 5));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 3));
			path.push_back(Node(8, 2));
			path.push_back(Node(7, 2));
			path.push_back(Node(6, 2));
			path.push_back(Node(6, 3));
			path.push_back(Node(6, 4));
			path.push_back(Node(5, 4));
			path.push_back(Node(4, 4));
			path.push_back(Node(4, 3));
			path.push_back(Node(4, 2));
			path.push_back(Node(3, 2));
			path.push_back(Node(2, 2));
			path.push_back(Node(2, 3));
			path.push_back(Node(2, 4));
			path.push_back(Node(1, 4));
			path.push_back(Node(0, 4));
			path.push_back(Node(0, 3));
			path.push_back(Node(0, 2));
			path.push_back(Node(0, 1));
			path.push_back(Node(0, 0));
			path.push_back(Node(1, 0));
			path.push_back(Node(2, 0));
			path.push_back(Node(3, 0));
			path.push_back(Node(4, 0));
			path.push_back(Node(5, 0));
			path.push_back(Node(6, 0));
			path.push_back(Node(7, 0));
			path.push_back(Node(8, 0));
			path.push_back(Node(9, 0));
			path.push_back(Node(10, 0));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 5));
			path.push_back(Node(10, 6));
			path.push_back(Node(10, 7));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel8SpawnIndex0(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(0, 8));
			path.push_back(Node(1, 8));
			path.push_back(Node(2, 8));
			path.push_back(Node(3, 8));
			path.push_back(Node(4, 8));
			path.push_back(Node(5, 8));
			path.push_back(Node(6, 8));
			path.push_back(Node(6, 7));
			path.push_back(Node(6, 6));
			path.push_back(Node(5, 6));
			path.push_back(Node(4, 6));
			path.push_back(Node(3, 6));
			path.push_back(Node(2, 6));
			path.push_back(Node(2, 5));
			path.push_back(Node(2, 4));
			path.push_back(Node(2, 3));
			path.push_back(Node(2, 2));
			path.push_back(Node(2, 1));
			path.push_back(Node(2, 0));
			path.push_back(Node(3, 0));
			path.push_back(Node(4, 0));
			path.push_back(Node(5, 0));
			path.push_back(Node(6, 0));
			path.push_back(Node(7, 0));
			path.push_back(Node(8, 0));
			path.push_back(Node(9, 0));
			path.push_back(Node(10, 0));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 5));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel8SpawnIndex1(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(10, 7));
			path.push_back(Node(10, 8));
			path.push_back(Node(9, 8));
			path.push_back(Node(8, 8));
			path.push_back(Node(7, 8));
			path.push_back(Node(6, 8));
			path.push_back(Node(6, 7));
			path.push_back(Node(6, 6));
			path.push_back(Node(5, 6));
			path.push_back(Node(4, 6));
			path.push_back(Node(3, 6));
			path.push_back(Node(2, 6));
			path.push_back(Node(2, 5));
			path.push_back(Node(2, 4));
			path.push_back(Node(2, 3));
			path.push_back(Node(2, 2));
			path.push_back(Node(2, 1));
			path.push_back(Node(2, 0));
			path.push_back(Node(3, 0));
			path.push_back(Node(4, 0));
			path.push_back(Node(5, 0));
			path.push_back(Node(6, 0));
			path.push_back(Node(7, 0));
			path.push_back(Node(8, 0));
			path.push_back(Node(9, 0));
			path.push_back(Node(10, 0));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 5));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel8SpawnIndex2(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(5, 4));
			path.push_back(Node(4, 4));
			path.push_back(Node(4, 3));
			path.push_back(Node(4, 2));
			path.push_back(Node(5, 2));
			path.push_back(Node(6, 2));
			path.push_back(Node(7, 2));
			path.push_back(Node(8, 2));
			path.push_back(Node(8, 3));
			path.push_back(Node(8, 4));
			path.push_back(Node(7, 4));
			path.push_back(Node(7, 5));
			path.push_back(Node(7, 6));
			path.push_back(Node(6, 6));
			path.push_back(Node(5, 6));
			path.push_back(Node(4, 6));
			path.push_back(Node(3, 6));
			path.push_back(Node(2, 6));
			path.push_back(Node(2, 5));
			path.push_back(Node(2, 4));
			path.push_back(Node(2, 3));
			path.push_back(Node(2, 2));
			path.push_back(Node(2, 1));
			path.push_back(Node(2, 0));
			path.push_back(Node(3, 0));
			path.push_back(Node(4, 0));
			path.push_back(Node(5, 0));
			path.push_back(Node(6, 0));
			path.push_back(Node(7, 0));
			path.push_back(Node(8, 0));
			path.push_back(Node(9, 0));
			path.push_back(Node(10, 0));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 5));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel8SpawnIndex3(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(0, 0));
			path.push_back(Node(0, 1));
			path.push_back(Node(0, 2));
			path.push_back(Node(0, 3));
			path.push_back(Node(0, 4));
			path.push_back(Node(0, 5));
			path.push_back(Node(1, 5));
			path.push_back(Node(2, 5));
			path.push_back(Node(2, 4));
			path.push_back(Node(2, 3));
			path.push_back(Node(2, 2));
			path.push_back(Node(2, 1));
			path.push_back(Node(2, 0));
			path.push_back(Node(3, 0));
			path.push_back(Node(4, 0));
			path.push_back(Node(5, 0));
			path.push_back(Node(6, 0));
			path.push_back(Node(7, 0));
			path.push_back(Node(8, 0));
			path.push_back(Node(9, 0));
			path.push_back(Node(10, 0));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 5));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel8SpawnIndex4(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(2, 0));
			path.push_back(Node(3, 0));
			path.push_back(Node(4, 0));
			path.push_back(Node(5, 0));
			path.push_back(Node(6, 0));
			path.push_back(Node(7, 0));
			path.push_back(Node(8, 0));
			path.push_back(Node(9, 0));
			path.push_back(Node(10, 0));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 5));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel9SpawnIndex0(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(10, 8));
			path.push_back(Node(9, 8));
			path.push_back(Node(8, 8));
			path.push_back(Node(7, 8));
			path.push_back(Node(6, 8));
			path.push_back(Node(5, 8));
			path.push_back(Node(4, 8));
			path.push_back(Node(3, 8));
			path.push_back(Node(2, 8));
			path.push_back(Node(1, 8));
			path.push_back(Node(0, 8));
			path.push_back(Node(0, 7));
			path.push_back(Node(0, 6));
			path.push_back(Node(1, 6));
			path.push_back(Node(1, 5));
			path.push_back(Node(2, 5));
			path.push_back(Node(2, 4));

			path.push_back(Node(2, 3));
			path.push_back(Node(3, 3));
			path.push_back(Node(4, 3));
			path.push_back(Node(4, 4));
			path.push_back(Node(4, 5));
			path.push_back(Node(4, 6));
			path.push_back(Node(5, 6));
			path.push_back(Node(6, 6));
			path.push_back(Node(6, 5));
			path.push_back(Node(6, 4));
			path.push_back(Node(6, 3));
			path.push_back(Node(6, 2));
			path.push_back(Node(7, 2));
			path.push_back(Node(8, 2));
			path.push_back(Node(8, 3));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 5));
			path.push_back(Node(8, 6));
			path.push_back(Node(9, 6));
			path.push_back(Node(10, 6));
			path.push_back(Node(10, 5));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 3));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel9SpawnIndex1(bool isUsingAltPath)
	{
		static std::vector<Node> path;

		if(path.size() == 0)
		{
			path.push_back(Node(10, 0));
			path.push_back(Node(9, 0));
			path.push_back(Node(8, 0));
			path.push_back(Node(7, 0));
			path.push_back(Node(6, 0));
			path.push_back(Node(5, 0));
			path.push_back(Node(4, 0));
			path.push_back(Node(3, 0));
			path.push_back(Node(2, 0));
			path.push_back(Node(1, 0));
			path.push_back(Node(0, 0));
			path.push_back(Node(0, 1));
			path.push_back(Node(0, 2));
			path.push_back(Node(1, 2));
			path.push_back(Node(1, 3));

			path.push_back(Node(2, 3));
			path.push_back(Node(3, 3));
			path.push_back(Node(4, 3));
			path.push_back(Node(4, 4));
			path.push_back(Node(4, 5));
			path.push_back(Node(4, 6));
			path.push_back(Node(5, 6));
			path.push_back(Node(6, 6));
			path.push_back(Node(6, 5));
			path.push_back(Node(6, 4));
			path.push_back(Node(6, 3));
			path.push_back(Node(6, 2));
			path.push_back(Node(7, 2));
			path.push_back(Node(8, 2));
			path.push_back(Node(8, 3));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 5));
			path.push_back(Node(8, 6));
			path.push_back(Node(9, 6));
			path.push_back(Node(10, 6));
			path.push_back(Node(10, 5));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 3));
		}

		return path;
	}

	static std::vector<Node> getPathForLevel10SpawnIndex0(bool isUsingAltPath)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(2, 8));
			path.push_back(Node(1, 8));
			path.push_back(Node(1, 7));
			path.push_back(Node(1, 6));
			path.push_back(Node(1, 5));

			path.push_back(Node(1, 4));
			path.push_back(Node(2, 4));
			path.push_back(Node(3, 4));
			path.push_back(Node(4, 4));
			path.push_back(Node(5, 4));
			path.push_back(Node(6, 4));
			path.push_back(Node(7, 4));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 3));
			path.push_back(Node(8, 2));
			path.push_back(Node(8, 1));
			path.push_back(Node(9, 1));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 5));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(2, 8));
			pathAlt.push_back(Node(1, 8));
			pathAlt.push_back(Node(1, 7));
			pathAlt.push_back(Node(1, 6));
			pathAlt.push_back(Node(1, 5));

			pathAlt.push_back(Node(1, 4));
			pathAlt.push_back(Node(2, 4));
			pathAlt.push_back(Node(3, 4));
			pathAlt.push_back(Node(4, 4));
			pathAlt.push_back(Node(5, 4));
			pathAlt.push_back(Node(6, 4));
			pathAlt.push_back(Node(7, 4));
			pathAlt.push_back(Node(8, 4));
			pathAlt.push_back(Node(8, 5));
			pathAlt.push_back(Node(8, 6));
			pathAlt.push_back(Node(8, 7));
			pathAlt.push_back(Node(9, 7));
			pathAlt.push_back(Node(10, 7));
			pathAlt.push_back(Node(10, 6));
			pathAlt.push_back(Node(10, 5));
		}

		return isUsingAltPath ? pathAlt : path;
	}

	static std::vector<Node> getPathForLevel10SpawnIndex1(bool isUsingAltPath)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(4, 8));
			path.push_back(Node(4, 7));
			path.push_back(Node(4, 6));
			path.push_back(Node(3, 6));
			path.push_back(Node(2, 6));
			path.push_back(Node(1, 6));
			path.push_back(Node(1, 5));

			path.push_back(Node(1, 4));
			path.push_back(Node(2, 4));
			path.push_back(Node(3, 4));
			path.push_back(Node(4, 4));
			path.push_back(Node(5, 4));
			path.push_back(Node(6, 4));
			path.push_back(Node(7, 4));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 3));
			path.push_back(Node(8, 2));
			path.push_back(Node(8, 1));
			path.push_back(Node(9, 1));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 5));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(4, 8));
			pathAlt.push_back(Node(4, 7));
			pathAlt.push_back(Node(4, 6));
			pathAlt.push_back(Node(3, 6));
			pathAlt.push_back(Node(2, 6));
			pathAlt.push_back(Node(1, 6));
			pathAlt.push_back(Node(1, 5));

			pathAlt.push_back(Node(1, 4));
			pathAlt.push_back(Node(2, 4));
			pathAlt.push_back(Node(3, 4));
			pathAlt.push_back(Node(4, 4));
			pathAlt.push_back(Node(5, 4));
			pathAlt.push_back(Node(6, 4));
			pathAlt.push_back(Node(7, 4));
			pathAlt.push_back(Node(8, 4));
			pathAlt.push_back(Node(8, 5));
			pathAlt.push_back(Node(8, 6));
			pathAlt.push_back(Node(8, 7));
			pathAlt.push_back(Node(9, 7));
			pathAlt.push_back(Node(10, 7));
			pathAlt.push_back(Node(10, 6));
			pathAlt.push_back(Node(10, 5));
		}

		return isUsingAltPath ? pathAlt : path;
	}

	static std::vector<Node> getPathForLevel10SpawnIndex2(bool isUsingAltPath)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(6, 8));
			path.push_back(Node(6, 7));
			path.push_back(Node(6, 6));
			path.push_back(Node(5, 6));
			path.push_back(Node(4, 6));
			path.push_back(Node(3, 6));
			path.push_back(Node(2, 6));
			path.push_back(Node(1, 6));
			path.push_back(Node(1, 5));

			path.push_back(Node(1, 4));
			path.push_back(Node(2, 4));
			path.push_back(Node(3, 4));
			path.push_back(Node(4, 4));
			path.push_back(Node(5, 4));
			path.push_back(Node(6, 4));
			path.push_back(Node(7, 4));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 3));
			path.push_back(Node(8, 2));
			path.push_back(Node(8, 1));
			path.push_back(Node(9, 1));
			path.push_back(Node(10, 1));
			path.push_back(Node(10, 2));
			path.push_back(Node(10, 3));
			path.push_back(Node(10, 4));
			path.push_back(Node(10, 5));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(6, 8));
			pathAlt.push_back(Node(6, 7));
			pathAlt.push_back(Node(6, 6));
			pathAlt.push_back(Node(5, 6));
			pathAlt.push_back(Node(4, 6));
			pathAlt.push_back(Node(3, 6));
			pathAlt.push_back(Node(2, 6));
			pathAlt.push_back(Node(1, 6));
			pathAlt.push_back(Node(1, 5));

			pathAlt.push_back(Node(1, 4));
			pathAlt.push_back(Node(2, 4));
			pathAlt.push_back(Node(3, 4));
			pathAlt.push_back(Node(4, 4));
			pathAlt.push_back(Node(5, 4));
			pathAlt.push_back(Node(6, 4));
			pathAlt.push_back(Node(7, 4));
			pathAlt.push_back(Node(8, 4));
			pathAlt.push_back(Node(8, 5));
			pathAlt.push_back(Node(8, 6));
			pathAlt.push_back(Node(8, 7));
			pathAlt.push_back(Node(9, 7));
			pathAlt.push_back(Node(10, 7));
			pathAlt.push_back(Node(10, 6));
			pathAlt.push_back(Node(10, 5));
		}

		return isUsingAltPath ? pathAlt : path;
	}

	static std::vector<Node> getPathForLevel10SpawnIndex3(bool isUsingAltPath)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(2, 0));
			path.push_back(Node(1, 0));
			path.push_back(Node(1, 1));
			path.push_back(Node(1, 2));
			path.push_back(Node(1, 3));

			path.push_back(Node(1, 4));
			path.push_back(Node(2, 4));
			path.push_back(Node(3, 4));
			path.push_back(Node(4, 4));
			path.push_back(Node(5, 4));
			path.push_back(Node(6, 4));
			path.push_back(Node(7, 4));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 5));
			path.push_back(Node(8, 6));
			path.push_back(Node(8, 7));
			path.push_back(Node(9, 7));
			path.push_back(Node(10, 7));
			path.push_back(Node(10, 6));
			path.push_back(Node(10, 5));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(2, 0));
			pathAlt.push_back(Node(1, 0));
			pathAlt.push_back(Node(1, 1));
			pathAlt.push_back(Node(1, 2));
			pathAlt.push_back(Node(1, 3));

			pathAlt.push_back(Node(1, 4));
			pathAlt.push_back(Node(2, 4));
			pathAlt.push_back(Node(3, 4));
			pathAlt.push_back(Node(4, 4));
			pathAlt.push_back(Node(5, 4));
			pathAlt.push_back(Node(6, 4));
			pathAlt.push_back(Node(7, 4));
			pathAlt.push_back(Node(8, 4));
			pathAlt.push_back(Node(8, 3));
			pathAlt.push_back(Node(8, 2));
			pathAlt.push_back(Node(8, 1));
			pathAlt.push_back(Node(9, 1));
			pathAlt.push_back(Node(10, 1));
			pathAlt.push_back(Node(10, 2));
			pathAlt.push_back(Node(10, 3));
			pathAlt.push_back(Node(10, 4));
			pathAlt.push_back(Node(10, 5));
		}

		return isUsingAltPath ? pathAlt : path;
	}

	static std::vector<Node> getPathForLevel10SpawnIndex4(bool isUsingAltPath)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(4, 0));
			path.push_back(Node(4, 1));
			path.push_back(Node(4, 2));
			path.push_back(Node(3, 2));
			path.push_back(Node(2, 2));
			path.push_back(Node(1, 2));
			path.push_back(Node(1, 3));

			path.push_back(Node(1, 4));
			path.push_back(Node(2, 4));
			path.push_back(Node(3, 4));
			path.push_back(Node(4, 4));
			path.push_back(Node(5, 4));
			path.push_back(Node(6, 4));
			path.push_back(Node(7, 4));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 5));
			path.push_back(Node(8, 6));
			path.push_back(Node(8, 7));
			path.push_back(Node(9, 7));
			path.push_back(Node(10, 7));
			path.push_back(Node(10, 6));
			path.push_back(Node(10, 5));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(4, 0));
			pathAlt.push_back(Node(4, 1));
			pathAlt.push_back(Node(4, 2));
			pathAlt.push_back(Node(3, 2));
			pathAlt.push_back(Node(2, 2));
			pathAlt.push_back(Node(1, 2));
			pathAlt.push_back(Node(1, 3));

			pathAlt.push_back(Node(1, 4));
			pathAlt.push_back(Node(2, 4));
			pathAlt.push_back(Node(3, 4));
			pathAlt.push_back(Node(4, 4));
			pathAlt.push_back(Node(5, 4));
			pathAlt.push_back(Node(6, 4));
			pathAlt.push_back(Node(7, 4));
			pathAlt.push_back(Node(8, 4));
			pathAlt.push_back(Node(8, 3));
			pathAlt.push_back(Node(8, 2));
			pathAlt.push_back(Node(8, 1));
			pathAlt.push_back(Node(9, 1));
			pathAlt.push_back(Node(10, 1));
			pathAlt.push_back(Node(10, 2));
			pathAlt.push_back(Node(10, 3));
			pathAlt.push_back(Node(10, 4));
			pathAlt.push_back(Node(10, 5));
		}

		return isUsingAltPath ? pathAlt : path;
	}

	static std::vector<Node> getPathForLevel10SpawnIndex5(bool isUsingAltPath)
	{
		static std::vector<Node> path;
		static std::vector<Node> pathAlt;

		if(path.size() == 0)
		{
			path.push_back(Node(6, 0));
			path.push_back(Node(6, 1));
			path.push_back(Node(6, 2));
			path.push_back(Node(5, 2));
			path.push_back(Node(4, 2));
			path.push_back(Node(3, 2));
			path.push_back(Node(2, 2));
			path.push_back(Node(1, 2));
			path.push_back(Node(1, 3));

			path.push_back(Node(1, 4));
			path.push_back(Node(2, 4));
			path.push_back(Node(3, 4));
			path.push_back(Node(4, 4));
			path.push_back(Node(5, 4));
			path.push_back(Node(6, 4));
			path.push_back(Node(7, 4));
			path.push_back(Node(8, 4));
			path.push_back(Node(8, 5));
			path.push_back(Node(8, 6));
			path.push_back(Node(8, 7));
			path.push_back(Node(9, 7));
			path.push_back(Node(10, 7));
			path.push_back(Node(10, 6));
			path.push_back(Node(10, 5));
		}

		if(pathAlt.size() == 0)
		{
			pathAlt.push_back(Node(6, 0));
			pathAlt.push_back(Node(6, 1));
			pathAlt.push_back(Node(6, 2));
			pathAlt.push_back(Node(5, 2));
			pathAlt.push_back(Node(4, 2));
			pathAlt.push_back(Node(3, 2));
			pathAlt.push_back(Node(2, 2));
			pathAlt.push_back(Node(1, 2));
			pathAlt.push_back(Node(1, 3));

			pathAlt.push_back(Node(1, 4));
			pathAlt.push_back(Node(2, 4));
			pathAlt.push_back(Node(3, 4));
			pathAlt.push_back(Node(4, 4));
			pathAlt.push_back(Node(5, 4));
			pathAlt.push_back(Node(6, 4));
			pathAlt.push_back(Node(7, 4));
			pathAlt.push_back(Node(8, 4));
			pathAlt.push_back(Node(8, 3));
			pathAlt.push_back(Node(8, 2));
			pathAlt.push_back(Node(8, 1));
			pathAlt.push_back(Node(9, 1));
			pathAlt.push_back(Node(10, 1));
			pathAlt.push_back(Node(10, 2));
			pathAlt.push_back(Node(10, 3));
			pathAlt.push_back(Node(10, 4));
			pathAlt.push_back(Node(10, 5));
		}

		return isUsingAltPath ? pathAlt : path;
	}
};

#endif /* defined(__insectoiddefense__HardCodedPathGenerator__) */