#include "pch.h"
#include "ShipModule.h"
#include "Vector2D.h"
#include "Rectangle.h"

ShipModule::ShipModule(float x, float y, float width, float height, Ship_Module_Type type) : DynamicGameObject (x, y, width, height, 0)
{
	m_type = type;
}

Ship_Module_Type ShipModule::getType()
{
	return m_type;
}