#include "stdafx.h"
#include "GreenCard.h"

void GreenCard::action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val)
{
	if (this->multiplier == Icon::none)
	{
		p1->deposit(this->get_value());
	}
	else
	{
		p1->deposit(this->get_value() * val);
	}
}

void GreenCard::set_multiplier_icon(Icon icon)
{
	this->multiplier = icon;
}

Bakery::Bakery() {
	this->set_card("Bakery", 1, 1, 2, 3, Icon::bread);
	this->set_multiplier_icon(Icon::none);
}

ConvenienceStore::ConvenienceStore() {
	this->set_card("ConvenienceStore", 2, 3, 4, 4, Icon::bread);
	this->set_multiplier_icon(Icon::none);
}

CheeseFactory::CheeseFactory() {
	this->set_card("CheeseFactory", 5, 3, 7, 7, Icon::factory);
	this->set_multiplier_icon(Icon::cow);
}

FurnitureFactory::FurnitureFactory() {
	this->set_card("FurnitureFactory", 3, 3, 8, 8, Icon::bread);
	this->set_multiplier_icon(Icon::gear);
}

FruitAndVegetableMarket::FruitAndVegetableMarket() {
	this->set_card("FruitAndVegetableMarket", 1, 1, 2, 3, Icon::bread);
	this->set_multiplier_icon(Icon::grain);
}
