#include "CoreShipModule.h"
#include "Vector2D.h"
#include "Rectangle.h"

CoreShipModule::CoreShipModule(float x, float y, float width, float height) : PhysicalEntity (x, y, width, height, 0)
{
	m_maxHealth = 10;
	m_health = m_maxHealth;

	setState(Core_Ship_Module_State::HAPPY);
}

void CoreShipModule::update(float deltaTime)
{
	m_fStateTime += deltaTime;

	if(m_state == Core_Ship_Module_State::TAKING_DAMAGE && m_fStateTime > 0.25f)
	{
		setState(Core_Ship_Module_State::HAPPY);
	}
}

void CoreShipModule::takeDamage()
{
	setState(Core_Ship_Module_State::TAKING_DAMAGE);
	m_health--;
}

bool CoreShipModule::isAtMaxHealth()
{
	return m_health == m_maxHealth;
}

bool CoreShipModule::isGameOver()
{
	return m_health <= 0;
}

Core_Ship_Module_State CoreShipModule::getState()
{
	return m_state;
}

int CoreShipModule::getMaxHealth()
{
	return m_maxHealth;
}

int CoreShipModule::getRemainingHealth()
{
	return m_health;
}

void CoreShipModule::setState(Core_Ship_Module_State state)
{
	m_state = state;
	m_fStateTime = 0;
}