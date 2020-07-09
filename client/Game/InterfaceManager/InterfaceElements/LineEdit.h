#pragma once
#include <SFML/Graphics.hpp>

class LineEdit
{
public:
	LineEdit(sf::Font font, sf::String str, float x, float y, float sizex, float sizey); // Edit Without Background
	LineEdit(sf::Font font, sf::String str, float x, float y, float ebx, float eby, float erx, float ery); // Edit With Background

	~LineEdit();

	sf::RectangleShape* EditBackground;
	sf::RectangleShape* EditRectangle;

	sf::Text* LineEditText;
};

