#pragma once
#include "../Client.h"
#include<SFML/Graphics.hpp>
#include "GameMenu/GameInterface.h"
#include "GameMenu/GameScene.h"
#include "GameMenu/PauseMenu.h"
#include "CurrentIMMenu.h"

using namespace sf;

class GameMenu
{
public:
	GameMenu(RenderWindow *win, Event *eve);
	~GameMenu();

	void draw();
	void update(Client *client);
private:
	GameInterface* gameInterface;
	GameScene* gameScene;
	PauseMenu* pauseMenu;
	RenderWindow* window;
	Event* eve;
};

