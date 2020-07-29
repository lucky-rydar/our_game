#pragma once
#include <regex>
#include <string>
#include <iostream>

using namespace std;

class Parser
{
public:
	Parser();
	~Parser();

	void parse(string line);


private:
	string line;
};

