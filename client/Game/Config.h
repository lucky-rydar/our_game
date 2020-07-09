#pragma once
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Config
{
public:
	Config(string fileName = "config.cfg");
	~Config();
	void loadConfig();
	string getParam(string key);

private:
	fstream configFile;
	map<string, string> *params;
};

