#pragma once
#pragma warning(disable: 4244)
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
	InterfaceManager(Client* client, Vector2f winSize = { 1280, 720});
	~InterfaceManager();

	void draw();
	void update();

private:
	Vector2f winSize;

	MainMenu *mainMenu;
	GameMenu *gameMenu;
	RenderWindow *window;
	CurrentIMMenu curMenu;
	Event *eve;
	Client* client;
};

