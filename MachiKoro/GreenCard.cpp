#include "stdafx.h"
#include "GreenCard.h"

Bakery::Bakery() {
	this->set_card("Bakery", 1, 1, 2, 3, Icon::bread);
}
void Bakery::action() {

}

ConvenienceStore::ConvenienceStore() {
	this->set_card("ConvenienceStore", 2, 3, 4, 4, Icon::bread);
}
void ConvenienceStore::action() {

}

CheeseFactory::CheeseFactory() {
	this->set_card("CheeseFactory", 5, 3, 7, 7, Icon::factory);
}
void CheeseFactory::action() {

}

FurnitureFactory::FurnitureFactory() {
	this->set_card("FurnitureFactory", 3, 3, 8, 8, Icon::bread);
}
void FurnitureFactory::action() {

}

FruitAndVegetableMarket::FruitAndVegetableMarket() {
	this->set_card("FruitAndVegetableMarket", 1, 1, 2, 3, Icon::bread);
}
void FruitAndVegetableMarket::action() {

}