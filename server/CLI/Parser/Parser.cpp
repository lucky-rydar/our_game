#include "Parser.h"

Parser::Parser()
{
	
}

Parser::~Parser()
{
	
}

vector<string> Parser::parse(string line)
{
	regex templ("(?:(\\w+)\\s)(.+)\\s?");
	cmatch found;

	if (!regex_match(line.c_str(), found, templ))
	{
		cout << "Error syntax/command" << endl;
		return vector<string>();
	}

	vector<string> result;
	for (size_t i = 1; i < found.size(); i++)
	{
		result.push_back(found[i]);
	}
	return result;
}


