#pragma once
#include "InterfaceManager/GameMenu.h"
#include "InterfaceManager/MainMenu.h"
#include <SFML/Graphics.hpp>
#include "Client.h"

using namespace sf;

enum class CurrentIMMenu // it means CurrentInterfaceManagerMenu
{
	Main,
	Game
};

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

