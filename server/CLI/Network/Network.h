#pragma once
#include "Database.h"
#include "DownLoader.h"
#include "UpLoader.h"

class Network
{
public:
	Network();
	~Network();


private:
	Database* db;
	DownLoader *downLoader;
	UpLoader* upLoader;

};

