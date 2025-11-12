#pragma once
#include <iostream>

class Settings
{
public:
	Settings(int screenWidth, int screenHeight);

	int GetScreenW() { return _screenWidth; }
	int GetScreenH() { return _screenHeight; }

	void SetScreenW(int size) { _screenWidth = size; }
	void SetScreenH(int size) { _screenHeight = size; }

private:
	int _screenWidth, _screenHeight;

};