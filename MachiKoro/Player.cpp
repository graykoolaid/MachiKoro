#include "stdafx.h"
#include "Player.h"

Player::Player(string name)
{
	this->name = name;
	this->coins = 3;
}

int Player::get_coins()
{
	return this->coins;
}

void Player::deposit(int val)
{
	this->coins += val;
}

int Player::withdraw(int val)
{
	if (val > this->coins)
	{
		int temp = this->coins;
		this->coins = 0;
		return this->coins;
	}

	this->coins -= val;
	return val;
}

string Player::get_name()
{
	return this->name;
}