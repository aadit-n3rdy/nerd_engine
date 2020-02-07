#pragma once
#include <string>

enum ComponentType2D
{
	COMPONENT_UNINIT,
	COMPONENT_INT_DATA,
	COMPONENT_FLOAT_DATA,
	COMPONENT_STRING_DATA,
	COMPONENT_CAMERA2D,
	COMPONENT_PHYSICS2D,
	COMPONENT_COLLIDER
};

class Component2D
{
public:
	ComponentType2D type;
	void* data;
	std::string name;
	Component2D()
	{
		type = COMPONENT_UNINIT;
		data = nullptr;
	}
	Component2D(ComponentType2D t, void* d)
	{
		type = t;
		data = d;
	}
	Component2D(ComponentType2D t)
	{
		type = t;
		data = nullptr;
	}
};

