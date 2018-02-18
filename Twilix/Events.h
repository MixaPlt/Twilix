#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Poll.h"
#include <queue>
#include <iostream>

class Events
{
public:
	Events();
	~Events();
	static void Init();
	static sf::Clock mainClock;
	static sf::Time mouseLeftDown;
	static sf::Time mouseRightDown;
	static sf::Time mouseLeftUp;
	static sf::Time mouseRightUp;
	static void pollEvents(sf::RenderWindow &window);
	static std::queue <Poll> eventPoll;
private:
	static sf::Event event;
	static Poll poll;
};

