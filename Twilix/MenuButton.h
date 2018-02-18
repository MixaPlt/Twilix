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
	MenuButton(sf::RenderWindow &window, std::string content, sf::Vector2f &size, sf::Vector2f &position);
	~MenuButton();
	void setContent(std::string content);
	void setSize(const sf::Vector2f &size);
	void setFontSize(unsigned int size);	
	void setPosition(const sf::Vector2f &position);
	void draw();
	bool isPressed();
	bool isMouseOver();
	void update();
private:
	sf::RectangleShape rectshape;
	sf::Text text;
	sf::Vector2f position;
	sf::Vector2f size;
	static sf::Color b_color, o_color;
	bool isClick;
	sf::Time lastClick;
	sf::Time overTime;
	sf::RenderWindow &window;
	bool mouseOver;
	unsigned int fontSize;
};

