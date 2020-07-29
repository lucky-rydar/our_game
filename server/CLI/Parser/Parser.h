#pragma once
#include <regex>
#include <string>
#include <iostream>
#include "BaseServerFuncs.h"

using namespace std;

class Parser
{
public:
	Parser();
	~Parser();

	void parse(string line);


private:
	string line;
	BaseServerFuncs *funcs;
};

