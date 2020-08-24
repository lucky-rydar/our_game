#include "MainMenu.h"

MainMenu::MainMenu(sf::Vector2f WindowSize, Event *eve, RenderWindow* win, CurrentIMMenu* curMenu)
{
	musicManager.setVolume(100);
	musicManager.play();
	
	
	this->window = win;
	this->curMMenu = new CurrentMainMenu;
	*this->curMMenu = CurrentMainMenu::Main;

	font = new Font;
	font->loadFromFile(std::string("Resources\\Fonts\\lilita_one_rus.ttf"));

	this->lineEdit = new LineEdit(font, "Hello", 1, 1, 100, 50, Color::Black, Color::White);

	sf::Texture texture;
	sf::Texture texture2;
	texture.loadFromFile("Resources\\Sprites\\Interface\\Button 1.png");

	this->PlayButton = new SpriteButton(font, sf::String("Play"), WindowSize.x / 2, WindowSize.y / 2 - 200, 1.f, 1.f, texture, win);
	this->PlayButton->setOnButtonFunc([this, curMenu]() {*curMenu = CurrentIMMenu::Game; musicManager.stop(); });

	this->SettingsButton = new SpriteButton(font, sf::String("Settings"), WindowSize.x / 2, WindowSize.y / 2 - 100, 1.f, 1.f, texture, win);
	this->SettingsButton->setOnButtonFunc([this]() {*curMMenu = CurrentMainMenu::Settings; });
	
	this->SettingsBack = new SpriteButton(font, sf::String("Back"), WindowSize.x / 8, WindowSize.y / 1.1, 1.f, 1.f, texture, win);
	this->SettingsBack->setOnButtonFunc([this]() {*curMMenu = CurrentMainMenu::Main;});

	this->SettingsGeneral = new SpriteButton(font, sf::String("General"), WindowSize.x / 8, WindowSize.y / 8, 1.f, 1.f, texture, win);
	this->SettingsGeneral->setOnButtonFunc([this]() {*curMMenu = CurrentMainMenu::Settings; });

	this->SettingsGraphics = new SpriteButton(font, sf::String("Graphics"), WindowSize.x / 8, WindowSize.y / 4, 1.f, 1.f, texture, win);
	this->SettingsGraphics->setOnButtonFunc([this]() {*curMMenu = CurrentMainMenu::SettingsGraphics; });

	this->SettingsSounds = new SpriteButton(font, sf::String("Sounds"), WindowSize.x / 8, WindowSize.y / 2.7, 1.f, 1.f, texture, win);
	this->SettingsSounds->setOnButtonFunc([this]() {*curMMenu = CurrentMainMenu::SettingsSound; });

	this->ExitButton = new SpriteButton(font, sf::String("Exit"), WindowSize.x / 2, WindowSize.y / 2, 1.f, 1.f, texture, win);
	this->ExitButton->setOnButtonFunc([win]() {
		win->close();
		exit(0);
		});

	this->label = new Label(font, sf::String("our_game"), WindowSize.x / 2, WindowSize.y / 8 - 25, sf::Color::White);

	this->lineEdit = new LineEdit(font, sf::String("Username"), WindowSize.x / 2, WindowSize.y / 2 - 100, 300.f, 60.f, 150.f, 30.f, sf::Color::Blue,
		sf::Color::Black, sf::Color::White);

	this->Vsynclabel = new Label(font, sf::String("VSync"), WindowSize.x / 1.3, WindowSize.y / 9, sf::Color::White);

	texture.loadFromFile("Resources\\Sprites\\Interface\\CheckBox.png");
	texture2.loadFromFile("Resources\\Sprites\\Interface\\Mark.png");
	this->Vsync = new CheckBox(texture, texture2, WindowSize.x / 1.15, WindowSize.y / 9, 0.75, 0.75, win);
	this->Vsync->SetOnCheckFunc([win]() {win->setVerticalSyncEnabled(true); });
	this->Vsync->SetNonCheckFunc([win]() {win->setVerticalSyncEnabled(false); });

	this->FullScreenlabel = new Label(font, "FullScreen", WindowSize.x / 1.3, WindowSize.y / 5, sf::Color::White);

	this->FullScreen = new CheckBox(texture, texture2, WindowSize.x / 1.15, WindowSize.y / 5, 0.75, 0.75, win);
	this->FullScreen->SetOnCheckFunc([win]() mutable
		{
			sf::VideoMode mode;
			mode.height = mode.getFullscreenModes()[1].height;
			mode.width = mode.getFullscreenModes()[1].width;
			delete win;
			win = new sf::RenderWindow(mode, "our_game", sf::Style::Fullscreen);
		});
	this->FullScreen->SetNonCheckFunc([win]() mutable
		{
			delete win;
			win = new sf::RenderWindow(sf::VideoMode(1280, 720), "our_game");
		});

	texture.loadFromFile("Resources\\Sprites\\Interface\\Button 3.png");
	this->UsrName = new SpriteLineEdit(font, "Username", texture, WindowSize.x / 2, WindowSize.y / 9, 1.f, 0.75, win);

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
		
		//this->lineEdit->draw(window); // here
	}
	else if (*this->curMMenu == CurrentMainMenu::Settings)
	{
		this->SettingsBack->draw();
		this->SettingsGeneral->draw();
		this->SettingsGraphics->draw();
		this->SettingsSounds->draw();

		this->UsrName->draw();
	}
	else if (*this->curMMenu == CurrentMainMenu::SettingsGraphics)
	{
		this->SettingsBack->draw();
		this->SettingsGeneral->draw();
		this->SettingsGraphics->draw();
		this->SettingsSounds->draw();

		this->Vsync->draw();
		this->Vsynclabel->draw(window);

		this->FullScreen->draw();
		this->FullScreenlabel->draw(window);
	}
	else if (*this->curMMenu == CurrentMainMenu::SettingsSound)
	{
		this->SettingsBack->draw();
		this->SettingsGeneral->draw();
		this->SettingsGraphics->draw();
		this->SettingsSounds->draw();
	}
}

void MainMenu::update(Client* client)
{
	if (*this->curMMenu == CurrentMainMenu::Main)
	{
		//lineEdit->update(eve);
		PlayButton->update(eve);
		SettingsButton->update(eve);
		ExitButton->update(eve);
	}
	else if (*this->curMMenu == CurrentMainMenu::Settings)
	{
		this->SettingsBack->update(eve);
		this->SettingsGeneral->update(eve);
		this->SettingsGraphics->update(eve);
		this->SettingsSounds->update(eve);

		this->UsrName->update(eve);
	}
	else if (*this->curMMenu == CurrentMainMenu::SettingsGraphics)
	{
		this->SettingsBack->update(eve);
		this->SettingsGeneral->update(eve);
		this->SettingsGraphics->update(eve);
		this->SettingsSounds->update(eve);

		this->Vsync->update(eve);
		this->FullScreen->update(eve);
	}
	else if (*this->curMMenu == CurrentMainMenu::SettingsSound)
	{
		this->SettingsBack->update(eve);
		this->SettingsGeneral->update(eve);
		this->SettingsGraphics->update(eve);
		this->SettingsSounds->update(eve);
	}
}

