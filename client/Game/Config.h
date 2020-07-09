#pragma once
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Config
{
public:
	Config();
	~Config();
	void loadConfig(string fileName = "config.cfg");
	string getParam(string key);

private:
	fstream configFile;
	map<string, string> *params;
};

