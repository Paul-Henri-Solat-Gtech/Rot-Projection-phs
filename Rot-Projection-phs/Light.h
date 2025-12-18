#pragma once

#include "Mesh.h"

class Light
{
public:
	Light(Settings settings);

	Vertex GetNormalizeLight() { return m_lightVertex; }
private:

	Vertex m_lightVertex;
};

