#include "GoalKeeper.h"

GoalKeeper::GoalKeeper():Player("localhost", "root", "test123", "leaguedb")
{
}

void GoalKeeper::insert(std::string position)
{
	Player::insert(position);
}
