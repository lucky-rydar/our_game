#include "DownLoader.h"

DownLoader::DownLoader(UdpSocket* socket, Config* cfg)
{
	this->socket = socket;
	this->config = cfg;
}

DownLoader::~DownLoader()
{
	delete socket;
}

void DownLoader::receive()
{

}

void DownLoader::toMap()
{

}