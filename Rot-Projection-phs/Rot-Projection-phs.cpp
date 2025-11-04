#include <iostream>
#include <Windows.h>

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

    std::cout << "Hello World\n";

    return 0;
}