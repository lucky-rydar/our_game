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

void ServerController::server(string func)
{
	if (func == "start")
		start();
	else if (func == "stop")
		stop();

}

void ServerController::start()
{
}

void ServerController::stop()
{
}
