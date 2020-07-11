#include "Game.h"

Game::Game()
{
	this->cfg = new Config;
	this->client = new Client(cfg);
	this->imanager = new InterfaceManager(client);
}

Game::~Game()
{
	delete this->client;
	delete this->cfg;
	delete this->imanager;
}

void Game::exec()
{
	while (true)
	{
		imanager->update();
		imanager->draw();
	}
}
