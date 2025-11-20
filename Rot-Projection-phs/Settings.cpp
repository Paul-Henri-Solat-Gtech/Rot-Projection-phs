#include "Settings.h"

#include <iostream>

Settings::Settings(int screenWidth, int screenHeight, int meshResolution, char screenBackground, 
	char screenMeshProj, float screenPos, float viewerPos) : _screenWidth(screenWidth), 
	_screenHeight(screenHeight), _meshResolution(meshResolution), _screenBackground(screenBackground), _screenMeshProjection(screenMeshProj), _screenPosition(screenPos), _viewerPosition(viewerPos)
{

}

void Settings::PrintInfo()
{
	std::cout << "\n ScreenSetting: W:" << _screenWidth <<" H:" << _screenHeight << " R:" << _meshResolution << std::endl;
}
