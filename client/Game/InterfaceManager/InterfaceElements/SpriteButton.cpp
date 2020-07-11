#include "SpriteButton.h"

SpriteButton::SpriteButton(sf::Font* font, sf::String str, float x, float y, float scalex, float scaley, sf::Texture texture, sf::RenderWindow* wnd)
{
	this->wnd = wnd;
	this->texture = texture;

	this->setScale(scalex, scaley);
	this->setTexture(this->texture);

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
}

void SpriteButton::draw()
{
	wnd->draw(*this);
	wnd->draw(*this->ButtonText);
}

void SpriteButton::update()
{

}