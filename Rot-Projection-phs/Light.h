#pragma once

#include "Mesh.h"

class Light
{
public:
	Light(Settings settings);

	Vertex const& GetNormalizedLight() const { return m_lightVertex; }
	void Debug() const { m_lightVertex.Debug(); }
private:

	Vertex m_lightVertex;
};

