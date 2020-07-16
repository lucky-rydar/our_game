#pragma once
#include <vector>

using namespace std;

class MapData
{
public:
	MapData(vector<vector<short>> data);
	
	void setSize(int size);
	vector<vector<short>> getMap();
	void generateMap(); // TODO

private:
	vector<vector<short>> map;
	int size;
};

