#include "DownLoader.h"

DownLoader::DownLoader(Config* cfg)
{
	this->cfg = cfg;

	string port_string = cfg->getParam("port");
	port = (unsigned short)stoi(port_string);
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
