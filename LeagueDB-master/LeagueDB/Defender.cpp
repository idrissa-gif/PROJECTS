
#include "Defender.h"

Defender::Defender():Player("localhost", "root", "test123", "leaguedb")
{
}

void Defender::insert(std::string position)
{
	Player::insert(position);
}
