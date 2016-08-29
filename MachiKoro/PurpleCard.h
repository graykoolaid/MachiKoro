#pragma once

#include "Card.h"

using namespace machi;

class PurpleCard : public Card {
public:
	virtual void action() = 0;
private:
};

class BusinessCenter : public Card {
public:
	BusinessCenter();
	virtual void action();
private:
};

class Stadium : public Card {
public:
	Stadium();
	virtual void action();
private:
};

class TVStation : public Card {
public:
	TVStation();
	virtual void action();
private:
};