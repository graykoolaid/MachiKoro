#pragma once

#include <string>

using namespace std;

class Player{
public:
	Player(string name);
	void deposit(int val);
	int withdraw(int val);
	int get_coins();
	string get_name();
private:
	int coins;
	string name;
};