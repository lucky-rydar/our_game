#include "GameMenu.h"

GameMenu::GameMenu(RenderWindow* win, Event* eve)
{	
	gameScene = new GameScene(win, eve);
	pauseMenu = new PauseMenu(win, eve);
	window = win;
	this->eve = eve;
}

GameMenu::~GameMenu()
{
	delete gameScene;
	delete pauseMenu;
}

void GameMenu::draw()
{

}

void GameMenu::update(Client* client)
{
}
