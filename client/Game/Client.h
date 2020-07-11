#pragma once
#include <SFML/Network.hpp>
#include "Client/DownLoader.h"
#include "Client/UpLoader.h"
#include "Config.h"
#include <map>

using namespace sf;
using namespace std;

class Client
{
public:
	Client(Config* cfg);
	~Client();

	void update();
private:
	DownLoader *downLoader;
	UpLoader *upLoader;
	Config *config;
	Packet* packToSend;
	Packet* packToReceive;
	
	
};

