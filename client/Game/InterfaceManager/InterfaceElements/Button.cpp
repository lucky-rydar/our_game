#include "Button.h"

//TODO: Button origin on centre
Button::Button(sf::Font* font, sf::String str, float x, float y, float scalex, float scaley, sf::Color clr)
{	
	this->setSize(sf::Vector2f(scalex, scaley));
	this->setFillColor(clr);

	sf::FloatRect bounds;
	sf::Vector2f box;

	this->setPosition(x, y);
	ButtonText = new sf::Text(str, *font);

	bounds = this->ButtonText->getLocalBounds();
	box = this->getSize();
	this->ButtonText->setOrigin((bounds.width - box.x) / 2 + bounds.left, (bounds.height - box.y) / 2 + bounds.top);

	this->ButtonText->setPosition(x, y);
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