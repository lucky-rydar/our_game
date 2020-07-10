#include "Button.h"

//TODO: Text centering
Button::Button(sf::Font font, sf::String str, float x, float y, float sizex, float sizey)
{
	ButtonText = new sf::Text(str, font);

	this->ButtonText->setPosition(x, y);
	
	this->setPosition(x, y);
	this->setSize(sf::Vector2f(sizex, sizey));
}

Button::~Button()
{
	delete this->ButtonText;
}

void Button::draw(sf::RenderWindow* wnd)
{
	wnd->draw(*this);
	wnd->draw(*this->ButtonText);
}