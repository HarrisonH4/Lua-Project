/*
Space invaders game
Author:		Philip Alassad
Filename:	Player.cpp
Date:		14/10/2015
Last Updated:	__/__/____

Description: Source file for Player class
*/

#include "Player.h"
#include <stdio.h>

//Constructor
Player::Player(float xPos, float yPos, int lives, string filename)
	:Ship(xPos, yPos, filename)
{
	m_lives = lives;
	m_score = 0;

	Ls = luaL_newstate();

	luaL_openlibs(Ls);

	if (!LuaOK(Ls, luaL_dofile(Ls, "LuaScript.lua")))
		assert(false);
}

Player::~Player()
{
	lua_close(Ls);
}

//Methods
int Player::getScore()//gets the current score
{
	return m_score;
}

void Player::reduceLives()
{
	m_lives -= 1;
}

void Player::increaseLives()
{
	m_lives += 1;
}

int Player::getLives()
{
	return m_lives;
}

void Player::setScore(int score)
{
	m_score = m_score + score;
}

void Player::kill()
{
	m_lives = 0;
}

void Player::reset_lives()
{
	m_lives = 3;
}

void Player::reset_score()
{
	m_score = 0;
}

void Player::right()
{
	CallmoveRight(Ls, "right", m_xpos, m_current_frame);
}

void Player::left()
{
	CallmoveLeft(Ls, "left", m_xpos, m_current_frame);
}

void Player::InitGame()
{
	CallInitGame(Ls, "InitGame", SWidth, SHeight);
}