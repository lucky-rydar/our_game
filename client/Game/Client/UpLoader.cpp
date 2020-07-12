#include "UpLoader.h"

UpLoader::UpLoader(Config* cfg)
{
	this->cfg = cfg;

	socket.bind(stoi(cfg->getParam("port")));
}

UpLoader::~UpLoader()
{
}

void UpLoader::send()
{
	toPacket();
	socket.send(pack, IpAddress(cfg->getParam("ip")), stoi(cfg->getParam("port")));
}

void UpLoader::toPacket()
{
	for (int i = 0; i < this->vector_data.size(); i++)
	{
		this->pack << vector_data[i].key << vector_data[i].value;
	}
}
