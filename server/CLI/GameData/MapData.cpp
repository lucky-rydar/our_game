#include "MapData.h"

MapData::MapData(vector<vector<float>> data)
{
	map = data;
}

void MapData::setSize(int size)
{
	this->size = size;
}

void MapData::generateMap()
{
	MapGenerator map_gen;
	
	this->map = map_gen.gen(9);
}
