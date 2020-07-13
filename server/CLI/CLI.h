#pragma once
#include <string>
#include <regex>
#include "Parser/Parser.h"
#include "Parser/Config.h"

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
};

