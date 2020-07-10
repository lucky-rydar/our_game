#include "Label.h"

Label::Label(sf::Font font, sf::String str, float x, float y)
{
	this->setFont(font);
	this->setString(str);
	this->setPosition(sf::Vector2f(x, y));
}

void Label::draw(sf::RenderWindow& wnd)
{
	wnd.draw(*this);
}