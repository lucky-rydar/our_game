#pragma once
#include "Network.h"
#include "../Parser/Config.h"

class ServerController
{
public:
	ServerController();
	~ServerController();

private:
	Config* config;
	Network* network;
};

