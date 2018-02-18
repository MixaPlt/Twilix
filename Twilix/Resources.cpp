#include "Resources.h"
#include <iostream>

sf::Font* Resources::sansation = new sf::Font;

Resources::Resources()
{
}

bool Resources::Init()
{
	if (!sansation->loadFromFile("resources/sansation.ttf"))
		return 0;
	return 1;
}

sf::Font& Resources::getSansation()
{
	return *Resources::sansation;
}