#include "Settings.h"

#include <iostream>

Settings::Settings(int argc, char** argv) :
	_screenWidth(100),
	_screenHeight(20),
    _screenBackground(' '),
    _screenMeshProjection('X'),
    _screenPosition(3.33f),
	_meshResolution(128),
    _meshPosition(3.33f),
    _viewerPosition(5.f),
    _rotX(0.20f),
    _rotY(0.004f),
    _rotZ(0.0f),
    _frameDuration(100000)
{
    _ParseArguments(argc, argv);
}

void Settings::PrintInfo()
{
	std::cout << "\n ScreenSetting: W:" << _screenWidth <<" H:" << _screenHeight << " R:" << _meshResolution << std::endl;
}

void Settings::_ParseArguments(int argc, char** argv)
{
    // Elegant solution from @T.Rosselet
    for (int i = 1; i < argc; i++) //i starts at 1 because command line arguments start with argv[1] (argv[0] is the name of the exe)
    {
        std::string arg = argv[i];
        if (arg == "-w" && i + 1 < argc)
        {
            _screenWidth = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-h" && i + 1 < argc)
        {
            _screenHeight = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-b" && i + 1 < argc)
        {
            _screenBackground = argv[i + 1][0];
            i++;
        }
        else if (arg == "-p" && i + 1 < argc)
        {
            _screenMeshProjection = argv[i + 1][0];
            i++;
        }
        else if (arg == "-s" && i + 1 < argc)
        {
            _screenPosition = std::atof(argv[i + 1]);
            i++;
        }
        else if (arg == "-r" && i + 1 < argc)
        {
            _meshResolution = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-m" && i + 1 < argc)
        {
            _meshPosition = std::atof(argv[i + 1]);
            i++;
        }
        else if (arg == "-x" && i + 1 < argc) 
        { 
            _rotX = std::atof(argv[i + 1]); 
            i++; 
        }
        else if (arg == "-y" && i + 1 < argc) 
        { 
            _rotY = std::atof(argv[i + 1]); 
            i++; 
        }
        else if (arg == "-z" && i + 1 < argc) 
        { 
            _rotZ = std::atof(argv[i + 1]); 
            i++; 
        }
        else if (arg == "-f" && i + 1 < argc) 
        {
            _frameDuration = std::atol(argv[i + 1]); 
            i++; 
        }
    }
}
