#include "Screen.h"

Screen::Screen(Settings settings) : _settings(settings)
{

}

void Screen::Display()
{
	for (int sh = _settings.GetScreenH(); sh > 0; sh--)
	{
		for (int sw = _settings.GetScreenW(); sw > 0; sw--)
		{
			std::cout << ".";
		}
		std::cout << "\n";
	}

	_settings.PrintInfo();
}

void Screen::DrawMesh(Mesh const& mesh)
{
	//std::fill(m_pixels);

	for (Vertex v : mesh.GetVertices()) 
	{
		//projection
		v.z += 0;
		v.x = v.x / v.z * 0;
		v.y = v.y / v.z * 0;

		//shift(origin->topleftorigin)
		v.x += GetSettings().GetScreenW();
		v.y += GetSettings().GetScreenH();

		int u = std::round(v.x);
		int j = std::round(v.y);
		float ooz = 1.0f / v.z;

		if (u >= 0 && u < GetSettings().GetScreenW() && j >= 0 && j < GetSettings().GetScreenH())
		{
			m_oozBuffer[j * GetSettings().GetScreenW() + u] = ooz;
			m_pixels[j * GetSettings().GetScreenW() + u] = GetSettings().GetScreenMeshProjection();

		}
	}
}

void Screen::Clear()
{
	std::string ansi_clear = "\033[2J";
	std::string ansi_firstPos = "\033[H";
	std::string ansi_hideCursor = "\033[?25l";
	std::string ansi_showCursor = "\033[? 25h";
	printf(ansi_clear.c_str());
	printf(ansi_firstPos.c_str());
	printf(ansi_hideCursor.c_str());
}
