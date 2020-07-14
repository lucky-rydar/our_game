#include "MusicManager.h"

MusicManager::MusicManager(string path) 
{
	this->path = path;
}

void MusicManager::setVolume(float volume) // 0 is min and 100 is max
{
	track.setVolume(volume);
}

void MusicManager::startPlaying() // Use this func in Thread and to stop it use terminate
{
	while (true)
	{
		for (int i = 0; track.openFromFile(path + to_string(i) + ".ogg"); i++)
		{
			track.play();
			this_thread::sleep_for(chrono::milliseconds(track.getDuration().asMilliseconds()));
		}
	}	
}