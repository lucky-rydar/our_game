#include "DownLoader.h"

DownLoader::DownLoader(Packet* pack)
{
	this->pack = pack;
	this->socket = new UdpSocket;
}

DownLoader::~DownLoader()
{
}

void DownLoader::receive()
{
}
