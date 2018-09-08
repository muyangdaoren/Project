#pragma once
#include "Data.h"
using namespace std;
class LoadSTL
{
public:
	LoadSTL();
	~LoadSTL();
	bool ReadFile(const char *cfilename);
	int NumTri();
	vector<Point3f>& PointList();
	int getSize()
	{
		return pointList.size();
	}
private:
	vector<Point3f> pointList;
	unsigned int unTriangles;
	bool ReadASCII(const char *cfilename);
	bool ReadBinary(const char *cfilename);

	char* memwriter;
	int cpyint(const char*& p);
	float cpyfloat(const char*& p);
};
