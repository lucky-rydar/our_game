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
}


