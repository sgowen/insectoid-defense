//
//  IceBlast.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/6/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__IceBlast__
#define __insectoiddefense__IceBlast__


#include "PhysicalEntity.h"

#include <vector>
#include <memory>

class Creep;
class Circle;

class IceBlast : public PhysicalEntity
{
public:
	IceBlast(float x, float y);

	void update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

	void performUpgrade();

	void blast();

	bool isBlasting();

	int getIceBlastID();

	virtual float getWidth();

	virtual float getHeight();

private:
	std::unique_ptr<Circle> m_blastRadius;
	float m_fBlastDisplayRadius;
	float m_fFrozenTime;
	int m_iBlastDamage;
	int m_iFreezeChance;
	int m_iIceBlastID;
	bool m_isBlasting;
	bool m_isDamageDealt;
};

#endif /* defined(__insectoiddefense__IceBlast__) */