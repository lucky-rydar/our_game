#pragma once
#include <SFML/Network.hpp>
#include "../Config.h"

using namespace sf;

class DownLoader
{
public:
	DownLoader(Config* cfg);
	~DownLoader();
	
	void receive();

	void toMap();
private:
	Packet pack;
	map<string, string> map_data;
	UdpSocket socket;

	Config* cfg;
	IpAddress address;
	unsigned short port;
};

