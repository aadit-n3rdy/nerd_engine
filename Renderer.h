#pragma once
#include "Component.h"
#include "Structs.h"
#include <GLFW/glfw3.h>
#include <cmath>

using namespace structs;

class Renderer2D
{
public:
	Color3F backgroundColor;

	void PreRender()
	{
		glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void PostRender(GLFWwindow* window)
	{
		glfwSwapBuffers(window);
	}

	void Render(RenderData2D renderData, int width, int height)
	{
		if (renderData.shape == SHAPE_CIRCLE)
		{
			if (renderData.isHollow)
			{
				glBegin(GL_LINE_LOOP);
			}
			else
			{
				glBegin(GL_TRIANGLE_FAN);
				glVertex2f(renderData.position.x / (float)width, renderData.position.y / (float)height);
			}
			float radius = renderData.radius;
			for (int i = 0; i < 2 * radius + 1; i++)
			{
				double theta = 3.1415926 * i / radius;
				glVertex2f((renderData.position.x + cos(theta) * radius) / (float)width, (renderData.position.y + sin(theta) * radius) / (float)height);
			}
			glEnd();
		}
		else if (renderData.shape == SHAPE_SQUARE)
		{
			Vector2DXY vertices[4];
			double x = renderData.position.x;
			double y = renderData.position.y;
			double side = renderData.side;
			vertices[0] = Vector2DXY(x + side / 2, y + side / 2);
			vertices[1] = Vector2DXY(x - side / 2, y + side / 2);
			vertices[2] = Vector2DXY(x - side / 2, y - side / 2);
			vertices[3] = Vector2DXY(x + side / 2, y - side / 2);
			if (renderData.isHollow)
			{
				glBegin(GL_LINE_LOOP);
				glVertex2f(vertices[0].x, vertices[0].y);
				glVertex2f(vertices[1].x, vertices[1].y);
				glVertex2f(vertices[2].x, vertices[2].y);
				glVertex2f(vertices[3].x, vertices[3].y);
				glEnd();
			}
			else
			{
				glBegin(GL_TRIANGLE_STRIP);
				glVertex2f(vertices[0].x, vertices[0].y);
				glVertex2f(vertices[1].x, vertices[1].y);
				glVertex2f(vertices[3].x, vertices[3].y);
				glVertex2f(vertices[2].x, vertices[2].y);
				glEnd();
			}
		}

	}

};
