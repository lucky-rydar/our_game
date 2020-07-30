#include "ServerController.h"

ServerController::ServerController()
{
	this->config = new Config();
	this->network = new Network(config);
}

ServerController::~ServerController()
{
	delete config;
	delete network;
}
