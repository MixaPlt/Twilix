#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "MenuButton.h"
#include "Resources.h"
#include "GlInit.hpp"
#include "Events.h"
#include "MainMenu.h"
#include <queue>

int main()
{
	Resources::Init();
	

	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 24;
	contextSettings.sRgbCapable = 0;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "Govno", sf::Style::Default, contextSettings);
	window.setVerticalSyncEnabled(true);

	MenuButton button(window, "button", sf::Vector2f(300.f, 100.f), sf::Vector2f(700.f, 100.f));

	MainMenu mainMenu (window);

	sf::CircleShape shape(60.f, 9);
	shape.setFillColor(sf::Color::Cyan);

	sf::Clock clock;
	while (window.isOpen())
	{
		Events::pollEvents(window);
		button.setContent(std::to_string(10000 / (clock.getElapsedTime().asMilliseconds() + 0.01)));
		clock.restart();

		// Clear the depth buffer
		glClear(GL_DEPTH_BUFFER_BIT);

		window.pushGLStates();
		window.clear(sf::Color::Blue);
		window.draw(shape);
		button.draw();
		mainMenu.draw();
		window.popGLStates();
		window.display();
	}

	return 0;
}