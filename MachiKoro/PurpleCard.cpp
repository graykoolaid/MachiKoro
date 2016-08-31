#include "stdafx.h"
#include "PurpleCard.h"

BusinessCenter::BusinessCenter() {
	this->set_card("BusinessCenter", 8, 0, 6, 6, Icon::establishment);
}

// TODO: Add Business center functionality
void BusinessCenter::action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val) {
	// This one is going to be fun
}

Stadium::Stadium() {
	this->set_card("Stadium", 6, 2, 6, 6, Icon::establishment);
}
void Stadium::action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val) {
	p1->deposit(p2->withdraw(this->get_value()));
}

TVStation::TVStation() {
	this->set_card("TVStation", 7, 5, 6, 6, Icon::retaurant);
}
void TVStation::action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val) {
	p1->deposit(p2->withdraw(this->get_value()));
}