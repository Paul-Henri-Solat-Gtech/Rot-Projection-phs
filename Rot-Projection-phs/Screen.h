#pragma once

#include "Settings.h"
#include "Mesh.h"

class Screen
{
public:
	Screen(Settings settings);

	void ResetBuffers();

	void Display();
	void DrawMesh(Mesh const& mesh);
	void Clear();

	Settings& GetSettings() { return _settings; }

private:
	Settings _settings;

	std::vector<char> m_pixels;
	std::vector<float> m_oozBuffer;

};

