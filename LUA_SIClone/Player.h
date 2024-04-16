/*
Space invaders game
Author:		Philip Alassad
Filename:	Player.h
Date:		14/10/2015
Last Updated:	__/__/____

Description: Header file for Player class
*/

#pragma once

//includes go here
#include "Ship.h"
#include "Helper.h"

using namespace std;

//lua_State* L;

class Player: public Ship
{
private:
	//members
	int m_lives;
	int m_score;
	lua_State* Ls;

	void setScore(int score);

public:
	//constructor
	Player(float xPos, float yPos, int lives, string filename);
	~Player(void);

	void Init(Dispatcher& disp)
	{
		Dispatcher::Command::voidintfunc f{ [this](int score) {return setScore(score); } };
		disp.Register("setScore", Dispatcher::Command{ f });
	}

	//methods
	void reduceLives();
	void increaseLives();
	int getLives();
	int getScore();
	void kill();
	void reset_lives();
	void reset_score();
	void right();
	void left();
};