#pragma once
#include <SFML/Graphics.hpp>

class Button : public sf::RectangleShape
{
public:
	Button(sf::Font font, sf::String str, float x, float y, float scalex, float scaley);

	~Button();

	sf::Text* ButtonText;

	void draw(sf::RenderWindow& wnd);
};

