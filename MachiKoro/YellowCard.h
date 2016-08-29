#pragma once

#include "Card.h"

using namespace machi;

class YellowCard : public Card {
public:
	virtual void action() = 0;
private:
};

class AmusementPark : public Card {
public:
	AmusementPark();
	virtual void action() = 0;
private:
};

class RadioTower : public Card {
public:
	RadioTower();
	virtual void action() = 0;
private:
};

class ShoppingMall : public Card {
public:
	ShoppingMall();
	virtual void action() = 0;
private:
};

class TrainStation : public Card {
public:
	TrainStation();
	virtual void action() = 0;
private:
};