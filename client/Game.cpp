#include "Game.h"

Game::Game()
{
	this->client = new Client;
	this->cfg = new Config;
	this->imanager = new InterfaceManager;
}

Game::~Game()
{
	delete this->client;
	delete this->cfg;
	delete this->imanager;
}