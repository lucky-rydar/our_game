#pragma once
#include <vector>
#include "MapGenerator.h"

using namespace std;

class MapData
{
public:
	MapData(vector<vector<float>> data);
	
	void setSize(int size);
	void generateMap(); // TODO

private:
	vector<vector<float>> map;
	int size;
};

