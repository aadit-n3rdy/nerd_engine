#pragma once
#include <cmath>
namespace structs
{
	struct Vector2DAM
	{
		double angle;
		double magnitude;
		Vector2DAM(double a, double m)
		{
			angle = a;
			magnitude = m;
		}
		Vector2DAM()
		{
			angle = 0;
			magnitude = 0;
		}
	};
	struct Vector2DXY
	{
		double x;
		double y;
		Vector2DXY(double xpos, double ypos)
		{
			x = xpos;
			y = ypos;
		}
		Vector2DXY()
		{
			x = 0;
			y = 0;
		}
	};
	Vector2DXY AMtoXY(Vector2DAM vec)
	{
		return { cos(vec.angle) * vec.magnitude, sin(vec.angle) * vec.magnitude };
	}
	Vector2DAM XYtoAM(Vector2DXY vec)
	{
		return { atan(vec.y / vec.x), sqrt(vec.x * vec.x + vec.y * vec.y) };
	}
	struct Color3F
	{
		float r;
		float g;
		float b;
		Color3F()
		{
			r = 0;
			g = 0;
			b = 0;
		}
		Color3F(float red, float green, float blue)
		{
			r = red;
			g = green;
			b = blue;
		}

	};
	struct Color4F
	{
		float r;
		float g;
		float b;
		float a;
		Color4F()
		{
			r = 0;
			g = 0;
			b = 0;
			a = 1;
		}
		Color4F(float red, float green, float blue, float alpha)
		{
			r = red;
			g = green;
			b = blue;
			a = alpha;
		}
	};
}