#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<windows.h>
#include <vector>
struct Vertex
{
	Vertex() {}
	Vertex(float x, float y, float z)
	{
		_x = x;  _y = y;  _z = z;
	}
	float _x, _y, _z;
	static const DWORD FVF;
};

class Point3f
{
public:
	Point3f()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Point3f(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
private:
	float x, y, z;
};

struct float2
{
	float u, v;
};
struct float3
{
	float x, y, z;
};