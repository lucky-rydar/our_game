#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <thread>

using namespace sf;
using namespace std;

class MusicManager 
{
public:
	MusicManager(string path = "Resources\\Music\\");

	void setVolume(float volume);
	void startPlaying();
private:
	void countFilesIn(string path);

	int numOfFiles;
	Music track;
	string path;
};

