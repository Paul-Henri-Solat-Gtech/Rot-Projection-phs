#include "Mesh.h"

#include <iostream>

Mesh::Mesh(Settings settings): _settings(settings)
{
	_resolution = _settings.GetMeshResolution();
}

void Mesh::Debug()
{
	std::cout << "\nVertexList : [";
	for (auto& v : _vertexList)
	{
		std::cout << "{" << v.x << "," << v.y << "," << v.z << "},";
	}
	std::cout << "] Res:" << _resolution << std::endl;
}

Vertex Mesh::CreateVertex(float _x, float _y, float _z)
{
	Vertex newV;
	newV.x = _x;
	newV.y = _y;
	newV.z = _z;

	_vertexList.push_back(newV);

	return newV;
}

void Mesh::GenerateSquare(float size)
{
}

void Mesh::GenerateRectangle(float width, float height)
{
}

void Mesh::GenerateCircle(float radius)
{
}

void Mesh::GenerateHalfCircle(float radius)
{
}
