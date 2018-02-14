#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Resources.h"
#include <string>
#include <iostream>
#include "Events.h"

class MenuButton
{
public:
	MenuButton(std::string content, sf::Vector2f &size, sf::Vector2f &position);
	~MenuButton();
	void setContent(std::string content);
	void setSize(sf::Vector2f &size);
	void setFontSize(unsigned int size);	
	void setPosition(sf::Vector2f &position);
	void draw(sf::RenderWindow &window);
	bool isPressed();
	bool isMouseOver(sf::RenderWindow &window);
private:
	sf::RectangleShape rectshape;
	sf::Text text;
	sf::Font font;
	sf::Vector2f position;
	sf::Vector2f size;
	static sf::Color b_color, o_color;
	bool isClick;
	sf::Time lastClick;
	sf::Time overTime;
	bool mouseOver;
};

