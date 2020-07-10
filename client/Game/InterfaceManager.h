#pragma once
#include "InterfaceManager/GameMenu.h"
#include "InterfaceManager/MainMenu.h"
#include <SFML/Graphics.hpp>
#include "Client.h"
#include "InterfaceManager/CurrentIMMenu.h"

using namespace sf;

class InterfaceManager
{
public:
	InterfaceManager();
	~InterfaceManager();

	void update(Client *client);
	void draw();

private:
	MainMenu *mainMenu;
	GameMenu *gameMenu;
	RenderWindow *window;
	CurrentIMMenu curMenu;
};

