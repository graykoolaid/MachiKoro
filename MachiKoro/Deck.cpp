#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include "Deck.h"


using namespace std;

ostream& operator << (ostream& os, const Color& obj)
{
	os << static_cast<typename underlying_type<Color>::type>(obj);
	return os;
}
ostream& operator << (ostream& os, const Icon& obj)
{
	os << static_cast<typename underlying_type<Icon>::type>(obj);
	return os;
}

Deck::Deck()
{
	Card *c;
	for (int i = 0; i < 6; i++) { c = new WheatField(); this->deck.push_back(c); }
	for (int i = 0; i < 6; i++) { c = new Ranch(); this->deck.push_back(c); }
	for (int i = 0; i < 6; i++) { c = new Forest(); this->deck.push_back(c); }
	for (int i = 0; i < 6; i++) { c = new Mine(); this->deck.push_back(c); }
	for (int i = 0; i < 6; i++) { c = new AppleOrchard(); this->deck.push_back(c); }

	for (int i = 0; i < 6; i++) { c = new Bakery(); this->deck.push_back(c); }
	for (int i = 0; i < 6; i++) { c = new ConvenienceStore(); this->deck.push_back(c); }
	for (int i = 0; i < 6; i++) { c = new CheeseFactory(); this->deck.push_back(c); }
	for (int i = 0; i < 6; i++) { c = new FurnitureFactory(); this->deck.push_back(c); }
	for (int i = 0; i < 6; i++) { c = new FruitAndVegetableMarket(); this->deck.push_back(c); }

	for (int i = 0; i < 6; i++) { c = new Cafe(); this->deck.push_back(c); }
	for (int i = 0; i < 6; i++) { c = new FamilyRestaurant(); this->deck.push_back(c); }

	for (int i = 0; i < 4; i++) { c = new BusinessCenter(); this->deck.push_back(c); }
	for (int i = 0; i < 4; i++) { c = new TVStation(); this->deck.push_back(c); }
	for (int i = 0; i < 4; i++) { c = new Stadium(); this->deck.push_back(c); }


	this->shuffle();
}

void Deck::shuffle()
{
	srand(unsigned(std::time(0)));
	random_shuffle(this->deck.begin(), this->deck.end());
	random_shuffle(this->deck.begin(), this->deck.end());
	random_shuffle(this->deck.begin(), this->deck.end());
	random_shuffle(this->deck.begin(), this->deck.end());
	random_shuffle(this->deck.begin(), this->deck.end());
	random_shuffle(this->deck.begin(), this->deck.end());
}