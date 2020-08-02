#include "CLI.h"



CLI::CLI(string start_line)
{
	this->config = new Config();
	this->start_line = start_line;
	this->parser = new Parser;
	this->server_controller = new ServerController(config);
}

CLI::~CLI()
{
	delete parser;
	delete server_controller;
}

void CLI::get_line()
{
	cout << start_line;
	getline(cin, cur_line);

	//TODO: calling parser to parse data and call the func we need
	parser->parse(cur_line);
}


