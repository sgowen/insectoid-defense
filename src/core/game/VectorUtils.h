//
//  VectorUtils.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/13/13.
//  Copyright (c) 2013 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__VectorUtils__
#define __insectoiddefense__VectorUtils__

#include <string>
#include <sstream>
#include <vector>

class VectorUtils
{
public:
	static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
	{
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim))
		{
			elems.push_back(item);
		}
    
		return elems;
	}


	static std::vector<std::string> split(const std::string &s, char delim)
	{
		std::vector<std::string> elems;
		split(s, delim, elems);
		return elems;
	}
};

#endif /* defined(__insectoiddefense__VectorUtils__) */