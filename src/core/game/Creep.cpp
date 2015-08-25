//
//  Creep.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 11/10/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#include "Creep.h"
#include "FlagUtil.h"
#include "DamageType.h"
#include "HardCodedPathGenerator.h"
#include "CreepBodyPart.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "GameConstants.h"
#include "GameConstants.h"

#include <stdlib.h>
#include <math.h>

Creep::Creep(float x, float y, float width, float height, float initialSpeed, int maxHealth, int pointValue, int levelIndex, int spawnPointIndex, bool isUsingAltPath) : PhysicalEntity (x, y, width, height, 0)
{
    m_fAlpha = 1.0f;
    m_fRed = 1.0f;
    m_fGreen = 1.0f;
    m_fBlue = 1.0f;
    m_defaultSize = width;
    m_halfSize = width / 2;
    m_maxSize = width * 1.15f;
    m_initialSpeed = initialSpeed;
    m_speed = initialSpeed;
    m_maxHealth = maxHealth;
    m_pointValue = pointValue;
    
    m_rollOverDistance = std::unique_ptr<Vector2D>(new Vector2D());
    m_timeToShowHealthBar = 0;
    m_frozenTime = 0;
    m_burnTime = 0;
    m_electrifiedTime = 0;
    m_poisonedTime = 0;
    m_poisonTime = 0;
    m_health = maxHealth;
    m_creepCondition = HEALTHY;
    m_healthBarFrame = 15;
    m_pathIndex = 0;
    m_direction = calculateInitialDirection();
    m_stickyCount = 0;
    m_levelIndex = levelIndex;
    m_spawnPointIndex = spawnPointIndex;
    m_isUsingAltPath = isUsingAltPath;
    m_state = ALIVE;
    m_fStateTime = 0;
    m_isUsingAltPathOnHullDamage = m_levelIndex == 2 && m_isUsingAltPath == false && (rand() % 2) == 0;
    
    resetBounds(width * SIZE_TO_BOUNDS_RATIO, height * SIZE_TO_BOUNDS_RATIO);
}

void Creep::update(float deltaTime)
{
    m_fStateTime += deltaTime;
    
    m_healthBarFrame = m_health * 16 / m_maxHealth - 1;
    m_healthBarFrame = m_healthBarFrame < 0 ? 0 : m_healthBarFrame;
    
    m_timeToShowHealthBar -= deltaTime;
    
    if (FlagUtil::isFlagSet(m_creepCondition, ELECTRIFIED))
    {
        if (m_electrifiedTime > 0)
        {
            m_electrifiedTime -= deltaTime;
        }
        else
        {
            m_creepCondition = FlagUtil::removeFlag(m_creepCondition, ELECTRIFIED);
            m_speed = m_initialSpeed;
            
            if (FlagUtil::isFlagSet(m_creepCondition, FROZEN))
            {
                m_speed /= 3;
            }
        }
    }
    
    if (FlagUtil::isFlagSet(m_creepCondition, POISONED))
    {
        if (m_poisonedTime > 0)
        {
            bool isFrozen = FlagUtil::isFlagSet(m_creepCondition, FROZEN);
            
            m_poisonedTime -= deltaTime;
            m_poisonTime += deltaTime;
            
            while (m_poisonTime > TIME_FOR_POISON_DAMAGE)
            {
                m_poisonTime -= TIME_FOR_POISON_DAMAGE;
                takeDamage(m_poisonDamage, Damage_Type::ACID);
            }
            
            if (m_isGrowingDueToPoison)
            {
                m_fWidth += deltaTime * (isFrozen ? 0.1f : 0.5f);
                m_fHeight += deltaTime * (isFrozen ? 0.1f : 0.5f);
                if (m_fWidth > m_maxSize)
                {
                    m_fWidth = m_maxSize;
                    m_fHeight = m_maxSize;
                    m_isGrowingDueToPoison = false;
                }
            }
            else
            {
                m_fWidth -= deltaTime * (isFrozen ? 0.1f : 0.5f);
                m_fHeight -= deltaTime * (isFrozen ? 0.1f : 0.5f);
                if (m_fWidth < m_halfSize)
                {
                    m_fWidth = m_halfSize;
                    m_fHeight = m_halfSize;
                    m_isGrowingDueToPoison = true;
                }
            }
        }
        else
        {
            m_creepCondition = FlagUtil::removeFlag(m_creepCondition, POISONED);
            m_fWidth = m_defaultSize;
            m_fHeight = m_defaultSize;
        }
        
        resetBounds(m_fWidth * SIZE_TO_BOUNDS_RATIO, m_fHeight * SIZE_TO_BOUNDS_RATIO);
    }
    
    if (FlagUtil::isFlagSet(m_creepCondition, FROZEN))
    {
        if (m_frozenTime > 0)
        {
            m_frozenTime -= deltaTime;
            m_fRed += m_frozenRecoveryRate * deltaTime;
            m_fGreen = m_fRed;
        }
        else
        {
            thaw();
        }
    }
    else if (FlagUtil::isFlagSet(m_creepCondition, ON_FIRE))
    {
        if (m_burnTime > 0)
        {
            m_burnTime -= deltaTime;
        }
        else
        {
            m_creepCondition = FlagUtil::removeFlag(m_creepCondition, ON_FIRE);
            m_creepCondition = FlagUtil::setFlag(m_creepCondition, FIRE_RECOVERY);
        }
    }
    else if (FlagUtil::isFlagSet(m_creepCondition, FIRE_RECOVERY))
    {
        m_fRed += 1.5f * deltaTime;
        m_fGreen = m_fRed;
        m_fBlue = m_fRed;
        
        if (m_fRed > 1)
        {
            m_creepCondition = FlagUtil::removeFlag(m_creepCondition, FIRE_RECOVERY);
            resetColor();
        }
    }
    
    m_deltaX = m_velocity->getX() * deltaTime;
    m_deltaY = m_velocity->getY() * deltaTime;
    m_position->add(m_deltaX, m_deltaY);
    m_direction = calcDirection();
    updateBounds();
}

