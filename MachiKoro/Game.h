#pragma once
#include <vector>

#include "Card.h"
#include "Bank.h"
#include "Deck.h"

using namespace std;

struct player {
	string name;
	Bank *bank;
	vector<BlueCard*> blue_cards;
	vector<GreenCard*> green_cards;
	vector<RedCard*> red_cards;
	vector<PurpleCard*> purple_cards;
	vector<YellowCard*> yellow_cards;
};

class Game {
public:
	Game();
	int turn;
	bool is_game_over;
	void deal();
	Deck* get_deck();
	vector<vector<Card *>> get_slot();
	vector<player*> players;
	void create_player(string name);
	void roll_dice();
	void red_card_check();
	void blue_card_check();
	void green_card_check();
	void purple_card_check();
	void buy_propery();
	void end_of_turn();
	void view_slot_cards(bool cls);
	void view_player_cards(int index, bool cls);
private:
	int dice;
	int dice1;
	int dice2;
	void rolling_dice(int dice_count);
	int player_input(string message);
	vector<vector<Card *>> slot;
	int slot_count;
	Deck *d;
};