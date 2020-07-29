#include "Parser.h"

Parser::Parser()
{
	this->funcs = new BaseServerFuncs();
}

Parser::~Parser()
{
	delete funcs;
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

	funcs->call(found[1], found[2]);

}


