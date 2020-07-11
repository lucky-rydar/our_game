#pragma once
#include <SFML/Network.hpp>

using namespace sf;

class DownLoader
{
public:
	DownLoader(Packet* pack);
	~DownLoader();
	
	void receive();
private:
	Packet* pack;
	UdpSocket *socket;
};

