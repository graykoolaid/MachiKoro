#include "stdafx.h"
#include "RedCard.h"

Cafe::Cafe() {
	this->set_card("Cafe", 2, 1, 3, 3, Icon::retaurant);
}
void Cafe::action() {

}

FamilyRestaurant::FamilyRestaurant() {
	this->set_card("FamilyRestaurant", 3, 2, 9, 10, Icon::retaurant);
}
void FamilyRestaurant::action() {

}