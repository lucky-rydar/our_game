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

	this->numOfFiles = (unsigned int)std::count_if(
		begin(dirIter),
		end(dirIter),
		[](auto& entry) { return entry.is_regular_file(); }
	);
}

void MusicManager::playing()
{
	srand((unsigned int)time(0));
	int current = 0;
	int duration;
	unsigned int num_of_cycles;
	while (canPlay)
	{
		current = rand() % this->numOfFiles + 1;
		track.openFromFile(path + to_string(current) + ".ogg");
		
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
