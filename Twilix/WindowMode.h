#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

enum Mode { MainMenu };
class WindowMode
{
public:
	WindowMode();
	~WindowMode();
	static Mode currentMode;
	static void Draw();
};

