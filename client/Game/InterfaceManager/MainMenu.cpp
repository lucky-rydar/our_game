#include "MainMenu.h"

MainMenu::MainMenu(sf::Vector2f WindowSize, Event *eve, RenderWindow* win, CurrentIMMenu* curMenu)
{
	this->window = win;
	this->curMMenu = new CurrentMainMenu;
	*this->curMMenu = CurrentMainMenu::Main;

	font = new Font;
	font->loadFromFile(std::string("Resources\\Fonts\\lilita_one_rus.ttf"));

	this->lineEdit = new LineEdit(font, "Hello", 1, 1, 100, 50, Color::Black, Color::White);

	sf::Texture texture;
	texture.loadFromFile("Resources\\Sprites\\Interface\\Button 1.png");

	this->PlayButton = new SpriteButton(font, sf::String("Play"), WindowSize.x / 2, WindowSize.y / 2 - 200, 1.f, 1.f, texture, win);
	this->PlayButton->setOnButtonFunc([curMenu]() {*curMenu = CurrentIMMenu::Game; });

	this->SettingsButton = new SpriteButton(font, sf::String("Settings"), WindowSize.x / 2, WindowSize.y / 2 - 100, 1.f, 1.f, texture, win);
	this->SettingsButton->setOnButtonFunc([this]() {*curMMenu = CurrentMainMenu::Settings; });
	
	this->SettingsBack = new SpriteButton(font, sf::String("Back"), WindowSize.x / 20, WindowSize.y / 1.2, 1.f, 1.f, texture, win);
	this->SettingsBack->setOnButtonFunc([this]() {*curMMenu = CurrentMainMenu::Main; });

	this->ExitButton = new SpriteButton(font, sf::String("Exit"), WindowSize.x / 2, WindowSize.y / 2, 1.f, 1.f, texture, win);
	this->ExitButton->setOnButtonFunc([win]() {win->close(); });

	this->label = new Label(font, sf::String("our_game"), WindowSize.x / 2 + 40, WindowSize.y / 8, sf::Color::White);
	this->lineEdit = new LineEdit(font, sf::String("Username"), WindowSize.x / 2, WindowSize.y / 2 - 100, 300.f, 60.f, 150.f, 30.f, sf::Color::Blue,
		sf::Color::Black, sf::Color::White);

	this->eve = eve;
}

MainMenu::~MainMenu()
{
	delete this->PlayButton;
	delete this->SettingsButton;
	delete this->ExitButton;
	
	delete this->SettingsBack;

	delete this->label;
	delete this->lineEdit;
}

void MainMenu::draw()
{
	if (*this->curMMenu == CurrentMainMenu::Main)
	{
		this->PlayButton->draw();
		this->SettingsButton->draw();
		this->ExitButton->draw();

		this->label->draw(window);
		
		this->lineEdit->draw(window); // here
	}
	else if (*this->curMMenu == CurrentMainMenu::Settings)
	{
		this->SettingsBack->draw();
	}
	
}

void MainMenu::update(Client* client)
{
	if (*this->curMMenu == CurrentMainMenu::Main)
	{
		lineEdit->update(eve);
		PlayButton->update(eve);
		SettingsButton->update(eve);
		ExitButton->update(eve);
	}
	else if (*this->curMMenu == CurrentMainMenu::Settings)
	{
		this->SettingsBack->update(eve);
	}
}

