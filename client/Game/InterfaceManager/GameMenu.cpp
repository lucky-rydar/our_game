#include "GameMenu.h"

GameMenu::GameMenu(RenderWindow* win)
{
	gameInterface = new GameInterface;
	gameScene = new GameScene;
	pauseMenu = new PauseMenu;
	window = win;
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
