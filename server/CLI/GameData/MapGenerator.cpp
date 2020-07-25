#include "MapGenerator.h"

MapGenerator::MapGenerator()
{
    srand(time(0));

    this->CHUNK_X = 0;
    this->CHUNK_Z = 0;
}

vector<vector<float>> MapGenerator::gen(int size, int base_height)
{
    if (size % 2 == 0)
        size++;
    base_height *= -1;

    vector<vector<float>> map;

    map.resize(size);
    for (size_t i = 0; i < map.size(); i++)
    {
        map[i].resize(size);
    }

    this->CHUNK_X = size;
    this->CHUNK_Z = size;

    
    array_map = new int* [size];
    for (int i = 0; i < size; i++)
    {
        array_map[i] = new int[size];
    }

    array_map[0][0] = random(base_height);
    array_map[0][size - 1] = random(base_height);
    array_map[size - 1][size - 1] = random(base_height);
    array_map[size - 1][0] = random(base_height);

    diamondSquare(array_map, size);
    normalize(base_height, size);
     
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            map[i][j] = array_map[i][j];
        }

    }

    for (int i = 0; i < size; i++)
    {
        delete[] array_map[i];
    }
    delete[] array_map;


    return map;
}

void MapGenerator::diamondSquare(int** Array, int size)
{
    int half = size / 2;
    if (half < 1)
        return;
    //square steps
    for (int z = half; z < CHUNK_Z; z += size)
        for (int x = half; x < CHUNK_X; x += size)
            squareStep(Array, x % CHUNK_X, z % CHUNK_Z, half);
    // diamond steps
    int col = 0;
    for (int x = 0; x < CHUNK_X; x += half)
    {
        col++;
        //If this is an odd column.
        if (col % 2 == 1)
            for (int z = half; z < CHUNK_Z; z += size)
                diamondStep(Array, x % CHUNK_X, z % CHUNK_Z, half);
        else
            for (int z = 0; z < CHUNK_Z; z += size)
                diamondStep(Array, x % CHUNK_X, z % CHUNK_Z, half);
    }
    diamondSquare(Array, size / 2);
}

void MapGenerator::squareStep(int** Array, int x, int z, int reach)
{
    int count = 0;
    float avg = 0.0f;
    if (x - reach >= 0 && z - reach >= 0)
    {
        avg += Array[x - reach][z - reach];
        count++;
    }
    if (x - reach >= 0 && z + reach < CHUNK_Z)
    {
        avg += Array[x - reach][z + reach];
        count++;
    }
    if (x + reach < CHUNK_X && z - reach >= 0)
    {
        avg += Array[x + reach][z - reach];
        count++;
    }
    if (x + reach < CHUNK_X && z + reach < CHUNK_Z)
    {
        avg += Array[x + reach][z + reach];
        count++;
    }
    avg += random(reach);
    avg /= count;
    Array[x][z] = round(avg);
}

void MapGenerator::diamondStep(int** Array, int x, int z, int reach)
{
    int count = 0;
    float avg = 0.0f;
    if (x - reach >= 0)
    {
        avg += Array[x - reach][z];
        count++;
    }
    if (x + reach < CHUNK_X)
    {
        avg += Array[x + reach][z];
        count++;
    }
    if (z - reach >= 0)
    {
        avg += Array[x][z - reach];
        count++;
    }
    if (z + reach < CHUNK_Z)
    {
        avg += Array[x][z + reach];
        count++;
    }
    avg += random(reach);
    avg /= count;
    Array[x][z] = (int)avg;
}

void MapGenerator::normalize(int range, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (array_map[i][j] > range * (-1))
                array_map[i][j] = range * (-1);
            else if (array_map[i][j] < range)
                array_map[i][j] = range;
        }
    }
}

float MapGenerator::random(int range)
{
    return (rand() % (range * 2)) - range;
}