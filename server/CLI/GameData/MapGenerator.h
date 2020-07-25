#pragma once
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class MapGenerator
{
public:
	MapGenerator();

	vector<vector<float>> gen(int size, int base_height = 2);
	static float random(int range);
private:
	void diamondSquare(int** Array, int size);
	void squareStep(int** Array, int x, int z, int reach);
	void diamondStep(int** Array, int x, int z, int reach);

	void normalize(int range, int size);

	int CHUNK_X;
	int CHUNK_Z;

	int** array_map;
};

