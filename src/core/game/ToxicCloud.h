//
//  ToxicCloud.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/8/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__ToxicCloud__
#define __insectoiddefense__ToxicCloud__

#include "pch.h"
#include "GameObject.h"
#include "ToxicCloudState.h"
#include "Color.h"

#include <vector>
#include <memory>

class Creep;
class Circle;

class ToxicCloud : public GameObject
{
public:
	ToxicCloud(float x, float y, float initialRadius, float endRadius, float poisonTime, float poisonToCreepHealthRatio);

	void update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);
	
	Circle &getRadius();
	
    Color getColor();
	
	bool remove();

private:
	std::unique_ptr<Circle> m_radius;
	Toxic_Cloud_State m_state;
	float m_fAlpha;
	float m_fRed;
	float m_fGreen;
	float m_fBlue;
	float m_fEndRadius;
	float m_fPoisonTime;
	float m_fPoisonToCreepHealthRatio;
	float m_fTimeForPoisonDisburse;
	float m_fRunningTimeForPoisonDisburse;
	bool m_remove;
};

#endif /* defined(__insectoiddefense__ToxicCloud__) */