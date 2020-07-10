#pragma once
#include "../Client.h"
#include<SFML/Graphics.hpp>
#include "GameMenu/GameInterface.h"
#include "GameMenu/GameScene.h"
#include "GameMenu/PauseMenu.h"

using namespace sf;

class GameMenu
{
public:
	GameMenu();
	~GameMenu();

	void draw(RenderWindow *win);
	void update(Client *client);
private:
	GameInterface* gameInterface;
	GameScene* gameScene;
	PauseMenu* pauseMenu;
};

