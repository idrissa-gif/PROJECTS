#pragma once
#ifndef __IOSTREAM_H
#include <iostream>
#endif // !__IOSTREAM_H

#ifndef GOALKEEPER_H
#include "GoalKeeper.h"
#endif

#ifndef PLAYER_H
#include "Player.h"
#endif 

#ifndef DEFENDER_H
#include "Defender.h"
#endif
#ifndef MIDFIELDER_H
#include "Midfielder.h"
#endif 

#ifndef ATTACKER_H
#include "Attacker.h"
#endif 
using namespace std;
namespace menu
{
	enum MainMenuOptions { CONTINUELEAGUE = 1, NEW, EXIT }; //ch1
	enum ExistingLeagueMenuOptions { VIEWSCORES = 1, STANDINGSTABLE, MOSTPOINTS, MOSTGOALS, HIGHDIFF, LEASTPOINTS, LEASTGOALS, LOWDIFF, V_END };//ch7
	enum NewLeaueMenuOptions { TEAM = 1, MANAGER, PLAYER, STARTLEAGUE, GOBACK}; //ch3
	enum ConfirmationOptions { YES = 1, NO }; //ch2
	enum TeamOptions { ADDTEAM = 1, PRINTTEAMS, EDITTEAM, DELTEAM, SEARCHTEAM, T_END }; //ch4
	enum ManagerOptions { ADDMANAGER = 1, PRINTMANAGERS, EDITMANAGER, DELMANAGER, SEARCHMANAGER, M_END }; //ch5
	enum PlayerOptions { ADDPLAYER = 1, PRINTPLAYERS, EDITPLAYER, DELPLAYER, SEARCHPLAYER, P_END }; //ch6
	

	int mainMenu()
	{
		cout << "\nSTARTMENU OPTIONS" << std::endl
			<< "1 - Continue with existing league " << std::endl
			<< "2 - Create a new league" << std::endl
			<< "3 - EXIT" << std::endl;
		int ch;
		cin >> ch;
		return ch;
	}

	int existingLeagueMenu()
	{
		cout << "\nONGOING LEAGUE" << std::endl
			<< "1 - Enter scores for each fixture " << std::endl
			<< "2 - View team Standings " << std::endl
			<< "3 - Team with most points " << std::endl
			<< "4 - Team with most goals " << std::endl
			<< "5 - Team with highest goal difference " << std::endl
			<< "6 - Team with least points " << std::endl
			<< "7 - Team with least goals " << std::endl
			<< "8 - Team with lowest goal difference " << std::endl
			<< "9- Go back " << std::endl;
		    
		int ch;
		cin >> ch;
		return ch;
	}

	int newLeaueMenu()
	{
		cout << "\nNEW LEAGUE MENU" << std::endl
			<< "1 - Teams " << std::endl
			<< "2 - Managers" << std::endl
			<< "3 - Players" << std::endl
			<< "4 - START THE NEW LEAGUE" << std::endl
			<< "5 - Go back" << std::endl;
		int ch;
		cin >> ch;
		return ch;
	}

	int confirmation()
	{
		cout << "\nARE YOU SURE?" << std::endl
			<< "1 - Yes, confirm " << std::endl
			<< "2 - No, go back" << std::endl;
		int ch;
		cin >> ch;
		return ch;
	}

	int teamMenu()
	{
		cout << "Menu Options" << std::endl
			<< " 1 - ADD A NEW TEAM" << std::endl
			<< " 2 - PRINT THE TEAMS" << std::endl
			<< " 3 - EDIT A TEAM" << std::endl
			<< " 4 - DELETE A TEAM" << std::endl
			<< " 5 - SEARCH A TEAM" << std::endl
			<< " 6 - RETURN BACK" << std::endl;
		int ch;
		cin >> ch;
		return ch;
	}
	int playerMenu()
	{
		cout << "Menu Options" << std::endl
			<< " 1 - ADD A NEW PLAYER" << std::endl
			<< " 2 - PRINT THE PLAYERS" << std::endl
			<< " 3 - EDIT A PLAYER" << std::endl
			<< " 4 - DELETE A PLAYER" << std::endl
			<< " 5 - SEARCH A PLAYER" << std::endl
			<< " 6 - RETURN BACK" << std::endl;
		int ch;
		cin >> ch;
		return ch;
	}
	int managerMenu()
	{
		cout << "Menu Options" << std::endl
			<< " 1 - ADD A NEW MANAGER" << std::endl
			<< " 2 - PRINT THE MANAGERS" << std::endl
			<< " 3 - EDIT A MANAGER" << std::endl
			<< " 4 - DELETE A MANAGER" << std::endl
			<< " 5 - SEARCH A MANAGER" << std::endl
			<< " 6 - RETURN BACK" << std::endl;
		int ch;
		cin >> ch;
		return ch;
	}



	void checkposition()
	{
		Player* P;

		string pos;
		cout << "Enter The Player position by Number:\n"
			<< "1-GoalKeeper\n"
			<< "2-Defender\n"
			<< "3-Midfielder\n"
			<< "4-Attacker\n";
		cin >> pos;
		if (pos == "1")
		{
			P = new GoalKeeper();
			P->insert("GoalKeeper");
		}
		else if (pos == "2")
		{
			P = new Defender();
			P->insert("Defender");
		}
		else if (pos == "3")
		{
			P = new Midfielder();
			P->insert("Midfielder");
		}
		else if (pos == "4")
		{
			P = new Attacker();
			P->insert("Attacker");
		}
	}
	
};