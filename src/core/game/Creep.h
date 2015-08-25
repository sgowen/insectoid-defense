//
//  Creep.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/12/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__Creep__
#define __insectoiddefense__Creep__

#include "PhysicalEntity.h"
#include "DamageType.h"
#include "CreepType.h"
#include "CreepBodyPartType.h"
#include "Color.h"

#include <memory>
#include <vector>

class CreepBodyPart;
struct Node;

class Creep : public PhysicalEntity
{
public:
    virtual Creep_Type getCreepType() = 0;
    
    virtual void scatterCreepBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts) = 0;
    
    Creep(float x, float y, float width, float height, float initialSpeed, int maxHealth, int pointValue, int levelIndex, int spawnPointIndex, bool isUsingAltPath);
    
    virtual void update(float deltaTime);
    
    bool isDead();
    
    virtual void freeze(float frozenTime, int freezeChance);
    
    virtual void electrify();
    
    void setOnFire(float burnTime);
    
    virtual void poison(float poisonedTime, int damage);
    
    void stick();
    
    virtual bool canStick();
    
    virtual bool isFlammable();
    
    virtual bool canMissilesTarget();
    
    virtual void deploy(std::vector<Creep *> &creeps, int wave);
    
    void takeZapDamage(int damage);
    
    void takeDamage(int damage, Damage_Type damageType);
    
    Color getColor();
    
    bool isHealthBarShowing();
    
    int getState();
    
    int getPointValue();
    
    int getHealthBarFrame();
    
    int getCreepCondition();
    
    int getMaxHealth();
    
    float getAngle();
    
    void remove();
    
protected:
    virtual bool applyDamage(int damage, Damage_Type damageType) = 0;
    
    int m_maxHealth;
    int m_health;
    int m_direction;
    int m_pathIndex;
    int m_creepCondition;
    int m_pointValue;
    int m_levelIndex;
    int m_spawnPointIndex;
    bool m_isUsingAltPath;
    
    void addCreepBodyPartForCreep(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts, Creep_Body_Part_Type type, float initialVelocity, float angleOffset);
    
    void addCreepOneBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts, float speed);
    
    void addCreepTwoBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts, float speed);
    
    void addCreepThreeBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts, float speed);
    
    virtual void kill(Damage_Type damageType);
    
    void displayHealthBar();
    
    void setState(int newState);
    
private:
    float m_fAlpha;
    float m_fRed;
    float m_fGreen;
    float m_fBlue;
    float m_defaultSize;
    float m_halfSize;
    float m_maxSize;
    float m_initialSpeed;
    int m_state;
    float m_speed;
    std::unique_ptr<Vector2D> m_rollOverDistance;
    float m_timeToShowHealthBar;
    float m_frozenTime;
    float m_burnTime;
    float m_electrifiedTime;
    float m_poisonedTime;
    float m_poisonTime;
    float m_frozenRecoveryRate;
    float m_deltaX;
    float m_deltaY;
    int m_healthBarFrame;
    int m_stickyCount;
    int m_poisonDamage;
    bool m_isGrowingDueToPoison;
    bool m_isUsingAltPathOnHullDamage;
    
    void thaw();
    
    void resetColor();
    
    int calculateInitialDirection();
    
    int calcDirection();
    
    int calcDirectionFromNodes(Node first, Node second);
};

#endif /* defined(__insectoiddefense__Creep__) */