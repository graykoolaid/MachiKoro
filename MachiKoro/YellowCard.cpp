#include "stdafx.h"
#include "YellowCard.h"

void YellowCard::action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val)
{
	// Nothing to really do here yet because yellow cards dont perform actions in the same manner
}

TrainStation::TrainStation() {
	this->active = false;
	this->set_card("TrainStation", 4, 0, 0, 0, Icon::establishment, Color::yellow);
}

ShoppingMall::ShoppingMall() {
	this->active = false;
	this->set_card("ShoppingMall", 10, 0, 0, 0, Icon::establishment, Color::yellow);
}

AmusementPark::AmusementPark() {
	this->active = false;
	this->set_card("AmusementPark", 16, 0, 0, 0, Icon::establishment, Color::yellow);
}

RadioTower::RadioTower() {
	this->active = false;
	this->set_card("RadioTower", 22, 0, 0, 0, Icon::establishment, Color::yellow);
}


