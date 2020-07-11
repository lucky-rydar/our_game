#include "LineEdit.h"


//TODO: Line edit input
LineEdit::LineEdit(sf::Font* font, sf::String str, float x, float y, float sizex, float sizey, sf::Color rectColor, sf::Color txtColor) // Edit Without Background
{
	this->LineEditText = new sf::Text(str, *font);
	this->LineEditText->setPosition(x, y);
	this->LineEditText->setFillColor(txtColor);

	this->EditRectangle = new sf::RectangleShape(sf::Vector2f(sizex, sizey));
	this->EditRectangle->setPosition(x, y);
	this->EditRectangle->setFillColor(rectColor);
	
	this->EditBackground = new sf::RectangleShape(sf::Vector2f(sizex, sizey));
	this->EditBackground->setPosition(x, y);

	isSelected = false;
}

LineEdit::LineEdit(sf::Font* font, sf::String str, float x, float y, float ebx, float eby, float erx, float ery,
	sf::Color bgColor, sf::Color rectColor, sf::Color txtColor) // Edit With Background
{
	this->LineEditText = new sf::Text(str, *font);
	this->LineEditText->setPosition(x, y);
	this->LineEditText->setFillColor(txtColor);

	this->EditRectangle = new sf::RectangleShape(sf::Vector2f(erx, ery));
	this->EditRectangle->setPosition(x, y);
	this->EditRectangle->setFillColor(rectColor);

	this->EditBackground = new sf::RectangleShape(sf::Vector2f(ebx, eby));
	this->EditBackground->setPosition(x, y);
	this->EditBackground->setFillColor(bgColor);
	
	isSelected = false;
}

LineEdit::~LineEdit()
{
	delete this->LineEditText;
	delete this->EditBackground;
	delete this->EditRectangle;
}

void LineEdit::update(Event* eve)
{
	if (eve->type == Event::MouseButtonReleased)
	{
		if (eve->mouseButton.button == Mouse::Left && isClicked(Vector2i(eve->mouseButton.x, eve->mouseButton.y)))
		{
			isSelected = true;
		}
		else if (eve->mouseButton.button == Mouse::Right && isClicked(Vector2i(eve->mouseButton.x, eve->mouseButton.y)))
		{
			// we downt need this yet
		}
	}
	if (eve->type == Event::KeyReleased)
	{
		if (eve->key.code == Keyboard::Escape)
			isSelected = false;
		else if (eve->key.code == Keyboard::BackSpace)
			backspace();
		else
		{
			if(eve->text.unicode < 128)
				write(eve->text.unicode);
		}
			
	}

	LineEditText->setString(stream_buff.str());
}

void LineEdit::draw(sf::RenderWindow* wnd)
{
	wnd->draw(*this->EditBackground);
	wnd->draw(*this->EditRectangle);
	wnd->draw(*this->LineEditText);
}

void LineEdit::backspace()
{
	string temp_str = this->stream_buff.str();
	string new_str;

	for (int i = 0; i < temp_str.length() - 1; i++)
	{
		new_str = temp_str[i];
	}
	stream_buff.str(new_str);
}

void LineEdit::write(int sym)
{
	stream_buff << static_cast<char>(sym);
}

bool LineEdit::isClicked(Vector2i pos)
{
	return this->EditBackground->getGlobalBounds().contains((float)pos.x, (float)pos.y);
}
