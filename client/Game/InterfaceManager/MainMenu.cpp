#include "MainMenu.h"

MainMenu::MainMenu(sf::Vector2f WindowSize)
{
	sf::Font font;
	font.loadFromFile(std::string("C:\\Windows\\Fonts\\Arial"));

	this->button = new Button(font, sf::String("Start"), WindowSize.x / 2, WindowSize.y / 2, 120.f, 30.f);
	this->label = new Label(font, sf::String("our_game"), WindowSize.x / 2, WindowSize.y);
	this->lineEdit = new LineEdit(font, sf::String("Username"), WindowSize.x / 2, WindowSize.y / 2 + 20, 120.f, 30.f);
}

MainMenu::~MainMenu()
{
	delete this->button;
	delete this->label;
	delete this->lineEdit;
}

void MainMenu::draw(RenderWindow* win)
{
	this->button->draw(*win);
	this->label->draw(*win);
	this->lineEdit->draw(*win);
}

void MainMenu::update(Client* client, CurrentIMMenu& curMenu)
{
}

