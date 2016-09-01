#include "stdafx.h"
#include "BlueCard.h"

void BlueCard::action(Bank *p1, Bank *p2, Card *c1, Card *c2, int val)
{
	p1->deposit(this->get_value());
}

WheatField::WheatField()
{
	this->set_card("Wheat Field", 1, 1, 1, 1, Icon::grain, Color::blue);
}

Ranch::Ranch()
{
	this->set_card("Ranch", 1, 1, 2, 2, Icon::cow, Color::blue);
}

Forest::Forest()
{
	this->set_card("Forest", 3, 1, 5, 5, Icon::gear, Color::blue);
}

Mine::Mine()
{
	this->set_card("Mine", 6, 3, 9, 9, Icon::gear, Color::blue);
}

AppleOrchard::AppleOrchard()
{
	this->set_card("AppleOrchard", 2, 1, 10, 10, Icon::grain, Color::blue);
}