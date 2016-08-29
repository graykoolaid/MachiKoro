#include "stdafx.h"

#include "Card.h"

using namespace machi;

Card::Card()
{

}

void Card::set_card(string name, int cost, int value, int low_roll, int high_roll, Icon icon)
{
	this->set_name(name);
	this->set_value(value);
	this->set_cost(cost);
	this->set_low_roll(low_roll);
	this->set_high_roll(high_roll);
	this->set_icon(icon);
	this->set_color(Color::blue);
}

void Card::set_cost(int cost)
{
	this->cost = cost;
}
void Card::set_value(int value)
{
	this->value = value;
}
void Card::set_color(Color color)
{
	this->color = color;
}
void Card::set_name(string name)
{
	this->name = name;
}
void Card::set_renovation(bool renovation)
{
	this->renovation = renovation;
}
void Card::set_low_roll(int low)
{
	this->low_roll = low;
}
void Card::set_high_roll(int high)
{
	this->high_roll = high;
}
void Card::set_icon(Icon icon)
{
	this->icon = icon;
}

int Card::get_value()
{
	return this->value;
}
int Card::get_cost()
{
	return this->cost;
}
Color Card::get_color()
{
	return this->color;
}
bool Card::get_renovation()
{
	return this->renovation;
}
string Card::get_name()
{
	return this->name;
}
Icon Card::get_icon()
{
	return this->icon;
}