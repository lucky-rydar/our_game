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