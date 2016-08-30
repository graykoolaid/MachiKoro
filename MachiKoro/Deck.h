#pragma once
#include <vector>
#include <iostream>
#include "Card.h"
#include "BlueCard.h"
#include "GreenCard.h"
#include "RedCard.h"
#include "PurpleCard.h"
#include "YellowCard.h"

using namespace std;

class Deck {
public:
	Deck();
	
	void shuffle();

	vector<Card*> deck;

private:
	void CreateBlueCards();
	void CreateRedCards();
	void CreateGreenCards();
	void CreateYellowCards();
	void CreatePurpleCards();
};