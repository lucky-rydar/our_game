#include "GameMenu.h"

GameMenu::GameMenu()
{
	gameInterface = new GameInterface;
	gameScene = new GameScene;
	pauseMenu = new PauseMenu;
}

GameMenu::~GameMenu()
{
	delete gameInterface;
	delete gameScene;
	delete pauseMenu;
}

void GameMenu::draw(RenderWindow* win)
{
}

void GameMenu::update(Client* client)
{
}
