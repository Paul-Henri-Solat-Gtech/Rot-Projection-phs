#pragma once
#include <iostream>

class Settings
{
public:
	Settings(int screenWidth, int screenHeight, int meshResolution);

	int GetScreenW() { return _screenWidth; }
	int GetScreenH() { return _screenHeight; }
	int GetMeshResolution() { return _meshResolution; }

	void SetScreenW(int size) { _screenWidth = size; }
	void SetScreenH(int size) { _screenHeight = size; }
	void SetMeshResolution(int size) { _meshResolution = size; }

	void PrintInfo();

private:
	int _screenWidth, _screenHeight;
	int _meshResolution;
};