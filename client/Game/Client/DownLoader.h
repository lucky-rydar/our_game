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

	map<string, string> map_data;
private:
	void toMap();
	
	Packet pack;
	UdpSocket socket;

	Config* cfg;
	IpAddress address;
	unsigned short port;
};

