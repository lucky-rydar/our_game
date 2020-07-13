#pragma once
#include <regex>
#include <string>
#include "LineType.h"

using namespace std;

class Parser
{
public:
	Parser();
	~Parser();

	LineType typeOfLine();


private:
	string line;
	LineType type;
};

