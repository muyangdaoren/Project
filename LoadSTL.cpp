#include "LoadSTL.h"
#include <sstream>
LoadSTL::LoadSTL()
{
}


LoadSTL::~LoadSTL()
{
}
bool LoadSTL::ReadFile(const char *cfilename)
{
	FILE * pFile;
	long lSize;
	char* buffer;
	size_t result;

	fopen_s(&pFile, cfilename, "rb");
	if (pFile == NULL)
	{
		fputs("File error", stderr);
		exit(1);
	}

	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);

	buffer = (char*)malloc(sizeof(char)*lSize);
	if (buffer == NULL)
	{
		fputs("Memory error", stderr);
		exit(2);
	}

	result = fread(buffer, 1, lSize, pFile);
	if (result != lSize)
	{
		fputs("Reading error", stderr);
		exit(3);
	}

	fclose(pFile);

	ios::sync_with_stdio(false);
	if (buffer[79] != '\0')
	{
		ReadASCII(buffer);
	}
	else
	{
		ReadBinary(buffer);
	}
	ios::sync_with_stdio(true);

	free(buffer);
	return true;
}

bool LoadSTL::ReadASCII(const char *buffer)
{
	unTriangles = 0;
	float x, y, z;
	int i;
	string name, useless;
	stringstream ss(buffer);
	ss >> name >> name;
	ss.get();
	do {
		ss >> useless;
		if (useless != "facet")
			break;
		getline(ss, useless);
		getline(ss, useless);
		for (i = 0; i < 3; i++)
		{
			ss >> useless >> x >> y >> z;
			pointList.push_back(Point3f(x, y, z));
		}
		unTriangles++;
		getline(ss, useless);
		getline(ss, useless);
		getline(ss, useless);
	} while (1);
	return true;
}

bool LoadSTL::ReadBinary(const char *buffer)
{
	const char* p = buffer;
	char name[80];
	int i, j;
	memcpy(name, p, 80);
	p += 80;
	unTriangles = cpyint(p);
	for (i = 0; i < unTriangles; i++)
	{
		p += 12;
		for (j = 0; j < 3; j++)
			pointList.push_back(Point3f(cpyfloat(p), cpyfloat(p), cpyfloat(p)));
		p += 2;
	}
	return true;
}

int LoadSTL::NumTri()
{
	return unTriangles;
}

vector<Point3f>& LoadSTL::PointList()
{
	return pointList;
}

int LoadSTL::cpyint(const char*& p)
{
	int cpy;
	memwriter = (char*)&cpy;
	memcpy(memwriter, p, 4);
	p += 4;
	return cpy;
}
float LoadSTL::cpyfloat(const char*& p)
{
	float cpy;
	memwriter = (char*)&cpy;
	memcpy(memwriter, p, 4);
	p += 4;
	return cpy;
}
