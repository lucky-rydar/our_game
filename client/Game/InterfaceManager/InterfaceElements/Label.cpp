#include "Label.h"

Label::Label(sf::Font* font, sf::String str, float x, float y, sf::Color clr)
{
	this->setFont(*font);
	this->setString(str);
	this->setPosition(sf::Vector2f(x, y));
	this->setFillColor(clr);
}

Label::~Label()
{
}

void Label::draw(sf::RenderWindow* wnd)
{
	wnd->draw(*this);
}