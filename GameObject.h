#pragma once
#include "Component.h"
#include "Structs.h"
#include "RenderData.h"
#include <vector>"
#include <string>

using namespace structs;

class GameObject2D
{
public:
	std::vector<Component2D> components;
	std::string name;
	RenderData2D renderData;
	void (*Update)(GameObject2D*);
	void (*OnInput)(GameObject2D*, int, double);
	GameObject2D()
	{
		components.clear();
		renderData = RenderData2D(Vector2DXY(0, 0), SHAPE_NONE, 0, 0, nullptr, false);
		Update = nullptr;
		OnInput = nullptr;
	}
	GameObject2D(Vector2DXY pos)
	{
		name = "";
		renderData.position = pos;
		components.clear();
		Update = nullptr;
		OnInput = nullptr;
	}
	GameObject2D(double xInp, double yInp)
	{
		renderData.position.x = xInp;
		renderData.position.y = yInp;
		Update = nullptr;
		OnInput = nullptr;
	}
	Component2D* GetComponent(ComponentType2D type)
	{
		for (int i = 0; i < components.size(); i++)
		{
			if (components[i].type == type)
			{
				return &components[i];
			}
		}
		return (Component2D*)nullptr;
	}
	Component2D* GetComponent(ComponentType2D type, std::string name)
	{
		for (int i = 0; i < components.size(); i++)
		{
			if (components[i].type == type && components[i].name == name)
			{
				return &components[i];
			}
		}
		return (Component2D*)nullptr;
	}
	Component2D* GetComponent(std::string name)
	{
		for (int i = 0; i < components.size(); i++)
		{
			if (components[i].name == name)
			{
				return &components[i];
			}
		}
		return (Component2D*)nullptr;
	}
	Component2D* AddComponent(ComponentType2D type, std::string name)
	{
		for (int i = 0; i < components.size(); i++)
		{
			if (components[i].name == name)
			{
				return &components[i];
			}
		}
		components.push_back(Component2D(type));
		return (Component2D*)nullptr;
	}
};
