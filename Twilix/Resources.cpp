#include "Resources.h"
#include <iostream>

sf::Font* Resources::sansation = new sf::Font;
sf::RenderWindow* Resources::_mainWindow;

Resources::Resources()
{
}

bool Resources::Init(sf::RenderWindow& window)
{
	_mainWindow = &window;
	if (!sansation->loadFromFile("resources/sansation.ttf"))
		return 0;
	return 1;
}

sf::RenderWindow& Resources::mainWindow()
{
	return *Resources::_mainWindow;
}

sf::Font& Resources::getSansation()
{
	return *Resources::sansation;
}