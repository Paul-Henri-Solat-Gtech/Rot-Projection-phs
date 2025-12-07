#pragma once

#include "Settings.h"
#include "Mesh.h"

class Screen
{
public:
	Screen(Settings settings);

	void ResetBuffers();

	void Display();
	void Display(Mesh const& mesh);
	void DrawMesh(Mesh const& mesh);
	void Clear();

	Settings& GetSettings() { return _settings; }

private:
	void _ProjectInCenterScreenSpace(Vertex& vertex);
	void _ProjectInTopLeftScreenSpace(Vertex& vertex);
	bool _IsVertexInScreen(int u, int v);

	Settings _settings;

	std::vector<char> m_pixels;
	std::vector<float> m_oozBuffer;

};

