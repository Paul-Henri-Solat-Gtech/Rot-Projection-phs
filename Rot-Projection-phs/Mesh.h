#pragma once

#include <vector>


struct Vertex
{
	float x, y, z;
	//void Debug();
};

class Mesh
{
public:
	void Debug();

	Vertex CreateVertex(float _x, float _y, float _z);

private:

	std::vector<Vertex> _vertexList;
};

