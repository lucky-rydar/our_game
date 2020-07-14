#include "Network.h"

Network::Network(Config* cfg)
{
	config = new Config;
	socket = new UdpSocket;
	db = new Database;
	upLoader = new UpLoader;
	downLoader = new DownLoader(socket, config);
}

Network::~Network()
{
	delete db;
	delete upLoader;
	delete downLoader;
}
