#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Button : public sf::RectangleShape
{
public:
	Button(sf::Font* font, sf::String str, float x, float y, float scalex, float scaley, sf::Color clr);
	~Button();
	void draw(sf::RenderWindow* wnd);
	bool isOnButton(Vector2i pos);


	sf::Text *ButtonText;

private:

};

