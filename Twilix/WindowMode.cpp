#include "WindowMode.h"

Mode WindowMode::currentMode = MainMenu;

void WindowMode::Draw()
{
	switch (currentMode)
	{
		case MainMenu:
		{

		}
		default:
			break;
	}
}

WindowMode::WindowMode()
{
}


WindowMode::~WindowMode()
{
}
