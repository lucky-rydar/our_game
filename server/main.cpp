#include <iostream>
#include "CLI/CLI.h"

using namespace std;

int main(int argc, char* argv[])
{
	CLI cli;
	while (true)
	{
		cli.get_line();
	}
}