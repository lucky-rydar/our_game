#pragma once
#include <SFML/Graphics.hpp>
#include "InterfaceElements/Button.h"
#include "InterfaceElements/Label.h"
#include "InterfaceElements/LineEdit.h"
#include "../Client.h"
#include "CurrentIMMenu.h"
#include <iostream>

using namespace sf;
using namespace std;

class MainMenu
{
public:
	MainMenu(sf::Vector2f WindowSize);
	~MainMenu();

	void draw(RenderWindow *win);
	void update(Client *client, CurrentIMMenu& curMenu);
private:
	Button* button;
	Label* label;
	LineEdit*  lineEdit;
};

