#pragma once
#include "Structs.h"
#include "GLFW/glfw3.h"
enum RENDER_SHAPE_2D : int {
	SHAPE_CIRCLE,
	SHAPE_EQUILATERAL_TRIANGLE,
	SHAPE_TRIANGLE,
	SHAPE_SQUARE,
	SHAPE_NONE
};

using namespace structs;

class RenderData2D
{
public:
	Vector2DXY position;
	double radius;
	double side;
	bool isHollow;
	RENDER_SHAPE_2D shape;
	Vector2DXY tri_coords[3];
	RenderData2D()
	{
		radius = 0.0;
		side = 0;
		shape = SHAPE_CIRCLE;
		isHollow = true;
		tri_coords[0] = { 0, 0 };
		tri_coords[1] = { 0, 0 };
		tri_coords[2] = { 0, 0 };
		position = Vector2DXY(0, 0);
	}
	RenderData2D(Vector2DXY pos, RENDER_SHAPE_2D sh, double r, double s, Vector2DXY coords[3], bool h)
	{
		position = pos;
		isHollow = h;
		shape = sh;
		radius = r;
		side = s;
		if (coords != NULL)
		{
			tri_coords[0] = coords[0];
			tri_coords[1] = coords[1];
			tri_coords[2] = coords[2];
		}
	}
};
