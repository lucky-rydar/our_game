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
	GameMenu(RenderWindow *win);
	~GameMenu();

	void draw();
	void update(Client *client, CurrentIMMenu* curMenu);
private:
	GameInterface* gameInterface;
	GameScene* gameScene;
	PauseMenu* pauseMenu;
	RenderWindow* window;
};

