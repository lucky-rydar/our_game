#pragma once
#include "Network.h"
#include "../Parser/Config.h"

class ServerController
{
public:
	ServerController();
	~ServerController();

	void start(); 
	void stop();


private:
	Config* config;
	Network* network;
};

