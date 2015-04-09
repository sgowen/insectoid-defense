//
//  LazerTower.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/24/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__LazerTower__
#define __insectoiddefense__LazerTower__

#include "Tower.h"
#include "LazerBeamState.h"

class LazerBeam;

class LazerTower : public Tower
{
public:
	LazerTower(float x, float y);

	virtual Tower_Type getTowerType();

	virtual void onRemove();
	
	Lazer_Beam_State getLazerBeamState();

protected:
	virtual void updateReady(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

	virtual void fireAtCreep(Creep *creep);

	virtual void performUpgrade();

	virtual void updatePhysics(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps);

private:
	std::vector<LazerBeam *> m_lazerBeams;
	float m_fStateTime;
	float m_fCooldownTime;
	float m_fFiringTime;
	Lazer_Beam_State m_state;

	void setLazerBeamState(Lazer_Beam_State state);
};

#endif /* defined(__insectoiddefense__LazerTower__) */