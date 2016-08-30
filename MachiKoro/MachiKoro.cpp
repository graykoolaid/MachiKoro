// MachiKoro.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

#include "Deck.h"
#include "Game.h"

using namespace std;

void view_slots(Game *g)
{
	vector<vector<Card*>> s = g->get_slot();
	for (int i = 0; i < s.size(); i++)
	{
		cout << i << ": " << s[i][0]->get_name() << ": " << s[i].size() << endl;
	}
}

int main()
{
	Deck *d;

	Game *g = new Game();
	g->deal();

	view_slots(g);

	g->deal();

	view_slots(g);

	char t;
	cin >> t;
    return 0;
}

