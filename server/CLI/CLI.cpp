#include "CLI.h"



CLI::CLI(string start_line)
{
	this->start_line = start_line;
	this->config = new Config;
	this->parser = new Parser;
}

CLI::~CLI()
{
	delete config;
	delete parser;
}

void CLI::get_line()
{
	cout << start_line;
	getline(cin, cur_line);

	//TODO: calling parser to parse data and call the func we need
	parser->parse(cur_line);
}


