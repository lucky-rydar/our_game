#pragma once
#include "Player.h"
#include <vector>
#include <map>

using namespace std;

class PlayersData
{
public:
	PlayersData();

	void addPlayer(Player plr);
	Player& findByLogin(string login);
	

private:
	vector<Player> players_vector;
	map<string, Player> players_by_login;
};

