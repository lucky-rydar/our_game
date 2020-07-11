#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

using namespace std;
using namespace sf;

class LineEdit
{
public:
	LineEdit(sf::Font* font, sf::String str, float x, float y, float sizex, float sizey, sf::Color rectColor, sf::Color txtColor); // Edit Without Background
	LineEdit(sf::Font* font, sf::String str, float x, float y, float ebx, float eby, float erx, float ery, 
		sf::Color bgColor, sf::Color rectColor, sf::Color txtColor); // Edit With Background
	~LineEdit();
	
	void update(Event* eve);
	void draw(sf::RenderWindow* wnd);
	
	sf::RectangleShape* EditBackground;
	sf::RectangleShape* EditRectangle;
	sf::Text* LineEditText;
private:
	stringstream stream_buff;
	bool isSelected;

	void backspace();
	void write(int sym);
	bool isClicked(Vector2i pos);

};

