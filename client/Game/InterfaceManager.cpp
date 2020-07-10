#include "InterfaceManager.h"

InterfaceManager::InterfaceManager()
{
	Vector2f winSize(1280, 720);

	window = new RenderWindow(VideoMode(winSize.x, winSize.y), "our_game");
	gameMenu = new GameMenu;
	mainMenu = new MainMenu(winSize);

	curMenu = CurrentIMMenu::Main;
}

InterfaceManager::~InterfaceManager()
{
	delete this->gameMenu;
	delete this->mainMenu;
	delete this->window;
}

void InterfaceManager::update(Client* client)
{
	if (curMenu == CurrentIMMenu::Main)
		mainMenu->update(client, curMenu);
	else if (curMenu == CurrentIMMenu::Game)
		gameMenu->update(client, curMenu);
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

		if (curMenu == CurrentIMMenu::Main)
			mainMenu->draw(window);
		else if (curMenu == CurrentIMMenu::Game)
			gameMenu->draw(window);

		window->display();
	}
}
