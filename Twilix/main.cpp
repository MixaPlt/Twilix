#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "MenuButton.h"
#include "Resources.h"
#include "GlInit.hpp"
#include "Events.h"

int main()
{
	Resources::Init();
	
	MenuButton button("button", sf::Vector2f(400.f, 100.f), sf::Vector2f(200.f, 100.f));

	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 24;
	contextSettings.sRgbCapable = 0;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "Govno", sf::Style::Default, contextSettings);
	window.setVerticalSyncEnabled(true);

	sf::CircleShape shape(60.f, 9);
	shape.setFillColor(sf::Color::Cyan);

	sf::Clock clock;
	while (window.isOpen())
	{
		Events::pollEvents(window);

		// Clear the depth buffer
		glClear(GL_DEPTH_BUFFER_BIT);

		window.pushGLStates();
		window.clear(sf::Color::Blue);
		window.draw(shape);
		button.draw(window);
		window.popGLStates();
		window.display();
	}

	return 0;
}