#pragma once

#include "Card.h"

using namespace machi;

class RedCard : public Card {
public:
	virtual void action() = 0;
private:
};

class Cafe : public RedCard {
public:
	Cafe();
	void action();
};

class FamilyRestaurant : public RedCard {
public:
	FamilyRestaurant();
	void action();
};