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
	MainMenu(sf::Vector2f WindowSize, Event* eve, RenderWindow* win);
	~MainMenu();

	void draw();
	void update(Client *client, CurrentIMMenu* curMenu);
private:
	Button* button;
	Label* label;
	LineEdit*  lineEdit;
	Font *font;
	Event *eve;
	RenderWindow *window;
};

