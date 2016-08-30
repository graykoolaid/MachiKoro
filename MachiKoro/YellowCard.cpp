#include "stdafx.h"
#include "YellowCard.h"

void YellowCard::action(Player *p1, Player *p2, Card *c1, Card *c2, int val)
{
	// Nothing to really do here yet
}

AmusementPark::AmusementPark() {
	this->set_card("AmusementPark", 16, 0, 0, 0, Icon::establishment);
}

RadioTower::RadioTower() {
	this->set_card("RadioTower", 22, 0, 0, 0, Icon::establishment);
}

ShoppingMall::ShoppingMall() {
	this->set_card("ShoppingMall", 10, 0, 0, 0, Icon::establishment);
}

TrainStation::TrainStation() {
	this->set_card("TrainStation", 4, 0, 0, 0, Icon::establishment);
}
