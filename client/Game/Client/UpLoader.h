#pragma once
#include <SFML/Network.hpp>
#include <map>

using namespace sf;
using namespace std;

class UpLoader
{
public:
	UpLoader(Packet* pack);
	~UpLoader();

	void send();
private:
	Packet* pack;
	UdpSocket* socket;
};

