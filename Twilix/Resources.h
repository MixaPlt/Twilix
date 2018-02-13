#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class Resources
{
public:
	Resources();
	static bool Init();
	static sf::Font* getSansation();
private:
	static sf::Font* sansation;
};

