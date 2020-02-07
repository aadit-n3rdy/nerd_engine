#pragma once
#include "Renderer.h"
#include "GameObject.h"
#include "Window.h"
#include <vector>

class Scene2D
{
public:
	std::vector<GameObject2D> gameObjects;
	Renderer2D renderer;
	Window window;
	void Render()
	{
		renderer.PreRender();
		for (int i = 0; i < gameObjects.size(); i++)
		{
			if (gameObjects[i].renderData.shape != SHAPE_NONE)
			{
				renderer.Render(gameObjects[i].renderData, window.width, window.height);
			}
		}
		renderer.PostRender(window.window);
	}
	void SetBackgroundColor(Color3F color)
	{
		renderer.backgroundColor = color;
	}

	void Begin()
	{
		while (!window.ShouldClose())
		{
			Render();
			glfwPollEvents();
		}
	}
	Scene2D(int width, int height)
	{
		gameObjects.clear();
		renderer = Renderer2D();
		window = Window(width, height, WINDOW_WINDOWED);
	}

};
