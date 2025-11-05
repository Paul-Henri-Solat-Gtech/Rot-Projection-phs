#include <iostream>
#include <Windows.h>
#include <cstdlib>

int screenWidth = 100;
int screenHeight = 20;

struct Vec2
{
	float _x;
	float _y;

	Vec2(float x, float y) { _x = x; _y = y; }
};

void ScreenSimulation()
{
	Vec2 screenDimension(screenWidth, screenHeight);

	int sWidth = screenDimension._x;
	int sHeight = screenDimension._y;

	for (int sh = sHeight; sh > 0; sh--)
	{
		for (int sw = sWidth; sw > 0; sw--)
		{
			std::cout << ".";
		}
		std::cout << "\n";
	}
}

void SetWidth(char* screenW)
{
	screenWidth = std::atoi(screenW);
}
void SetHeight(char* screenH)
{
	screenHeight = std::atoi(screenH);
}

int main(int argc, char* argv[])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hConsole, &mode);
	SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	std::string ansi_clear = "\033[2J";
	std::string ansi_firstPos = "\033[H";
	std::string ansi_hideCursor = "\033[?25l";
	std::string ansi_showCursor = "\033[? 25h";

	// std::cout << "Hello World (this text will be cleared)\n";

	printf(ansi_clear.c_str());
	printf(ansi_firstPos.c_str());
	printf(ansi_hideCursor.c_str());

	//std::cout << "Hello World\n";

	// parse args
	bool doStart = false;
	for (int i = 1; i < argc; ++i)
	{
		std::string a = argv[i];
		if (a == "-w" && i + 1 < argc) { SetWidth(argv[++i]); continue; }
		if (a == "-h" && i + 1 < argc) { SetHeight(argv[++i]); continue; }
		if (a == "-start") { doStart = true; continue; }
		// optionnel: add -help, -w=20 syntax, etc.
	}

	// clear screen etc.
	std::cout << ansi_clear << ansi_firstPos << ansi_hideCursor;

	if (doStart)
	{
		ScreenSimulation();
	}
	else 
	{
		std::cout << "No -start flag given. Use: exe -w 20 -h 10 -start\n";
	}

	// .\Rot-Projection-phs.exe -w 20 -h 20 -start After constructing the release

	return 0;
}