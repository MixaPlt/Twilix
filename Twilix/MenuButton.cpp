#include "MenuButton.h"


sf::Color MenuButton::b_color(150, 150, 150, 255);
sf::Color MenuButton::o_color(100, 100, 200, 255);

MenuButton::MenuButton(sf::RenderWindow &_window, std::string _content, sf::Vector2f &_size, sf::Vector2f &_position) 
	:window(_window)
{
	lastClick = Events::mainClock.getElapsedTime();

	mouseOver = 0;
	rectshape.setFillColor(b_color);

	//font = Resources::getSansation();
	text.setFont(Resources::getSansation());
	
	rectshape.setOutlineThickness(1);

	setContent(_content);
	setSize(_size);
	setFontSize(70);
	setPosition(_position);
}

void MenuButton::setContent(std::string _content)
{
	text.setString(_content);
	text.setPosition(position + sf::Vector2f((size.x - text.getLocalBounds().width) / 2.f - fontSize * 0.075, (size.y - text.getLocalBounds().height) / 2 - fontSize * 0.3));
}

void MenuButton::setSize(const sf::Vector2f &_size)
{
	rectshape.setSize(_size);
	text.move((_size - size) / 2.f);
	size = _size;
}

void MenuButton::setFontSize(unsigned int _size)
{
	fontSize = _size;
	text.setCharacterSize(_size);
	text.setPosition(position + sf::Vector2f((size.x - text.getLocalBounds().width) / 2.f - _size * 0.075, (size.y - text.getLocalBounds().height) / 2 - _size * 0.3));
}

void MenuButton::setPosition(const sf::Vector2f &_position)
{
	rectshape.setPosition(_position);
	text.move(_position - position);
	position = _position;
}

void MenuButton::draw()
{
	update();
	window.draw(rectshape);
	window.draw(text);
}

bool MenuButton::isPressed()
{
	return isClick;
}

bool MenuButton::isMouseOver()
{
	if (mouseOver && Events::mouseLeftDown >= overTime && Events::mouseLeftUp >= overTime && Events::mouseLeftUp > lastClick)
	{
		lastClick = Events::mouseLeftUp;
		isClick = 1;
		std::cout << "KEK!!!";
	}

	sf::Vector2i m_position = sf::Mouse::getPosition(window);
	
	if (m_position.x > position.x && m_position.y > position.y && m_position.x < position.x + size.x && m_position.y < position.y + size.y)
		return 1;
	return 0;
}

void MenuButton::update()
{
	if (isMouseOver())
	{
		if (!mouseOver)
		{
			rectshape.setFillColor(o_color);
			mouseOver = 1;
			overTime = Events::mainClock.getElapsedTime();
		}
	}
	else
	{
		if (mouseOver)
		{
			rectshape.setFillColor(b_color);
			mouseOver = 0;
		}
	}
}

MenuButton::~MenuButton()
{
}
