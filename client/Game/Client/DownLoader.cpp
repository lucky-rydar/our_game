#include "DownLoader.h"

DownLoader::DownLoader(Config* cfg)
{
	this->cfg = cfg;

	port = (unsigned short)stoi(cfg->getParam("port"));
}

DownLoader::~DownLoader()
{
}

void DownLoader::receive()
{
	socket.receive(this->pack, address, port);
	toMap();
}

void DownLoader::toMap()
{
	string key;
	string value;
	
	while (!pack.endOfPacket())
	{
		pack >> key >> value;
		this->map_data[key] = value;
	}
}
