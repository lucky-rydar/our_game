#include "Parser.h"

Parser::Parser()
{
	
}

Parser::~Parser()
{
	
}

void Parser::parse(string line)
{
	regex templ("(?:(\\w+)\\s)(.+)\\s?");
	cmatch found;

	if (!regex_match(line.c_str(), found, templ))
	{
		cout << "Error syntax/command" << endl;
		return;
	}


}


