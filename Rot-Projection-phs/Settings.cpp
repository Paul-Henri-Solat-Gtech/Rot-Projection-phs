#include "Settings.h"

#include <iostream>

Settings::Settings(int argc, char** argv) :
	_screenWidth(100),
	_screenHeight(20),
    _screenBackground(' '),
    _screenMeshProjection('X'),
    _screenPosition(3.33f),
	_meshResolution(80),
    _meshPosition(3.33f),
    _viewerPosition(5.f)
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
    }
}
