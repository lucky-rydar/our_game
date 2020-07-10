#pragma once
#include "../Client.h"
#include<SFML/Graphics.hpp>

using namespace sf;

class GameMenu
{
public:
	GameMenu();
	~GameMenu();

	void draw(RenderWindow *win);
	void update(Client *client);
private:

};

