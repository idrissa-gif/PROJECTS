
#pragma once
#include "Player.h"
#ifndef __IOSTREAM_H
#include<iostream>
#endif // !__IOSTREAM_H
#ifndef __SSTREAM_H
#include<sstream>
#endif

class Defender : public Player 
{
public:
	Defender();
	void insert(std::string);
};
