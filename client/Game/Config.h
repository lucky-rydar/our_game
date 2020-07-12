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
	
	string getParam(string key);

private:
	void loadConfig();

	fstream configFile;
	map<string, string> params;
};

