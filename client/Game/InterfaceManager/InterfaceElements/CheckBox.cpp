#include "CheckBox.h"

CheckBox::CheckBox(sf::Texture box, sf::Texture mark, float x, float y, float scalex, float scaley, sf::RenderWindow* wnd)
{
	this->wnd = wnd;

	this->BoxTexture = new sf::Texture(box);
	this->MarkTexture = new sf::Texture(mark);

	this->Box = new sf::Sprite(*this->BoxTexture);
	this->Box->setPosition(x, y);
	this->Box->setScale(scalex, scaley);

	this->Mark = new sf::Sprite(*this->MarkTexture);
	this->Mark->setPosition(x, y);
	this->Mark->setScale(scalex, scaley);

	this->isChecked = new bool;
	this->isChecked = false;
}

CheckBox::~CheckBox()
{
	delete this->Box;
	delete this->Mark;
}

void CheckBox::draw()
{
	this->wnd->draw(*this->Box);
	if (this->isChecked)
		this->wnd->draw(*this->Mark);
}

void CheckBox::update(sf::Event* eve)
{
	sf::Mouse mouse;
	auto pos = mouse.getPosition(*wnd);

	if (eve->type == sf::Event::MouseButtonPressed)
	{
		if (eve->mouseButton.button == sf::Mouse::Left)
		{
			if (isOnCheck(pos))
			{
				if (this->isChecked)
				{
					this->isChecked = false;
					nonCheck();
				}
				if(!this->isChecked)
				{
					this->isChecked = true;
					onCheck();
				}
			}
		}
	}

}


void CheckBox::SetOnCheckFunc(std::function<void(void)> func)
{
	this->onCheck = func;
}

void CheckBox::SetNonCheckFunc(std::function<void(void)> func)
{
	this->nonCheck = func;
}

bool CheckBox::isOnCheck(sf::Vector2i pos)
{
	return this->Box->getGlobalBounds().contains((float)pos.x, (float)pos.y);
}