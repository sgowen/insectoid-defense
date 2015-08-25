//
//  LazerBeam.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/5/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__LazerBeam__
#define __insectoiddefense__LazerBeam__


#include "Color.h"

#include <vector>
#include <memory>

class Line;
class Creep;

class LazerBeam
{
public:
	LazerBeam(float x, float y, float alpha, int damageRate);

	void update(float red, float green, float blue);

	void checkCreepsHitByLazerBeam(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);
	
	void fire(float endX, float endY);

	void reset();
	
	void increaseDamageRate();
	
	Line & getPath();

	Color getColor();
	
	bool isFiring();

	int getLazerBeamID();

private:
	std::unique_ptr<Line> m_path;
	float m_fAlpha;
	float m_fRed;
	float m_fGreen;
	float m_fBlue;
	float m_fDamageTime;
	float m_fFireTime;
	int m_iDamageRate;
	int m_iDamage;
	int m_iLazerBeamID;
	bool m_isFiring;
};

#endif /* defined(__insectoiddefense__LazerBeam__) */