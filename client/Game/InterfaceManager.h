#pragma once
#include "InterfaceManager/GameMenu.h"
#include "InterfaceManager/MainMenu.h"
#include <SFML/Graphics.hpp>
#include "Client.h"
#include "InterfaceManager/CurrentIMMenu.h"
#include <thread>

using namespace sf;

class InterfaceManager
{
public:
	InterfaceManager(Client* client);
	~InterfaceManager();

	void draw();
	void update();

private:
	

	MainMenu *mainMenu;
	GameMenu *gameMenu;
	RenderWindow *window;
	CurrentIMMenu curMenu;
	Event *eve;
	Client* client;
};

