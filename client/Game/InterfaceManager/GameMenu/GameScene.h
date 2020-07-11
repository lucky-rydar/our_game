#pragma once
#include <SFML/Graphics.hpp>
#include "../../Client.h"

using namespace sf;

class GameScene
{
public:
	GameScene(RenderWindow* win, Event* eve);
	~GameScene();

	void draw();
	void update(Client* client);
private:
	RenderWindow* window;
	Event* eve;

};

