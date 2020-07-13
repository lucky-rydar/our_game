#pragma once
#include <SFML/Network.hpp>
#include "../Parser/Config.h"
#include <map>

using namespace sf;
using namespace std;

class DownLoader
{
private:
	DownLoader(UdpSocket* socket, Config* cfg);
	~DownLoader();

	void receive();
public:
	void toMap();
	
	Packet pack;
	map<string, string> map_data;
	UdpSocket* socket;
	Config *config;
};

