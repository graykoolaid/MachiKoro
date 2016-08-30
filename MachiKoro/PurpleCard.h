#pragma once

#include "Card.h"

using namespace machi;

class PurpleCard : public Card {
public:
	virtual void action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val) = 0;
private:
};

class BusinessCenter : public PurpleCard {
public:
	BusinessCenter();
	virtual void action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val);
private:
};

class Stadium : public PurpleCard {
public:
	Stadium();
	virtual void action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val);
private:
};

class TVStation : public PurpleCard {
public:
	TVStation();
	virtual void action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val);
private:
};