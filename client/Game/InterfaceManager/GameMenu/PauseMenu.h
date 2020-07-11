#pragma once
#include <SFML/Graphics.hpp>
#include "../../Client.h"

using namespace sf;
using namespace std;

class PauseMenu
{
public:
	PauseMenu(RenderWindow* win, Event* eve);
	~PauseMenu();

	void draw();
	void update(Client* client);

private:
	RenderWindow* window;
	Event *eve;
};

