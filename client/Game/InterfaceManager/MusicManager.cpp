#include "MusicManager.h"

MusicManager::MusicManager(string path) 
{
	this->canPlay = true;
	th = new Thread(&MusicManager::playing, this);
	this->path = path;
	countFilesIn(path);
}

MusicManager::~MusicManager()
{
	delete th;
}

void MusicManager::setVolume(float volume) // 0 is min and 100 is max
{
	track.setVolume(volume);
}

void MusicManager::play()
{
	canPlay = true;
	th->launch();
}

void MusicManager::stop()
{
	canPlay = false;
	th->wait();
	return;
}

void MusicManager::countFilesIn(string path)
{
	auto dirIter = std::filesystem::directory_iterator(path);

	int counter = 0;
	for (size_t i = 0; !dirIter._At_end(); i++)
	{
		if (dirIter->is_regular_file() && dirIter->path().extension() == ".ogg")
		{
			this->list_of_tracks.push_back(dirIter->path().filename().string());
			counter++;
		}
		
		dirIter++;
	}
	this->numOfFiles = counter;	
}

void MusicManager::playing()
{
	srand((unsigned int)time(0));
	int current = 0;
	int duration;
	unsigned int num_of_cycles;
	while (canPlay)
	{
		current = rand() % this->numOfFiles;
		track.openFromFile(path + list_of_tracks[current]);
		
		duration = track.getDuration().asMilliseconds();
		num_of_cycles = duration / 20;
		
		track.play();
		for (unsigned int i = 0; i < num_of_cycles && canPlay; i++)
		{
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		
	}
	track.stop();
	return;
}
