#pragma once

#include "Card.h"

using namespace machi;

class YellowCard : public Card {
public:
	virtual void action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val);
	bool active;
private:
};

class AmusementPark : public YellowCard {
public:
	AmusementPark();
private:
};

class RadioTower : public YellowCard {
public:
	RadioTower();
private:
};

class ShoppingMall : public YellowCard {
public:
	ShoppingMall();
private:
};

class TrainStation : public YellowCard {
public:
	TrainStation();
private:
};