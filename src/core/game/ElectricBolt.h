//
//  ElectricBolt.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 12/4/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__ElectricBolt__
#define __insectoiddefense__ElectricBolt__


#include "PhysicalEntity.h"
#include "Color.h"

#include <vector>
#include <memory>

class Creep;
class WorldPlatform;
class Projectile;

class ElectricBolt : public PhysicalEntity
{
public:
	ElectricBolt(float x, float y, float width, float height, float velocityConstant, float directionalAngle, int damage, int fadeTimeSeconds);
	
	void update(float deltaTime, std::vector<std::unique_ptr<Creep>> &creeps, std::vector<std::unique_ptr<WorldPlatform>> &platforms, std::vector<std::unique_ptr<Projectile>> &projectiles);
	
    Color getColor();
	
	bool remove();

private:
	float m_fAlpha;
	float m_fRed;
	float m_fGreen;
	float m_fBlue;
	float m_fDamageTime;
	float m_fFireTime;
	int m_iFadeTimeSeconds;
	int m_iDamage;
	int m_iZapDamage;
	int m_iDamageSinceLastUpdate;
	bool m_hasEscapedTowerPlatform;
	bool m_remove;

	void setVelocity(float directionalAngle, float velocityConstant);
};

#endif /* defined(__insectoiddefense__ElectricBolt__) */