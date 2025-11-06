#pragma once

#include "Settings.h"

class Screen
{
public:
	Screen(Settings settings);

	void Display();
	void Clear();

	Settings& GetSettings() { return _settings; }

private:

	Settings _settings;
};

