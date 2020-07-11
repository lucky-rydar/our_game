#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

using namespace sf;
using namespace std;

class Button : public sf::RectangleShape
{
public:
	Button(sf::Font* font, sf::String str, float x, float y, float scalex, float scaley, sf::Color clr, sf::RenderWindow* wnd);
	~Button();
	void draw();
	void update(Event *eve);

	void setOnButtonFunc(function<void(void)> func);

	sf::Text *ButtonText;
private:
	bool isOnButton(Vector2i pos);

	function<void(void)> onButton;
	RenderWindow *wnd;
};

class Collider
{
public:
private:
};

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