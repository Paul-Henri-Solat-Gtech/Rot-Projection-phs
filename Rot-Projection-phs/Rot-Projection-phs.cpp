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
	int meshResolution = 32;

	bool doStart = false;
	for (int i = 1; i < argc; ++i)
	{
		std::string a = argv[i];
		if (a == "-w" && i + 1 < argc) { screenWidth = std::atoi(argv[++i]); continue; }
		if (a == "-h" && i + 1 < argc) { screenHeight = std::atoi(argv[++i]); continue; }
		if (a == "-r" && i + 1 < argc) { meshResolution = std::atoi(argv[++i]); continue; }
	}

	if (screenWidth > 0 && screenHeight > 0)
	{
		//Set settings
		Settings newSettings(screenWidth, screenHeight, meshResolution);

		//Build Screen
		Screen newScreen(newSettings);
		newScreen.Clear();
		newScreen.Display();

		//Mesh
		Mesh newMesh(newSettings);
		newMesh.GenerateRectangle(2.f, 4.f);
		std::cout << "Rectangle 2x4:" << std::endl;
		newMesh.Debug();
		newMesh.GenerateSquare(6.f);
		std::cout << "Square 6x6:" << std::endl;
		newMesh.Debug();
		newMesh.GenerateCircle(2.f);
		std::cout << "Circle radius 2:" << std::endl;
		newMesh.Debug();
		newMesh.GenerateHalfCircle(1.f);
		std::cout << "Half Circle radius 1:" << std::endl;
		newMesh.Debug();
	}
	else 
	{
		std::cout << "No -start flag given. Use: exe -w 20 -h 10 -r 32\n";
	}

	// .\Rot-Projection-phs.exe -w 20 -h 20 -r 32 <-After constructing the release

	return 0;
}