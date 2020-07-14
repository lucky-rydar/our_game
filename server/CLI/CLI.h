#pragma once
#include <iostream>
#include <string>
#include "Parser/Parser.h"
#include "Parser/Config.h"
#include "Network/Network.h"

using namespace std;

class CLI // Command Line Interface class
{
public:
	CLI(string start_line = "-->");
	~CLI();
	void get_line();

	
private:
	string cur_line;
	string start_line;

	Config* config;
	Parser* parser;
	Network* network;
};

