#pragma once
#include "Renderer.h"
#include "GameObject.h"
#include "Window.h"
#include <GLFW/glfw3.h>
#include <vector>

class Scene2D;
void SceneSetup(GLFWwindow* window, int key, int scancode, int action, int mods);

#define KEY(bleh) GLFW_KEY_bleh;

class Scene2D
{
public:
	double delta_time;
	std::vector<GameObject2D> gameObjects;
	Renderer2D renderer;
	Window window;
	void CheckKeyboardEvents()
	{
		int array[349];
		for (int i = -1; i < 349; i++)
		{
			auto state = glfwGetKey(window.window, i);
			if (state == GLFW_PRESS || state == GLFW_REPEAT)
			{
				for (int j = 0; j < gameObjects.size(); j++)
				{
					if (gameObjects[j].OnInput != nullptr)
					{
 						gameObjects[j].OnInput(&gameObjects[j], i, delta_time);
					}
				}
			}
		}
	}

	void KeyCallBack(int key, int scancode, int action, int mods)
	{
		
	}
	void UpdateAll()
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			if (gameObjects[i].Update != nullptr)
			{
				gameObjects[i].Update(&gameObjects[i]);
			}
		}
	}
	void Render()
	{
		delta_time = 0.00001;
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
			double time = glfwGetTime();
			UpdateAll();
			Render();
			glfwPollEvents();
			delta_time = glfwGetTime() - time;
			CheckKeyboardEvents();
		}		
	}
	Scene2D(int width, int height)
	{
		delta_time = 0;
		gameObjects.clear();
		renderer = Renderer2D();
		window = Window(width, height, WINDOW_WINDOWED);
		glfwSetWindowUserPointer(window.window, this);
		//glfwSetKeyCallback(window.window, SceneSetup);
		//glfwSetInputMode(window.window, GLFW_STICKY_KEYS, GLFW_TRUE);
	}

};

void SceneSetup(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	static_cast<Scene2D*>(glfwGetWindowUserPointer(window))->KeyCallBack(key, scancode, action, mods);
	
}
