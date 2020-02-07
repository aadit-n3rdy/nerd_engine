#pragma once
#include "Component.h"
#include "GameObject.h"
#include "RenderData.h"
#include "RenderData.h"
#include "Scene.h"
#include "Structs.h"
#include "Window.h"

#include <GLFW/glfw3.h>

void StartGLFW()
{
	if (!glfwInit())
	{
		throw "Could not init GLFW";
	}
}

void EndGLFW()
{
	glfwTerminate();
}
