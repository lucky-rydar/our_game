#include "InterfaceManager.h"

InterfaceManager::InterfaceManager()
{
	Vector2f winSize(1280, 720);

	window = new RenderWindow(VideoMode(winSize.x, winSize.y), "our_game");
	gameMenu = new GameMenu;
	mainMenu = new MainMenu(winSize);

	
}

InterfaceManager::~InterfaceManager()
{
	delete this->gameMenu;
	delete this->mainMenu;
	delete this->window;
}

void InterfaceManager::update(Client* client)
{
	// TO DO checking current window from statement variable
	mainMenu->update(client);
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

		// TO DO checking current window from statement variable
		mainMenu->draw(window);

		window->display();
	}
}
