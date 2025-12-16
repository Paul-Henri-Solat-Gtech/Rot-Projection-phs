#pragma once

#include <vector>

#include "Settings.h"

class Settings;

enum class Axis
{
	x,
	y,
	z,
};

struct Vertex
{
	void Debug() const { std::printf("[x=%5.2f, y=%5.2f, z=%5.2f]\t[x=%5.2f, y=%5.2f, z=%5.2f]\n", x, y, z, nx, ny, nz); }
	void Rotate(float angle, Axis axis);
	float x;
	float y;
	float z;

	float nx, ny, nz;

	Axis previous;
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
	void GenerateTorus(float majorRadius, float minorRadius);

	const std::vector<Vertex>& GetVertices() const { return _vertexList; }
	std::vector<Vertex>& GetVertices() { return _vertexList; }

	void Rotate(float rotX, float rotY, float rotZ);

private:
	void _GenerateSector(float radius, float angle);

	std::vector<Vertex> _vertexList; // vertices
	Settings _settings;
	int _resolution;
};

