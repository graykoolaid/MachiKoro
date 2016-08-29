#pragma once

#include "Card.h"

using namespace machi;

class BlueCard: public Card {
public:
	virtual void action() = 0;
private:
};

class WheatField : public BlueCard {
public:
	WheatField();
	void action();
};

class Ranch : public BlueCard {
public:
	Ranch();
	void action();
};

class Forest : public BlueCard {
public:
	Forest();
	void action();
};

class Mine : public BlueCard {
public:
	Mine();
	void action();
};

class AppleOrchard : public BlueCard {
public:
	AppleOrchard();
	void action();
};