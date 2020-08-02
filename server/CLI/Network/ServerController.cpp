#include "ServerController.h"

ServerController::ServerController(Config* cfg)
{
	this->config = cfg;
	// TODO: load all config

	this->network = new Network(cfg);
}

ServerController::~ServerController()
{
	delete network;
}

void ServerController::start()
{
}

void ServerController::stop()
{
}
