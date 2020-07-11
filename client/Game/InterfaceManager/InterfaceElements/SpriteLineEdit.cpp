#include "SpriteLineEdit.h"

SpriteLineEdit::SpriteLineEdit(sf::Font* font, sf::String str, sf::Texture texture, float x, float y, float scalex, float scaley, sf::RenderWindow* wnd)
{
	this->wnd = wnd;
	this->texture = texture;
	this->isSelected = false;

	this->font = font;
	this->text = new sf::Text(str, *font);

	this->setTexture(this->texture);
	this->setScale(scalex, scaley);

	const sf::FloatRect bounds(this->text->getLocalBounds());
	const sf::Vector2f box(
		this->getTexture()->getSize().x * this->getScale().x,
		this->getTexture()->getSize().y * this->getScale().y);

	this->text->setOrigin(-20, (bounds.height - box.y) / 2 + bounds.top);
	this->text->setPosition(x, y);

	this->setPosition(x, y);
	
	this->input = new sf::String;
}

SpriteLineEdit::~SpriteLineEdit()
{
	delete this->text;
	delete this->input;
}

void SpriteLineEdit::draw()
{
	this->wnd->draw(*this);
	this->wnd->draw(*this->text);
}

void SpriteLineEdit::update(sf::Event* eve)
{
	if (eve->type == sf::Event::MouseButtonReleased)
	{
		if (eve->mouseButton.button == sf::Mouse::Left && isClicked(sf::Vector2i(eve->mouseButton.x, eve->mouseButton.y)))
			isSelected = true;
		if (eve->mouseButton.button == sf::Mouse::Left && !isClicked(sf::Vector2i(eve->mouseButton.x, eve->mouseButton.y)))
			isSelected = false;
		if (eve->mouseButton.button == sf::Mouse::Right && !isClicked(sf::Vector2i(eve->mouseButton.x, eve->mouseButton.y)))
			isSelected = false;
	}
	if (eve->type == sf::Event::KeyReleased)
	{
		if (eve->key.code == sf::Keyboard::Escape)
			isSelected = false;
		else if (eve->key.code == sf::Keyboard::BackSpace)
			backspace();
		else
		{
				write(*eve);
		}

	}
}

void SpriteLineEdit::backspace()
{
	this->input--;
	this->text->setString(*input);
}

void SpriteLineEdit::write(sf::Event eve)
{
	this->input += eve.text.unicode;
	this->text->setString(*input);
}

bool SpriteLineEdit::isClicked(sf::Vector2i pos)
{
	return this->getGlobalBounds().contains(sf::Vector2f(pos));
}