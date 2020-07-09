#include "Label.h"

Label::Label(sf::Font font, sf::String str, float x, float y)
{
	this->LabelText = new sf::Text(str, font);

	this->LabelText->setPosition(sf::Vector2f(x, y));
}

Label::~Label()
{
	delete this->LabelText;
}