#include "MapData.h"

MapData::MapData(vector<vector<short>> data)
{
	map = data;
}

void MapData::setSize(int size)
{
	this->size = size;
}

vector<vector<short>> MapData::getMap()
{
	return this->map;
}

void MapData::generateMap()
{
}
