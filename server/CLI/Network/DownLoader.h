#pragma once
#include <SFML/Network.hpp>
#include "../Parser/Config.h"
#include <map>

using namespace sf;
using namespace std;

class DownLoader
{
public:
	DownLoader(UdpSocket* socket, Config* cfg);

	void receive();
private:
	void toMap();
	
	Packet pack;
	map<string, string> map_data;
	UdpSocket* socket;
	Config *config;
};

