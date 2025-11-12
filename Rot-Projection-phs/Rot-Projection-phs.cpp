#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>

#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"

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

		//Build Screen
		Screen newScreen(newSettings);
		newScreen.Clear();
		newScreen.Display();

		//Mesh
		Mesh newMesh;
		newMesh.CreateVertex(-1, -1, 0);
		newMesh.CreateVertex(-1, 1, 0);
		newMesh.CreateVertex(1, -1, 0);
		newMesh.CreateVertex(1, 1, 0);

		newMesh.Debug();
	}
	else 
	{
		std::cout << "No -start flag given. Use: exe -w 20 -h 10\n";
	}

	// .\Rot-Projection-phs.exe -w 20 -h 20 <-After constructing the release

	return 0;
}