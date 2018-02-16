#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "MenuButton.h"
#include <vector>
#include <string>

class MainMenu
{
public:
	MainMenu(sf::RenderWindow &window);
	~MainMenu();
	void draw();
	void update();
	bool onClick();
	int choise;
private:
	sf::RenderWindow &window;
	static const std::vector <std::string> strings;
	MenuButton* buttons[4];
	bool onclick;
};

