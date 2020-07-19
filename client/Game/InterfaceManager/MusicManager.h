#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <thread>
#include <iostream>
#include <filesystem>

using namespace sf;
using namespace std;

class MusicManager 
{
public:
	MusicManager(string path = "Resources\\Music\\");
	~MusicManager();

	void setVolume(float volume);
	void play();
	void stop();
	
	void playing();
private:
	void countFilesIn(string path);

	bool canPlay;
	unsigned int numOfFiles;
	Thread *th;
	Music track;
	string path;
};

