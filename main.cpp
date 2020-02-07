#include "NerdEngine.h"

int main()
{
	StartGLFW();

	Scene2D scene(1920, 1080);
	scene.SetBackgroundColor(Color3F(1, 0, 1));
	scene.gameObjects.push_back(GameObject2D(200, 200));
	scene.gameObjects[0].renderData = RenderData2D(Vector2DXY(1000, 1000), SHAPE_CIRCLE, 200, 0, nullptr, false);
	scene.Begin();
	EndGLFW();
	return 0;
}