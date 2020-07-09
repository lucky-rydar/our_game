#pragma once
#include "InterfaceManager/GameMenu.h"
#include "InterfaceManager/MainMenu.h"

class InterfaceManager
{
public:

	InterfaceManager();

	~InterfaceManager();

private:

	MainMenu *mainMenu;

	GameMenu *gameMenu;
};

