#include "MusicManager.h"

MusicManager::MusicManager(string path) 
{
	this->path = path;
	countFilesIn(path);
}

void MusicManager::setVolume(float volume) // 0 is min and 100 is max
{
	track.setVolume(volume);
}

void MusicManager::startPlaying() // Use this func in Thread and to stop it use terminate
{
	srand(time(0));
	int current = 0;
	while (true)
	{
		current = rand() % this->numOfFiles + 1;
		track.openFromFile(path + to_string(current) + ".ogg");
		track.play();
		this_thread::sleep_for(chrono::milliseconds(track.getDuration().asMilliseconds()));
	}	
}

void MusicManager::countFilesIn(string path)
{
	InputSoundFile file;
	string format = ".ogg";
	int tempCount = 0;

	for (int i = 1; file.openFromFile(path + to_string(i) + format); i++)
	{
		tempCount++;
	}

	this->numOfFiles = tempCount;
}