bool Creep::isDead()
{
    return FlagUtil::isFlagSet(getState(), SET_TO_REMOVE) || FlagUtil::isFlagSet(getState(), DEAD) || FlagUtil::isFlagSet(getState(), DEPLOYING) || FlagUtil::isFlagSet(getState(), GOAL_REACHED);
}

void Creep::freeze(float frozenTime, int freezeChance)
{
    if ((rand() % freezeChance) == 0)
    {
        if (FlagUtil::isFlagSet(m_creepCondition, ON_FIRE))
        {
            m_creepCondition = FlagUtil::removeFlag(m_creepCondition, ON_FIRE);
        }
        
        if (FlagUtil::isFlagSet(m_creepCondition, FIRE_RECOVERY))
        {
            m_creepCondition = FlagUtil::removeFlag(m_creepCondition, FIRE_RECOVERY);
        }
        
        if (!FlagUtil::isFlagSet(m_creepCondition, FROZEN))
        {
            m_creepCondition = FlagUtil::setFlag(m_creepCondition, FROZEN);
            m_speed /= 3;
        }
        
        m_frozenTime = frozenTime;
        m_frozenRecoveryRate = 0.75f / frozenTime;
        m_fRed = 0.25f;
        m_fGreen = 0.25f;
        m_fBlue = 1.0f;
    }
}

void Creep::electrify()
{
    if (!FlagUtil::isFlagSet(m_creepCondition, ELECTRIFIED))
    {
        m_creepCondition = FlagUtil::setFlag(m_creepCondition, ELECTRIFIED);
        m_speed++;
    }
    
    m_electrifiedTime = 0.50f;
}

void Creep::setOnFire(float burnTime)
{
    m_burnTime = burnTime;
    
    if (FlagUtil::isFlagSet(m_creepCondition, FROZEN))
    {
        thaw();
    }
    
    if (!FlagUtil::isFlagSet(m_creepCondition, ON_FIRE))
    {
        m_creepCondition = FlagUtil::setFlag(m_creepCondition, ON_FIRE);
        m_fRed = 0.25f;
        m_fGreen = 0.25f;
        m_fBlue = 0.25f;
    }
}

