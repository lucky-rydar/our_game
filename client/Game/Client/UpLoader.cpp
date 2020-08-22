#include "UpLoader.h"

UpLoader::UpLoader(Config* cfg)
{
	this->cfg = cfg;

	socket.bind(stoi(cfg->getParam("port")));
}

UpLoader::~UpLoader()
{
}

void UpLoader::send()
{
	socket.send(pack, IpAddress(cfg->getParam("ip")), stoi(cfg->getParam("port")));
	pack.clear();
}

void UpLoader::addInstruction(Instruction instruction)
{
	pack << instruction.key << instruction.value;
}
