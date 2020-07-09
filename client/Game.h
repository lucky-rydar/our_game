#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Game/InterfaceManager.h"
#include "Game/Config.h"
#include "Game/Client.h"

class Game
{
public:

	Game();

	~Game();

private:

	Client *client;

	Config *cfg;

	InterfaceManager *imanager;

};

