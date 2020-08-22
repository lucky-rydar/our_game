#pragma once
#include "Instruction.h"
#include "../Config.h"
#include <SFML/Network.hpp>
#include <map>

using namespace sf;
using namespace std;

class UpLoader
{
public:
	UpLoader(Config *cfg);
	~UpLoader();

	void send();
	void addInstruction(Instruction instruction);
	
private:
	
	Config* cfg;
	
	Packet pack;
	UdpSocket socket;
};

