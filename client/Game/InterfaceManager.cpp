#include "InterfaceManager.h"

InterfaceManager::InterfaceManager(Client *client)
{
	Vector2f winSize(1280, 720);
	eve = new Event;
	window = new RenderWindow(VideoMode(winSize.x, winSize.y), "our_game");
	gameMenu = new GameMenu(window);
	mainMenu = new MainMenu(winSize, eve, window);
	curMenu = CurrentIMMenu::Main;
	this->client = client;
}

InterfaceManager::~InterfaceManager()
{
	delete this->gameMenu;
	delete this->mainMenu;
	delete this->window;
	delete this->eve;
	delete this->client;
}

void InterfaceManager::update()
{
	if (curMenu == CurrentIMMenu::Main)
		mainMenu->update(client, &curMenu);
	else if (curMenu == CurrentIMMenu::Game)
		gameMenu->update(client, &curMenu);
}

void InterfaceManager::draw()
{
	if (window->isOpen())
	{
		
		while (window->pollEvent(*eve))
		{
			if (eve->type == Event::Closed)
				window->close();
		}

		window->clear(Color(0, 0, 0, 0));

		if (curMenu == CurrentIMMenu::Main)
			mainMenu->draw();
		else if (curMenu == CurrentIMMenu::Game)
			gameMenu->draw();

		window->display();
	}
}
