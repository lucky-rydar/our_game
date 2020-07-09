#include "Config.h"

Config::Config()
{
	this->params = new map<string, string>();
	this->configFile = fstream();
}

Config::~Config()
{
	delete this->params;
}

void Config::loadConfig(string fileName)
{
	string key;
	string value;

	configFile.open(fileName);

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
