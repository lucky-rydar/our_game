#include "Parser.h"

Parser::Parser()
{
	
}

Parser::~Parser()
{
	
}

vector<string> Parser::parse(string line)
{
	regex templ("(?:(\\w+)\\s?)(?:(.+)\\s*)?");
	cmatch found;
	vector<string> result;

	while (regex_match(line.c_str(), found, templ))
	{
		result.push_back(found[1]);
		if(line.size() > 2)
			line = found[2];
	}
	
	return result;
}


