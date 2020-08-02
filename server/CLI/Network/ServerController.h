#pragma once
#include <iostream>
#include "Network.h"
#include "../Parser/Config.h"

using namespace std;

class ServerController
{
public:
	ServerController(Config* cfg);
	~ServerController();

	
	void server(string func);

private:
	void start();
	void stop();

	Config* config;
	Network* network;
};

