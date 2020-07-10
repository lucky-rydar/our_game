#include "Game.h"

Game::Game()
{
	this->client = new Client;
	this->cfg = new Config;
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
