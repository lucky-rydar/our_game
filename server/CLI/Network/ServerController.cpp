#include "ServerController.h"

ServerController::ServerController()
{
	this->config = new Config();
	// TODO: load all config

	this->network = new Network(config);
}

ServerController::~ServerController()
{
	delete config;
	delete network;
}

void ServerController::start()
{
}

void ServerController::stop()
{
}
