#include "InterfaceManager.h"

InterfaceManager::InterfaceManager()
{
	gameMenu = new GameMenu;
	mainMenu = new MainMenu;

	window = new RenderWindow(VideoMode(1280, 720), "our_game");
}

InterfaceManager::~InterfaceManager()
{
	delete this->gameMenu;
	delete this->mainMenu;
	delete this->window;
}

void InterfaceManager::update(Client* client)
{
	// TO DO here call update func of gameMenu and mainMenu 
}

void InterfaceManager::draw()
{
	if (window->isOpen())
	{
		Event eve;
		while (window->pollEvent(eve))
		{
			if (eve.type == Event::Closed)
				window->close();
		}

		window->clear(Color(0, 0, 0, 0));

		// TO DO drawing gamMenu and mainMenu

		window->display();
	}
}
