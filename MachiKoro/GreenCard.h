#pragma once

#include "Card.h"

using namespace machi;

class GreenCard : public Card {
public:
	virtual void action() = 0;
private:
};

class Bakery : public GreenCard {
public:
	Bakery();
	void action();
};

class ConvenienceStore : public GreenCard {
public:
	ConvenienceStore();
	void action();
};

class CheeseFactory : public GreenCard {
public:
	CheeseFactory();
	void action();
};

class FurnitureFactory : public GreenCard {
public:
	FurnitureFactory();
	void action();
};

class FruitAndVegetableMarket : public GreenCard {
public:
	FruitAndVegetableMarket();
	void action();
};