#include "UpLoader.h"

UpLoader::UpLoader(Packet* pack)
{
	this->pack = pack;
	this->socket = new UdpSocket;
}

UpLoader::~UpLoader()
{
}

void UpLoader::send()
{
}
