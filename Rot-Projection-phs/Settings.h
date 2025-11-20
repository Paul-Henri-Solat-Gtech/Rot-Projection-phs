#pragma once
#include <iostream>

class Settings
{
public:
	Settings(int screenWidth, int screenHeight, int meshResolution, char screenBackground, char screenMeshProj, float screenPos, float viewerPos);

	int GetScreenW() { return _screenWidth; }
	int GetScreenH() { return _screenHeight; }
	int GetMeshResolution() { return _meshResolution; }

	char GetScreenBackground() { return _screenBackground; }
	char GetScreenMeshProjection() { return _screenMeshProjection; }
	float GetScreenPosition() { return _screenPosition; }
	float GetViewerPosition() { return _viewerPosition; }

	void SetScreenW(int size) { _screenWidth = size; }
	void SetScreenH(int size) { _screenHeight = size; }
	void SetMeshResolution(int size) { _meshResolution = size; }

	void PrintInfo();

private:
	int _screenWidth, _screenHeight;
	int _meshResolution;

	char _screenBackground;
	char _screenMeshProjection;
	float _screenPosition;
	float _viewerPosition;
};