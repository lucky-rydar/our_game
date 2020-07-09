#pragma once
#include <SFML/Graphics.hpp>
#include "InterfaceElements/Button.h"
#include "InterfaceElements/Label.h"
#include "InterfaceElements/LineEdit.h"

class MainMenu
{
public:
	MainMenu(sf::Vector2f WindowSize);

	~MainMenu();
private:
	Button* button;
	Label* label;
	LineEdit*  lineEdit;
};

