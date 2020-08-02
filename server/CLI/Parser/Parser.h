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

	vector<string> parse(string line);


private:
	string line;
};

