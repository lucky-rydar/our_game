#include "Button.h"

//TODO: Text centering
Button::Button(sf::Font font, sf::String str, float x, float y, float sizex, float sizey)
{
	this->ButtonText = new sf::Text(str, font);

	this->ButtonText->setPosition(x, y);

	this->setPosition(x, y);
	this->setSize(sf::Vector2f(sizex, sizey));
}

Button::~Button()
{
	delete this->ButtonText;
}