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

	sf::RenderWindow window(sf::VideoMode(1024, 660), "Govno", sf::Style::Default, contextSettings);
	

	MenuButton button(window, "button", sf::Vector2f(300.f, 100.f), sf::Vector2f(700.f, 100.f));

	MainMenu mainMenu (window);

	sf::CircleShape shape(60.f, 9);
	shape.setFillColor(sf::Color::Cyan);

	sf::Text fpsText("FPS: ", Resources::getSansation(), 30);
	fpsText.setPosition(sf::Vector2f(0.f, 630.f));

	sf::Clock clock;

	int a = 0;
	while (window.isOpen())
	{
		Events::pollEvents(window);
		a++;
		if (clock.getElapsedTime().asMilliseconds() > 400)
		{
			fpsText.setString("FPS: " + std::to_string(int(1000000.f / clock.getElapsedTime().asMicroseconds() * a)));
			a = 0;
			clock.restart();
		}

		// Clear the depth buffer
		glClear(GL_DEPTH_BUFFER_BIT);

		window.pushGLStates();
		window.clear(sf::Color::Blue);
		window.draw(shape);
		mainMenu.draw();
		button.draw();
		window.draw(fpsText);
		window.popGLStates();
		window.display();
	}

	return 0;
}