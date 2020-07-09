#pragma once
#include <SFML/Graphics.hpp>

class LineEdit : public sf::Shape
{
public:
	LineEdit();

	~LineEdit();

	sf::Text* LineEditText;
};

