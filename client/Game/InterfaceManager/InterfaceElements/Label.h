#pragma once
#include <SFML/Graphics.hpp>

class Label : public sf::Text
{
public:
	Label(sf::Font* font, sf::String str, float x, float y, sf::Color clr);
	~Label();
	void draw(sf::RenderWindow* wnd);

private:
	
};

