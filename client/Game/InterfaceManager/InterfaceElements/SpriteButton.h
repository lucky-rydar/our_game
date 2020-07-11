#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class SpriteButton : public sf::Sprite
{
public:
	SpriteButton(sf::Font* font, sf::String str, float x, float y, float scalex, float scaley, sf::Texture texture, sf::RenderWindow* wnd);
	~SpriteButton();
	void draw();
	void update(sf::Event* eve);

	void setOnButtonFunc(std::function<void(void)> func);
	sf::Text* ButtonText;
private:
	bool isOnButton(sf::Vector2i pos);
	std::function<void(void)> onButton;

	sf::RenderWindow* wnd;
	sf::Texture texture;
	sf::Vector2f* defaultScale;
};