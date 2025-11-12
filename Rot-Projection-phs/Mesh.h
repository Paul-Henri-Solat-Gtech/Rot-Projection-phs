#pragma once

#include <vector>

#include "Settings.h"

struct Vertex
{
	float x, y, z;
	//void Debug();
};

class Mesh
{
public:
	Mesh(Settings settings);

	void Debug();

	Vertex CreateVertex(float _x, float _y, float _z);

	void GenerateSquare(float size);
	void GenerateRectangle(float width, float height);
	void GenerateCircle(float radius);
	void GenerateHalfCircle(float radius);

private:

	std::vector<Vertex> _vertexList;
	Settings _settings;
	int _resolution;
};

