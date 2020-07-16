#pragma once
#pragma warning(disable: 4244)
#include <SFML/Graphics.hpp>
#include "InterfaceElements/Button.h"
#include "InterfaceElements/SpriteButton.h"
#include "InterfaceElements/Label.h"
#include "InterfaceElements/LineEdit.h"
#include "InterfaceElements/CheckBox.h"
#include "InterfaceElements/SpriteLineEdit.h"
#include "../Client.h"
#include "CurrentIMMenu.h"
#include "CurrentMainMenu.h"
#include <iostream>
#include "MusicManager.h"

using namespace sf;
using namespace std;

class MainMenu
{
public:
	MainMenu(sf::Vector2f WindowSize, Event* eve, RenderWindow* win, CurrentIMMenu *curMenu);
	~MainMenu();

	void draw();
	void update(Client *client);
private:
	//Button* button;
	SpriteButton* PlayButton;
	SpriteButton* SettingsButton;
	SpriteButton* ExitButton;
	SpriteButton* SettingsBack;
	SpriteButton* SettingsGeneral;
	SpriteButton* SettingsGraphics;
	SpriteButton* SettingsSounds;

	SpriteLineEdit* UsrName;
	CheckBox* Vsync;
	Label* Vsynclabel;
	CheckBox* FullScreen;
	Label* FullScreenlabel;
	
	MusicManager musicManager;

	Label* label;
	LineEdit*  lineEdit;
	Font *font;
	CurrentMainMenu* curMMenu;

	Event *eve; // do not delete them in 
	RenderWindow *window; // destructor
};

