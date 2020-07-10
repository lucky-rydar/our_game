#include "MainMenu.h"

MainMenu::MainMenu(sf::Vector2f WindowSize)
{
	font = new Font;
	font->loadFromFile(std::string("Resources\\Fonts\\lilita_one_rus.ttf"));

	this->button = new Button(font, sf::String("Start"), WindowSize.x / 2, WindowSize.y / 2, 150.f, 30.f, sf::Color::Red);
	this->label = new Label(font, sf::String("our_game"), WindowSize.x / 2, WindowSize.y, sf::Color::White);
	this->lineEdit = new LineEdit(font, sf::String("Username"), WindowSize.x / 2, WindowSize.y / 2 - 100, 300.f, 60.f, 150.f, 30.f, sf::Color::Blue,
		sf::Color::Black, sf::Color::White);
}

MainMenu::~MainMenu()
{
	delete this->button;
	delete this->label;
	delete this->lineEdit;
}

void MainMenu::draw(RenderWindow* win)
{
	this->button->draw(win);
	this->label->draw(win);
	this->lineEdit->draw(win);
}

void MainMenu::update(Client* client, CurrentIMMenu& curMenu)
{
}

