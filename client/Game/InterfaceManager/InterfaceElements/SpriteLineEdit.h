#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

class SpriteLineEdit : public sf::Sprite
{
public:
	SpriteLineEdit(sf::Font* font, sf::String str, sf::Texture texture, float x, float y, float scalex, float scaley, sf::RenderWindow* wnd);
	~SpriteLineEdit();

	void draw();
	void update(sf::Event* eve);

	sf::Text* text;
private:
	sf::String* input;

	bool isSelected;

	void backspace();
	void write(sf::Event eve);
	bool isClicked(sf::Vector2i pos);


	sf::Font* font;
	sf::Texture texture;

	sf::RenderWindow* wnd;
};

