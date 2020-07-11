#include "Button.h"

//TODO: Button origin on centre
Button::Button(sf::Font* font, sf::String str, float x, float y, float scalex, float scaley, sf::Color clr, sf::RenderWindow* wnd)
{	
	this->wnd = wnd;

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

void Button::draw()
{
	wnd->draw(*this);
	wnd->draw(*this->ButtonText);
}

void Button::update(Event *eve)
{
	Mouse mouse;
	auto pos = mouse.getPosition(*wnd);

	if (eve->type == Event::MouseButtonReleased)
	{
		if (eve->mouseButton.button == Mouse::Left)
		{
			if (isOnButton(pos))
				onButton();
		}
		else if(eve->mouseButton.button == Mouse::Left)
		{
			// we do not need that yet
		}
	}
	
}

void Button::setOnButtonFunc(function<void(void)> func)
{
	this->onButton = func;
}

bool Button::isOnButton(Vector2i pos)
{
	return this->getGlobalBounds().contains((float)pos.x, (float)pos.y);
}
