#include "stdafx.h"
#include "RedCard.h"

// Player 1 will take coins from player 2
void RedCard::action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val)
{
	int bonus = 0;
	if (c1 != NULL) bonus = 1;
	p1->deposit(p2->withdraw(this->get_value()+bonus));
}

Cafe::Cafe() {
	this->set_card("Cafe", 2, 1, 3, 3, Icon::retaurant, Color::red);
}

FamilyRestaurant::FamilyRestaurant() {
	this->set_card("FamilyRestaurant", 3, 2, 9, 10, Icon::retaurant, Color::red);
}
