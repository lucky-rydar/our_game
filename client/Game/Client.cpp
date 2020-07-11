#include "Client.h"

Client::Client(Config* cfg)
{
	this->packToReceive = new Packet();
	this->packToSend = new Packet();
	
	this->downLoader = new DownLoader(packToReceive);
	this->upLoader = new UpLoader(packToSend);
	this->config = cfg;
}

Client::~Client()
{
	delete this->downLoader;
	delete this->upLoader;
}

void Client::update()
{
	downLoader->receive();

	upLoader->send();
}
