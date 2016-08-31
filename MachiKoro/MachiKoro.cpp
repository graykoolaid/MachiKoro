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
	Game *g = new Game();
	view_slots(g);

	int dice;
	while (!g->is_game_over)
	{
		g->roll_dice();

		// This doesnt do anything yet..
		//void yellow_card_check();

		//void red_card_check();
		//void blue_card_check();
		//void green_card_check();
		//void purple_card_check();
		//void buy_propery();
		//void end_of_turn();
		//g->is_game_over = true;
		char t;
		cin >> t;
	}


	char t;
	cin >> t;
    return 0;
}

