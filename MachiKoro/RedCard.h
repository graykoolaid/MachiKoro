#pragma once

#include "Card.h"

using namespace machi;

class RedCard : public Card {
public:
	virtual void action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val);
private:
};

class Cafe : public RedCard {
public:
	Cafe();
};

class FamilyRestaurant : public RedCard {
public:
	FamilyRestaurant();
};