void Creep::poison(float poisonedTime, int damage)
{
    if (!FlagUtil::isFlagSet(m_creepCondition, POISONED))
    {
        m_creepCondition = FlagUtil::setFlag(m_creepCondition, POISONED);
    }
    
    m_poisonedTime = poisonedTime;
    m_poisonDamage = damage;
}

void Creep::stick()
{
    m_stickyCount++;
}

bool Creep::canStick()
{
    return m_stickyCount < 40;
}

bool Creep::isFlammable()
{
    return true;
}

bool Creep::canMissilesTarget()
{
    return !FlagUtil::isFlagSet(m_creepCondition, FROZEN);
}

void Creep::deploy(std::vector<Creep *> &creeps, int wave)
{
    setState(DEAD);
}

void Creep::takeZapDamage(int damage)
{
    m_stickyCount--;
    
    takeDamage(damage, ELECTRIC);
}

void Creep::takeDamage(int damage, Damage_Type damageType)
{
    if (applyDamage(damage, damageType))
    {
        displayHealthBar();
    }
    
    if (m_health <= 0)
    {
        kill(damageType);
    }
}

Color Creep::getColor()
{
    Color color = Color(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
    return color;
}

bool Creep::isHealthBarShowing()
{
    return m_timeToShowHealthBar > 0;
}

int Creep::getState()
{
    return m_state;
}

int Creep::getPointValue()
{
    return m_pointValue;
}

int Creep::getHealthBarFrame()
{
    return m_healthBarFrame;
}

int Creep::getCreepCondition()
{
    return m_creepCondition;
}

int Creep::getMaxHealth()
{
    return m_maxHealth;
}

float Creep::getAngle()
{
    return m_direction * 90;
}

void Creep::remove()
{
    setState(SET_TO_REMOVE);
}

// Protected

void Creep::addCreepBodyPartForCreep(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts, Creep_Body_Part_Type type, float initialVelocity, float angleOffset)
{
    creepBodyParts.push_back(std::unique_ptr<CreepBodyPart>(new CreepBodyPart(m_position->getX(), m_position->getY(), m_fWidth, m_fHeight, initialVelocity, getAngle(), getAngle() + angleOffset, m_fAlpha, m_fRed, m_fGreen, m_fBlue, type)));
}

void Creep::addCreepOneBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts, float speed)
{
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::HEAD_1, speed, 0);
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LEFT_WING_1, speed, 51);
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::TAIL_1, speed, 153);
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::RIGHT_WING_1, speed, 310);
}

void Creep::addCreepTwoBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts, float speed)
{
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::HEAD_2, speed, 0);
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LEFT_WING_2, speed, 60);
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LOWER_LEFT_WING_2, speed, 120);
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LOWER_RIGHT_WING_2, speed, 240);
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::RIGHT_WING_2, speed, 300);
}

void Creep::addCreepThreeBodyParts(std::vector<std::unique_ptr<CreepBodyPart>> &creepBodyParts, float speed)
{
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::HEAD_3, speed, 0);
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::LEFT_ARM_3, speed, 60);
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::BODY_3, speed, 180);
    addCreepBodyPartForCreep(creepBodyParts, Creep_Body_Part_Type::RIGHT_ARM_3, speed, 300);
}

void Creep::kill(Damage_Type damageType)
{
    setState(DEAD);
}

void Creep::displayHealthBar()
{
    m_timeToShowHealthBar = 0.5f;
}

void Creep::setState(int newState)
{
    m_state = FlagUtil::setFlag(m_state, newState);
    m_fStateTime = 0;
}

// Private

void Creep::thaw()
{
    m_creepCondition = FlagUtil::removeFlag(m_creepCondition, FROZEN);
    
    resetColor();
    
    m_speed = m_initialSpeed;
    
    if (FlagUtil::isFlagSet(m_creepCondition, ELECTRIFIED))
    {
        m_speed++;
    }
}

void Creep::resetColor()
{
    m_fRed = 1;
    m_fGreen = 1;
    m_fBlue = 1;
}

