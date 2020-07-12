#include "Client.h"

Client::Client(Config* cfg)
{	
	this->config = cfg;
	this->downLoader = new DownLoader(cfg);
	this->upLoader = new UpLoader(cfg);
	
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

void Client::addData(Instruction instruction)
{
	
}
