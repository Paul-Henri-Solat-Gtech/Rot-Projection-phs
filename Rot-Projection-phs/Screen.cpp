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
