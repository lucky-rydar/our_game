#include "PlayersData.h"

PlayersData::PlayersData()
{
	
}

void PlayersData::addPlayer(Player plr)
{
	players_vector.push_back(plr);
	players_by_login.at(plr.login) = plr;
}

Player& PlayersData::findByLogin(string login)
{
	return (Player&)players_by_login.at(login);
}
