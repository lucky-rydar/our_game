#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class SpriteButton : public sf::Sprite
{
public:
	SpriteButton(sf::Font* font, sf::String str, float x, float y, float scalex, float scaley, sf::Texture texture, sf::RenderWindow* wnd);
	~SpriteButton();
	void draw();
	void update();

	sf::Text* ButtonText;
private:
	RenderWindow* wnd;
	sf::Texture texture;
};