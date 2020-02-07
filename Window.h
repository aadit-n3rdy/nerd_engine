#pragma once
#include <GLFW/glfw3.h>
#include <string>

enum WindowType
{
	WINDOW_WINDOWED,
	WINDOW_FULLSCREEN,
	WINDOW_BORDERLESS
};

class Window
{
public:
	int width;
	int height;
	std::string name;
	WindowType type;
	GLFWwindow* window;
	bool ShouldClose()
	{
		return glfwWindowShouldClose(window);
	}
	Window(int w, int h, WindowType t)
	{
		width = w;
		height = h;
		type = t;
		window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
	}
	Window()
	{
		width = 600;
		height = 480;
		type - WINDOW_WINDOWED;
		window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
	}
};