int Creep::calculateInitialDirection()
{
    std::vector<Node> path = HardCodedPathGenerator::getHardCodedPathForLevelSpawnPointIndex(m_levelIndex, m_spawnPointIndex, m_isUsingAltPath, m_isUsingAltPathOnHullDamage);
    if (path.size() > 2)
    {
        return calcDirectionFromNodes(path.at(0), path.at(1));
    }
    
    return DIRECTION_UP;
}

int Creep::calcDirection()
{
    std::vector<Node> path = HardCodedPathGenerator::getHardCodedPathForLevelSpawnPointIndex(m_levelIndex, m_spawnPointIndex, m_isUsingAltPath, m_isUsingAltPathOnHullDamage);
    if (m_pathIndex == path.size() - 1)
    {
        if (FlagUtil::isFlagSet(m_state, GOAL_POINT_REACHED))
        {
            Node currentNode = path.at(m_pathIndex);
            if ((int) (m_position->getX() - GAME_X) > (currentNode.x + 1))
            {
                setState(GOAL_REACHED);
            }
        }
        else
        {
            setState(GOAL_POINT_REACHED);
        }
        
        m_velocity->set(m_speed, 0);
        return DIRECTION_RIGHT;
    }
    else
    {
        Node currentNode = path.at(m_pathIndex);
        Node nextNode = path.at(m_pathIndex + 1);
        
        int newDirection = calcDirectionFromNodes(currentNode, nextNode);
        
        float delta = 0;
        switch (m_direction)
        {
            case DIRECTION_UP:
                if ((int) (m_position->getY() - GAME_Y) > currentNode.y)
                {
                    m_position->setX(currentNode.x + GAME_X);
                    
                    delta = m_position->getY() - GAME_Y - currentNode.y;
                    
                    m_pathIndex++;
                }
                break;
            case DIRECTION_DOWN:
                if ((int) ceilf(m_position->getY() - GAME_Y) < currentNode.y)
                {
                    m_position->setX(currentNode.x + GAME_X);
                    
                    delta = m_position->getY() - GAME_Y - currentNode.y;
                    
                    m_pathIndex++;
                }
                break;
            case DIRECTION_LEFT:
                if ((int) ceilf(m_position->getX() - GAME_X) < currentNode.x)
                {
                    m_position->setY(currentNode.y + GAME_Y);
                    
                    delta = m_position->getX() - GAME_X - currentNode.x;
                    
                    m_pathIndex++;
                }
                break;
            case DIRECTION_RIGHT:
                if ((int) (m_position->getX() - GAME_X) > currentNode.x)
                {
                    m_position->setY(currentNode.y + GAME_Y);
                    
                    delta = m_position->getX() - GAME_X - currentNode.x;
                    
                    m_pathIndex++;
                }
                break;
        }
        
        if ((m_direction == DIRECTION_LEFT || m_direction == DIRECTION_RIGHT) && (newDirection == DIRECTION_UP || newDirection == DIRECTION_DOWN))
        {
            m_position->setX(currentNode.x + GAME_X);
            m_rollOverDistance->set(0, delta);
        }
        else if ((newDirection == DIRECTION_LEFT || newDirection == DIRECTION_RIGHT) && (m_direction == DIRECTION_UP || m_direction == DIRECTION_DOWN))
        {
            m_position->setY(currentNode.y + GAME_Y);
            m_rollOverDistance->set(delta, 0);
        }
        
        m_position->add(m_rollOverDistance->getX(), m_rollOverDistance->getY());
        m_rollOverDistance->set(0, 0);
        
        return newDirection;
    }
}

int Creep::calcDirectionFromNodes(Node first, Node second)
{
    if (second.x > first.x)
    {
        m_velocity->set(m_speed, 0);
        return DIRECTION_RIGHT;
    }
    else if (second.x < first.x)
    {
        m_velocity->set(-m_speed, 0);
        return DIRECTION_LEFT;
    }
    else if (second.y > first.y)
    {
        m_velocity->set(0, m_speed);
        return DIRECTION_UP;
    }
    else
    {
        m_velocity->set(0, -m_speed);
        return DIRECTION_DOWN;
    }
}