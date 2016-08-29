#include "stdafx.h"
#include "PurpleCard.h"

BusinessCenter::BusinessCenter() {
	this->set_card("BusinessCenter", 8, 0, 6, 6, Icon::establishment);
}
void BusinessCenter::action() {

}

Stadium::Stadium() {
	this->set_card("Stadium", 6, 2, 6, 6, Icon::establishment);
}
void Stadium::action() {

}

TVStation::TVStation() {
	this->set_card("TVStation", 7, 5, 6, 6, Icon::retaurant);
}
void TVStation::action() {

}