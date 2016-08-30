#include "stdafx.h"
#include "Bank.h"

Bank::Bank()
{
	this->coins = 3;
}

int Bank::get_coins()
{
	return this->coins;
}

void Bank::deposit(int val)
{
	this->coins += val;
}

int Bank::withdraw(int val)
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
