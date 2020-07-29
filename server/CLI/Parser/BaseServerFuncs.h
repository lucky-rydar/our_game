#pragma once
#include <map>
#include <regex>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

class BaseServerFuncs
{
public:
	BaseServerFuncs();
	void call(string func, string args);

private:
	map<string, void(*)(string)> functions;

	static void echo(string);
	
};

