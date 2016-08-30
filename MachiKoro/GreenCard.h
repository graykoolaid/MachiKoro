#pragma once

#include "Card.h"

using namespace machi;

class GreenCard : public Card {
public:
	virtual void action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val);
	void set_multiplier_icon(Icon icon);
private:
	Icon multiplier = Icon::none;
};

class Bakery : public GreenCard {
public:
	Bakery();
};

class ConvenienceStore : public GreenCard {
public:
	ConvenienceStore();
};

class CheeseFactory : public GreenCard {
public:
	CheeseFactory();
};

class FurnitureFactory : public GreenCard {
public:
	FurnitureFactory();
};

class FruitAndVegetableMarket : public GreenCard {
public:
	FruitAndVegetableMarket();
};