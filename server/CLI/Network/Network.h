#pragma once
#include "Database.h"
#include "DownLoader.h"
#include "UpLoader.h"

class Network
{
public:
	Network(Config* cfg);
	~Network();


private:
	Database* db;
	DownLoader *downLoader;
	UpLoader* upLoader;

	Config* config;
	UdpSocket* socket;
};

