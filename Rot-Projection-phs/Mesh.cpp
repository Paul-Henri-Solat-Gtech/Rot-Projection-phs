#include "Mesh.h"

#include <iostream>

constexpr float PI = 3.14159265f;

Mesh::Mesh(Settings settings): _settings(settings)
{
	_resolution = _settings.GetMeshResolution();
}

void Mesh::Debug()
{
	//std::cout << "\nVertexList : [";
	//for (auto& v : _vertexList)
	//{
	//	std::cout << "{" << v.x << "," << v.y << "," << v.z << "},";
	//}
	//std::cout << "] Res:" << _resolution << std::endl;

	for (Vertex const& vertex : _vertexList)
	{
		vertex.Debug();
	}
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
	GenerateRectangle(size, size);
}

void Mesh::GenerateRectangle(float width, float height)
{
	_vertexList.resize(_settings.GetMeshResolution() * _settings.GetMeshResolution());
	for (int i = 0; i < _settings.GetMeshResolution(); i++)
	{
		for (int j = 0; j < _settings.GetMeshResolution(); j++)
		{
			_vertexList[_settings.GetMeshResolution() * i + j].x = (1.f * i / (_settings.GetMeshResolution() - 1) - 0.5f) * width;
			_vertexList[_settings.GetMeshResolution() * i + j].y = (1.f * j / (_settings.GetMeshResolution() - 1) - 0.5f) * height;
			_vertexList[_settings.GetMeshResolution() * i + j].z = 0.f;
		}
	}
}

void Mesh::GenerateCircle(float radius)
{
	_GenerateSector(radius, 2 * PI);
}

void Mesh::GenerateHalfCircle(float radius)
{
	_GenerateSector(radius, PI);
}

void Mesh::_GenerateSector(float radius, float angle)
{
	_vertexList.resize(_settings.GetMeshResolution() * _settings.GetMeshResolution());
	for (int i = 0; i < _settings.GetMeshResolution(); i++)
	{
		float r = (radius * i) / (_settings.GetMeshResolution() - 1);
		for (int j = 0; j < _settings.GetMeshResolution(); j++)
		{
			float theta = (angle * j) / (_settings.GetMeshResolution() - 1);
			_vertexList[_settings.GetMeshResolution() * i + j].x = r * std::cos(theta);
			_vertexList[_settings.GetMeshResolution() * i + j].y = r * std::sin(theta);
			_vertexList[_settings.GetMeshResolution() * i + j].z = 0.f;
		}
	}
}

void Vertex::Rotate(float angle, Axis axis)
{
	float px = x;
	float py = y;
	float pz = z;

	switch (axis)
	{
	case Axis::x:
		y = py * std::cos(angle) - pz * std::sin(angle);
		z = py * std::sin(angle) + pz * std::cos(angle);
		break;
	case Axis::y:
		x = px * std::cos(angle) + pz * std::sin(angle);
		z = -px * std::sin(angle) + pz * std::cos(angle);
		break;
	case Axis::z:
		x = px * std::cos(angle) - py * std::sin(angle);
		y = px * std::sin(angle) + py * std::cos(angle);
		break;
	}
}