#include "LineEdit.h"


//TODO: Line edit input
LineEdit::LineEdit(sf::Font font, sf::String str, float x, float y, float sizex, float sizey) // Edit Without Background
{
	this->LineEditText = new sf::Text(str, font);
	this->LineEditText->setPosition(x, y);

	this->EditRectangle = new sf::RectangleShape(sf::Vector2f(sizex, sizey));
	this->EditRectangle->setPosition(x, y);
	
	this->EditBackground = new sf::RectangleShape(sf::Vector2f(sizex, sizey));
	this->EditRectangle->setPosition(x, y);
}

LineEdit::LineEdit(sf::Font font, sf::String str, float x, float y, float ebx, float eby, float erx, float ery) // Edit With Background
{
	this->LineEditText = new sf::Text(str, font);
	this->LineEditText->setPosition(x, y);

	this->EditRectangle = new sf::RectangleShape(sf::Vector2f(erx, ery));
	this->EditRectangle->setPosition(x, y);

	this->EditBackground = new sf::RectangleShape(sf::Vector2f(ebx, eby));
	this->EditRectangle->setPosition(x, y);
}

LineEdit::~LineEdit()
{
	delete this->LineEditText;
	delete this->EditBackground;
	delete this->EditRectangle;
}

void LineEdit::draw(sf::RenderWindow* wnd)
{
	wnd->draw(*this->EditBackground);
	wnd->draw(*this->EditRectangle);
	wnd->draw(*this->LineEditText);
}