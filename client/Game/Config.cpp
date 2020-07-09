#include "Config.h"

Config::Config(string fileName)
{
	this->params = new map<string, string>();
	this->configFile = fstream();

	configFile.open(fileName);
	if (!configFile.is_open())
	{
		ofstream newFile("config.cfg");
		return;
	}
}

Config::~Config()
{
	delete this->params;
}

void Config::loadConfig()
{
	string key;
	string value;

	while (!configFile.eof())
	{
		configFile >> key >> value;
		params->at(key) = value;
	}
}

string Config::getParam(string key)
{
	return params->at(key);
}
