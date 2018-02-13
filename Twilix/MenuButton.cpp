#include "MenuButton.h"


sf::Color MenuButton::b_color = *new sf::Color(150, 150, 150, 255);
sf::Color MenuButton::o_color = *new sf::Color(100, 100, 200, 255);

MenuButton::MenuButton(std::string _content, sf::Vector2f &_size, sf::Vector2f &_position)
{
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

void MenuButton::setFontSize(double _size)
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
	sf::Vector2i m_position = sf::Mouse::getPosition(_window);
	if (m_position.x > position.x && m_position.y > position.y && m_position.x < position.x + size.x && m_position.y < position.y + size.y)
		rectshape.setFillColor(o_color);
	else
		rectshape.setFillColor(b_color);
	_window.draw(rectshape);
	_window.popGLStates();
	_window.pushGLStates();
	_window.draw(text);
}

MenuButton::~MenuButton()
{
}
