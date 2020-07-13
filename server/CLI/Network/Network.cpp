#include "Network.h"

Network::Network()
{
	db = new Database;
	upLoader = new UpLoader;
	downLoader = new DownLoader;
}

Network::~Network()
{
	delete db;
	delete upLoader;
	delete downLoader;
}
