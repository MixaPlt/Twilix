#include "MenuButton.h"


sf::Color MenuButton::b_color = *new sf::Color(150, 150, 150, 255);
sf::Color MenuButton::o_color = *new sf::Color(100, 100, 200, 255);

MenuButton::MenuButton(std::string _content, sf::Vector2f &_size, sf::Vector2f &_position)
{
	lastClick = Events::mainClock.getElapsedTime();

	mouseOver = 0;
	rectshape.setFillColor(b_color);

	font = *Resources::getSansation();
	text.setFont(font);
	
	rectshape.setOutlineThickness(1);

	setContent(_content);
	setSize(_size);
	setFontSize(70);
	setPosition(_position);
}

void MenuButton::setContent(std::string _content)
{
	text.setString(_content);
}

void MenuButton::setSize(sf::Vector2f &_size)
{
	rectshape.setSize(_size);
	text.move((_size - size) / 2.f);
	size = _size;
}

void MenuButton::setFontSize(unsigned int _size)
{
	text.setCharacterSize(_size);
	text.setPosition(position + sf::Vector2f((size.x - text.getLocalBounds().width) / 2.f - _size * 0.075, (size.y - text.getLocalBounds().height) / 2 - _size * 0.3));
}

void MenuButton::setPosition(sf::Vector2f &_position)
{
	rectshape.setPosition(_position);
	text.move(_position - position);
	position = _position;
}

void MenuButton::draw(sf::RenderWindow &_window)
{
	
	if (isMouseOver(_window))
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
	_window.draw(rectshape);
	_window.draw(text);
}

bool MenuButton::isPressed()
{
	return isClick;
}

bool MenuButton::isMouseOver(sf::RenderWindow &_window)
{
	if (mouseOver && Events::mouseLeftDown >= overTime && Events::mouseLeftUp >= overTime && Events::mouseLeftUp > lastClick)
	{
		lastClick = Events::mouseLeftUp;
		isClick = 1;
		std::cout << "KEK!!!";
	}

	sf::Vector2i m_position = sf::Mouse::getPosition(_window);
	
	if (m_position.x > position.x && m_position.y > position.y && m_position.x < position.x + size.x && m_position.y < position.y + size.y)
		return 1;
	return 0;
}

MenuButton::~MenuButton()
{
}
