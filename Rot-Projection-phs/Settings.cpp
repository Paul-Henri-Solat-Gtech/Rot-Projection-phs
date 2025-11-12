#include "Settings.h"

#include <iostream>

Settings::Settings(int screenWidth, int screenHeight, int meshResolution) : _screenWidth(screenWidth), _screenHeight(screenHeight), _meshResolution(meshResolution)
{
}

void Settings::PrintInfo()
{
	std::cout << "\n ScreenSetting: W:" << _screenWidth <<" H:" << _screenHeight << " R:" << _meshResolution << std::endl;
}
