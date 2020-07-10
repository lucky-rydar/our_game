#include "MainMenu.h"

MainMenu::MainMenu(sf::Vector2f WindowSize, Event *eve, RenderWindow* win)
{
	this->window = win;
	
	font = new Font;
	font->loadFromFile(std::string("Resources\\Fonts\\lilita_one_rus.ttf"));

	this->button = new Button(font, sf::String("Start"), WindowSize.x / 2, WindowSize.y / 2, 150.f, 30.f, sf::Color::Red);
	this->label = new Label(font, sf::String("our_game"), WindowSize.x / 2, WindowSize.y, sf::Color::White);
	this->lineEdit = new LineEdit(font, sf::String("Username"), WindowSize.x / 2, WindowSize.y / 2 - 100, 300.f, 60.f, 150.f, 30.f, sf::Color::Blue,
		sf::Color::Black, sf::Color::White);

	this->eve = eve;
}

MainMenu::~MainMenu()
{
	delete this->button;
	delete this->label;
	delete this->lineEdit;
}

void MainMenu::draw()
{
	this->button->draw(window);
	this->label->draw(window);
	this->lineEdit->draw(window);
}

void MainMenu::update(Client* client, CurrentIMMenu* curMenu)
{
	Mouse mouse;
	auto mouse_pos = mouse.getPosition(*window);
	
	if (eve->type == Event::MouseButtonReleased && eve->mouseButton.button == Mouse::Left)
	{
		if (button->isOnButton(mouse_pos))
			*curMenu = CurrentIMMenu::Game;
			
	}
}

