#include "CheckBox.h"

CheckBox::CheckBox(sf::Texture box, sf::Texture mark, float x, float y, float scalex, float scaley, sf::RenderWindow* wnd, uint32_t waiting_time)
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

	this->wait_time = waiting_time;
	this->waited = 0;

	timer.restart();
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
	
	auto elapsed = timer.getElapsedTime().asMilliseconds();
	this->waited += elapsed;
	timer.restart();

	if (mouse.isButtonPressed(Mouse::Button::Left) && this->waited >= this->wait_time)
	{
		if (isOnCheck(pos))
		{
			if (this->isChecked)
			{
				this->isChecked = false;
				nonCheck();
			}
			else if (!this->isChecked)
			{
				this->isChecked = true;
				onCheck();
			}
		}

		waited -= wait_time;
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