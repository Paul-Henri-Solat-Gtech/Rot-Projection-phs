#include <iostream>
#include <Windows.h>

struct Vec2
{
    float _x;
    float _y;

    Vec2(float x, float y) { _x = x; _y = y; }
};

void ScreenSimulation() 
{
    Vec2 screenDimension(100,20);

    int screenWidth = screenDimension._x;
    int screenHeight = screenDimension._y;

    for (int sh = screenHeight; sh > 0; sh--)
    {
        for (int sw = screenWidth; sw > 0; sw--)
        {
            std::cout << ".";
        }
        std::cout << "\n";
    }
}

int main(int argc, char** argv)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    std::string ansi_clear = "\033[2J";
    std::string ansi_firstPos = "\033[H";
    std::string ansi_hideCursor = "\033[?25l";
    std::string ansi_showCursor = "\033[? 25h";

    std::cout << "Hello World (this text will be cleared)\n";

    printf(ansi_clear.c_str());
    printf(ansi_firstPos.c_str());
    printf(ansi_hideCursor.c_str());

    //std::cout << "Hello World\n";
    
    ScreenSimulation();

    return 0;
}