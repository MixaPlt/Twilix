#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "MenuButton.h"
#include "Resources.h"
#include "GlInit.hpp"

int main()
{
	Resources::Init();

	glInit();
	
	MenuButton button("button", sf::Vector2f(400.f, 100.f), sf::Vector2f(200.f, 100.f));

	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 24;
	contextSettings.sRgbCapable = 0;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "Govno", sf::Style::Default, contextSettings);
	window.setVerticalSyncEnabled(true);

	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
	glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 100.f);

	sf::CircleShape shape(60.f, 9);
	shape.setFillColor(sf::Color::Cyan);

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear the depth buffer
		glClear(GL_DEPTH_BUFFER_BIT);
		window.pushGLStates();
		window.clear(sf::Color::Blue);
		//window.draw(shape);
		button.draw(window);
		window.popGLStates();
		window.display();
	}

	return 0;
}