#include "Mesh.h"

#include <iostream>

void Mesh::Debug()
{
	std::cout << "\nVertexList : [";
	for (auto v : _vertexList) 
	{
		std::cout << "{" << v.x << "," << v.y << "," << v.z << "},";
	}
	std::cout << "]";
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
