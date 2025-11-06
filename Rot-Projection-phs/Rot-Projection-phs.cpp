#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>

#include "Settings.h"

void ScreenSimulation(Settings screenSettings)
{
	for (int sh = screenSettings.GetScreenH(); sh > 0; sh--)
	{
		for (int sw = screenSettings.GetScreenW(); sw > 0; sw--)
		{
			std::cout << ".";
		}
		std::cout << "\n";
	}
}

int main(int argc, char* argv[])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hConsole, &mode);
	SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	// parse args
	int screenWidth = 0;
	int screenHeight = 0;

	bool doStart = false;
	for (int i = 1; i < argc; ++i)
	{
		std::string a = argv[i];
		if (a == "-w" && i + 1 < argc) { screenWidth = std::atoi(argv[++i]); continue; }
		if (a == "-h" && i + 1 < argc) { screenHeight = std::atoi(argv[++i]); continue; }
	}

	if (screenWidth > 0 && screenHeight > 0)
	{
		//Set settings
		Settings newSettings(screenWidth, screenHeight);

		//Clear Screen
		std::string ansi_clear = "\033[2J";
		std::string ansi_firstPos = "\033[H";
		std::string ansi_hideCursor = "\033[?25l";
		std::string ansi_showCursor = "\033[? 25h";
		printf(ansi_clear.c_str());
		printf(ansi_firstPos.c_str());
		printf(ansi_hideCursor.c_str());

		//Build Screen
		ScreenSimulation(newSettings);
	}
	else 
	{
		std::cout << "No -start flag given. Use: exe -w 20 -h 10\n";
	}

	// .\Rot-Projection-phs.exe -w 20 -h 20 After constructing the release

	return 0;
}