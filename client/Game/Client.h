#pragma once
#include <SFML/Network.hpp>
#include "Client/DataBase.h"
#include "Client/DownLoader.h"
#include "Client/UpLoader.h"

class Client
{
public:
	Client();

	~Client();
private:

	DataBase *db;

	DownLoader *downLoader;

	UpLoader *upLoader;
};

