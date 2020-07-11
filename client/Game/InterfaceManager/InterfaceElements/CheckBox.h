#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class CheckBox
{
public:
	CheckBox(sf::Texture box, sf::Texture mark, float x, float y, float scalex, float scaley, sf::RenderWindow* wnd);
	~CheckBox();

	void draw();
	void update(sf::Event* eve);

	void SetOnCheckFunc(std::function<void(void)> func);
	void SetNonCheckFunc(std::function<void(void)> func);
private:
	bool isOnCheck(sf::Vector2i pos);
	bool isChecked;

	std::function<void(void)> onCheck;
	std::function<void(void)> nonCheck;

	sf::Sprite* Box;
	sf::Sprite* Mark;

	sf::Texture* BoxTexture;
	sf::Texture* MarkTexture;

	sf::RenderWindow* wnd;
};

