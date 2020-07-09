#pragma once
#include <SFML/Graphics.hpp>

class Button : public sf::Shape
{
public:
	Button();

	~Button();

	sf::Text* ButtonText;
};

