#include "Client.h"

Client::Client()
{
	this->db = new DataBase;
	this->downLoader = new DownLoader;
	this->upLoader = new UpLoader;
}

Client::~Client()
{
	delete this->db;
	delete this->downLoader;
	delete this->upLoader;
}