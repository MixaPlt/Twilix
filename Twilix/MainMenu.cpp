#include "MainMenu.h"

const std::vector <std::string> MainMenu::strings = {"Multiplayer", "Singleplayer", "Settings", "Exit"};

MainMenu::MainMenu()
{
	for (size_t i = 0; i < strings.size(); i++)
	{
		buttons[i] = new MenuButton(Resources::mainWindow(), strings[i], sf::Vector2f(400.f, 100.f), sf::Vector2f(200.f, i*100.f));
		buttons[i]->setFontSize(50);
	}
}

void MainMenu::draw()
{
	update();
	for (size_t i = 0; i < strings.size(); i++)
		buttons[i]->draw();
}

void MainMenu::update()
{
	for (int i = 0; i < strings.size(); i++)
	{
		if (buttons[i]->isPressed())
		{
			onclick = 1;
			choise = i;
		}
	}
	if (onclick)
	{
		switch (choise)
		{
			case 3:
			{
				Events::eventPoll.push(Poll::Closed);
			}
		}
	}
}

bool MainMenu::onClick()
{
	return onclick;
}

MainMenu::~MainMenu()
{
}
