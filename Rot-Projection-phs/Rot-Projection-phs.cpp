#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>

#include <thread>
#include <chrono>
#include <signal.h>

#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"

// .\Rot-Projection-phs.exe

void ClearConsole()
{
	std::cout << "\x1b[2J"; // Remove all characters in console
	std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
}

void SetCursorVisible(bool visible)
{
    if (visible)
    {
        std::cout << "\x1b[?25h"; // Make cursor visible
    }
    else
    {
        std::cout << "\x1b[?25l"; // Make cursor invisible
    }
}

// Callback pour le kill du programme (Ctrl+C)
void OnKill(int signum)
{
    ClearConsole();
    SetCursorVisible(true); 
    std::exit(signum);      // Termine le programme proprement
}

int main(int argc, char* argv[])
{
    signal(SIGINT, OnKill); // Capture CTRL+C

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hConsole, &mode);
	SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	ClearConsole();

	// parse args
    ClearConsole();
    SetCursorVisible(false);
    Settings settings(argc, argv);
    Screen screen(settings);

    screen.Display();
    Mesh mesh(settings);
    
    mesh.GenerateRectangle(10.f, 20.f);
    std::cout << "Rectangle 10x20:" << std::endl;
    screen.Display(mesh);
    mesh.GenerateSquare(20.f);
    std::cout << "Square 20x20:" << std::endl;
    screen.Display(mesh);
    mesh.GenerateCircle(15.f);
    std::cout << "Circle radius 15:" << std::endl;
    screen.Display(mesh);
    mesh.GenerateHalfCircle(15.f);
    std::cout << "Half Circle radius 15:" << std::endl;
    screen.Display(mesh);

    // Donut
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // pause for generating after those render (cause threads)
    std::cout << "Torus 4x0.9 (rotating):" << std::endl;
    ClearConsole(); // Clear console before torus

    mesh.GenerateTorus(4.f, 0.9f);
    float rotX = settings.GetMeshRotationXPerFrame();
    float rotY = settings.GetMeshRotationYPerFrame();
    float rotZ = settings.GetMeshRotationZPerFrame();
    long frameMicro = settings.GetFrameDuration();
    int torusOffsetY = settings.GetScreenH() / 2; // centre

    while (true)
    {
        std::cout << "\x1b[H"; // reset curseur en haut
        
        mesh.Rotate(rotX, rotY, rotZ);
        screen.Display(mesh);

        std::this_thread::sleep_for(std::chrono::microseconds(frameMicro));
    }


    return 0;
}