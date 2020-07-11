#include "GameMenu.h"

GameMenu::GameMenu(RenderWindow* win, Event* eve)
{
	gameInterface = new GameInterface;
	gameScene = new GameScene;
	pauseMenu = new PauseMenu;
	window = win;
	this->eve = eve;
}

GameMenu::~GameMenu()
{
	delete gameInterface;
	delete gameScene;
	delete pauseMenu;
}

void GameMenu::draw()
{
}

void GameMenu::update(Client* client)
{
}
