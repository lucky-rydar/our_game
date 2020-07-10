#pragma once
#include <SFML/Graphics.hpp>
#include "InterfaceElements/Button.h"
#include "InterfaceElements/Label.h"
#include "InterfaceElements/LineEdit.h"
#include "../Client.h"
using namespace sf;

class MainMenu
{
public:
	MainMenu(sf::Vector2f WindowSize);
	~MainMenu();

	void draw(RenderWindow *win);
	void update(Client *client);
private:
	Button* button;
	Label* label;
	LineEdit*  lineEdit;
};

