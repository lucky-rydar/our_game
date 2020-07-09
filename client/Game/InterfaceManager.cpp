#include "InterfaceManager.h"

InterfaceManager::InterfaceManager()
{
	this->gameMenu = new GameMenu;
	this->mainMenu = new MainMenu;
}

InterfaceManager::~InterfaceManager()
{
	delete this->gameMenu;
	delete this->mainMenu;
}