#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class Resources
{
public:
	Resources();
	static bool Init(sf::RenderWindow&);
	static sf::Font& getSansation();
	static sf::RenderWindow& mainWindow();
private:
	static sf::Font* sansation;
	static sf::RenderWindow* _mainWindow;
};

