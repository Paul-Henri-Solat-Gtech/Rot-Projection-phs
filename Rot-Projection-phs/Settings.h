#pragma once
#include <iostream>

class Settings
{
public:
	Settings(int argc, char** argv);

	int GetScreenW() { return _screenWidth; }
	int GetScreenH() { return _screenHeight; }

	int GetMeshResolution() { return _meshResolution; }
	float GetMeshPosition() { return _meshPosition; }

	char GetScreenBackground() { return _screenBackground; }
	char GetScreenMeshProjection() { return _screenMeshProjection; }
	float GetScreenPosition() { return _screenPosition; }
	float GetViewerPosition() { return _viewerPosition; }

	void SetScreenW(int size) { _screenWidth = size; }
	void SetScreenH(int size) { _screenHeight = size; }
	void SetMeshResolution(int size) { _meshResolution = size; }

	void PrintInfo();

	void _ParseArguments(int argc, char** argv);

private:
	int _screenWidth, _screenHeight;
	int _meshResolution;
	float _meshPosition;

	char _screenBackground;
	char _screenMeshProjection;
	float _screenPosition;
	float _viewerPosition;
};