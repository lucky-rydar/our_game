#pragma once
#include <SFML/Graphics.hpp>

class Label
{
public:
	Label(sf::Font font, sf::String str, float x, float y);

	~Label();

	sf::Text* LabelText;

	void draw(sf::RenderWindow& wnd);
};

