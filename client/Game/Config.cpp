#include "Config.h"

Config::Config(string fileName)
{
	
	this->configFile = fstream();

	configFile.open(fileName);
	if (!configFile.is_open())
	{
		ofstream newFile("config.cfg");
		return;
	}
	loadConfig();
}

Config::~Config()
{
	
}

void Config::loadConfig()
{
	string key;
	string value;

	while (!configFile.eof())
	{
		configFile >> key >> value;
		params[key] = value;
	}
}

string Config::getParam(string key)
{
	return params[key];
}
