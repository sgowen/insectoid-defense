//
//  IceTower.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__IceTower__
#define __insectoiddefense__IceTower__

#include "Tower.h"

class IceBlast;

class IceTower : public Tower
{
public:
	IceTower(float x, float y);

	virtual Tower_Type getTowerType();

	virtual void onRemove();

protected:
	virtual void updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

	virtual void fireAtCreep(Creep *creep);

	virtual void performUpgrade();

	virtual void updatePhysics(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

private:
	IceBlast *m_iceBlast;
	float m_fStateTime;
	float m_fCooldownTime;
};

#endif /* defined(__insectoiddefense__IceTower__) */