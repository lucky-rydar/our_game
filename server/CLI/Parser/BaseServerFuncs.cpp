#include "BaseServerFuncs.h"

BaseServerFuncs::BaseServerFuncs()
{
	this->functions["echo"] = &BaseServerFuncs::echo;
}

void BaseServerFuncs::call(string func, string args)
{
	if (functions.find(func) == functions.end())
	{
		cout << "Error" << endl;
	}
	else
	{
		functions.at(func)(args);
	}
}

void BaseServerFuncs::echo(string str)
{
	cout << str << endl;
} 
