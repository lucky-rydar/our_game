#pragma once
#include "InterfaceManager/GameMenu.h"
#include "InterfaceManager/MainMenu.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class InterfaceManager
{
public:
	InterfaceManager();
	~InterfaceManager();

	void update();
	void draw();

private:
	MainMenu *mainMenu;
	GameMenu *gameMenu;
	RenderWindow *window;
	
};

