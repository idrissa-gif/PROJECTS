#include "Player.h"
#include "Midfielder.h"

Midfielder::Midfielder():Player("localhost", "root", "test123", "leaguedb")
{
}

void Midfielder::insert(std::string position)
{
	Player::insert(position);
}
