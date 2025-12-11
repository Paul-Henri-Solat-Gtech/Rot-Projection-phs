#include "Mesh.h"
#include <cmath>
#include <iostream>

constexpr float PI = 3.14159265f;

Mesh::Mesh(Settings settings): _settings(settings)
{
	_resolution = _settings.GetMeshResolution();
}

void Mesh::Debug()
{
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
	_GenerateSector(radius, 2*PI);
}

void Mesh::GenerateHalfCircle(float radius)
{
	_GenerateSector(radius, PI);
}

void Mesh::GenerateTorus(float majorRadius, float minorRadius)
{
	int res = _settings.GetMeshResolution();
	_vertexList.resize(res * res);

	for (int j = 0; j < res; ++j) // phi : angle autour de l'anneau principal
	{
		float phi = (2.0f * PI * j) / (res - 1);
		float cosPhi = std::cos(phi);
		float sinPhi = std::sin(phi);

		for (int i = 0; i < res; ++i) // theta : angle autour du tube
		{
			float theta = (2.0f * PI * i) / (res - 1);
			float cosTheta = std::cos(theta);
			float sinTheta = std::sin(theta);

			// (R + r cosƒÆ) cosƒÓ, (R + r cosƒÆ) sinƒÓ, r sinƒÆ
			float tubeCenter = majorRadius + minorRadius * cosTheta;
			float x = tubeCenter * cosPhi;
			float y = minorRadius * sinTheta;
			float z = tubeCenter * sinPhi;

			_vertexList[res * j + i].x = x;
			_vertexList[res * j + i].y = y;
			_vertexList[res * j + i].z = z;
		}
	}
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

void Mesh::Rotate(float rotX, float rotY, float rotZ)
{
	for (auto& v : _vertexList)
	{
		if (rotX != 0.0f) v.Rotate(rotX, Axis::x);
		if (rotY != 0.0f) v.Rotate(rotY, Axis::y);
		if (rotZ != 0.0f) v.Rotate(rotZ, Axis::z);
	}
}

void Vertex::Rotate(float angle, Axis axis)
{
	float pastX = x;
	float pastY = y;
	float pastZ = z;

	switch (axis)
	{
	case Axis::x:
		y = pastY * std::cos(angle) - pastZ * std::sin(angle);
		z = pastY * std::sin(angle) + pastZ * std::cos(angle);
		break;
	case Axis::y:
		x = pastZ * std::sin(angle)  + pastX * std::cos(angle);
		z = pastZ * std::cos(angle) - pastX * std::sin(angle);
		break;
	case Axis::z:
		x = pastX * std::cos(angle) - pastY * std::sin(angle);
		y = pastX * std::sin(angle) + pastY * std::cos(angle);
		break;
	}
}