#include "Attacker.h"
#include "Player.h"
#ifndef mysql_h
#include<mysql.h>
#endif // !mysql_h
#ifndef __IOSTREAM_H
#include<iostream>
#endif // !__IOSTREAM_H
#ifndef __SSTREAM_H
#include<sstream>
#endif

Attacker::Attacker():Player("localhost", "root", "test123", "leaguedb")
{
}

void Attacker::insert(std::string position)
{
	Player::insert(position);
}