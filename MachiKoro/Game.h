#pragma once
#include <vector>

#include "Card.h"
#include "Player.h"
#include "Deck.h"

using namespace std;

class Game {
public:
	Game();
	void deal();
	Deck* get_deck();
	vector<vector<Card *>> get_slot();
private:
	vector<vector<Card *>> slot;
	int slot_count;
	Deck *d;
};