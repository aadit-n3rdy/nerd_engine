#include "NerdEngine.h"
#include <iostream>

void OnInput0(GameObject2D* self, int key, double deltaTime);

int main()
{
	StartGLFW();

	Scene2D scene(1920, 1080);
	scene.SetBackgroundColor(Color3F(0.25, 0, 0.25));
	scene.gameObjects.push_back(GameObject2D(0, 0));
	scene.gameObjects[0].renderData = RenderData2D(Vector2DXY(0, 0), SHAPE_CIRCLE, 200, 0, nullptr, false);
	scene.gameObjects[0].OnInput = &OnInput0;
	scene.Begin();
	EndGLFW();
	return 0;
}

void OnInput0(GameObject2D* self, int key, double deltaTime)
{
	if (key == GLFW_KEY_D)
	{
		self->renderData.position.x += deltaTime * 100;
	}	
	else if (key == GLFW_KEY_A)
	{
		self->renderData.position.x -= deltaTime * 100;
	}
	else if (key == GLFW_KEY_W)
	{
		self->renderData.position.y += deltaTime * 100;
	}
	else if (key == GLFW_KEY_S)
	{
		self->renderData.position.y -= deltaTime * 100;
	}
}
