#include "SpriteButton.h"

SpriteButton::SpriteButton(sf::Font* font, sf::String str, float x, float y, float scalex, float scaley, sf::Texture texture, sf::RenderWindow* wnd)
{
	this->wnd = wnd;
	this->texture = texture;

	this->setScale(scalex, scaley);
	this->setTexture(this->texture);
	this->defaultScale = new sf::Vector2f(scalex, scaley);

	sf::FloatRect bounds;
	const sf::Vector2f box(
		this->getTexture()->getSize().x * this->getScale().x,
		this->getTexture()->getSize().y * this->getScale().y);

	this->setPosition(x, y);

	this->ButtonText = new sf::Text(str, *font);

	bounds = this->ButtonText->getLocalBounds();

	this->ButtonText->setOrigin((bounds.width - box.x) / 2 + bounds.left, (bounds.height - box.y) / 2 + bounds.top);

	this->ButtonText->setPosition(x, y);
}

SpriteButton::~SpriteButton()
{
	delete this->ButtonText;
	delete this->defaultScale;
}

void SpriteButton::draw()
{
	wnd->draw(*this);
	wnd->draw(*this->ButtonText);
}

void SpriteButton::update(sf::Event* eve)
{
	sf::Mouse mouse;
	auto pos = mouse.getPosition(*wnd);

	if (eve->type == sf::Event::MouseButtonPressed)
	{
		if (eve->mouseButton.button == sf::Mouse::Left)
		{
			if (isOnButton(pos))
				this->setScale(0.9, 0.9);
		}
	}

	if (eve->type == sf::Event::MouseButtonReleased)
	{
		if (eve->mouseButton.button == sf::Mouse::Left)
		{
			if (isOnButton(pos))
			{
				this->setScale(*this->defaultScale);
				onButton();
			}
		}
		else if (eve->mouseButton.button == sf::Mouse::Left)
		{
			// we do not need that yet
		}
	}
}

void SpriteButton::setOnButtonFunc(std::function<void(void)> func)
{
	this->onButton = func;
}

bool SpriteButton::isOnButton(sf::Vector2i pos)
{
	return this->getGlobalBounds().contains((float)pos.x, (float)pos.y);
}