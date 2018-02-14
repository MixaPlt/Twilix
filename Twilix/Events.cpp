#include "Events.h"

sf::Clock Events::mainClock;
sf::Time Events::mouseLeftDown;
sf::Time Events::mouseRightDown;
sf::Time Events::mouseLeftUp;
sf::Time Events::mouseRightUp;

void Events::Init()
{
	
}

void Events::pollEvents(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
				mouseLeftDown = mainClock.getElapsedTime();

			if (event.mouseButton.button == sf::Mouse::Right)
				mouseRightDown = mainClock.getElapsedTime();
		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
				mouseLeftUp = mainClock.getElapsedTime();

			if (event.mouseButton.button == sf::Mouse::Right)
				mouseRightUp = mainClock.getElapsedTime();
		}
	}
}

Events::Events()
{
}


Events::~Events()
{
}
