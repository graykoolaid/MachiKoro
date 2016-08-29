#include "stdafx.h"
#include "BlueCard.h"

WheatField::WheatField()
{
	this->set_card("Wheat Field", 1, 1, 1, 1, Icon::grain);
}

void WheatField::action()
{

}

Ranch::Ranch()
{
	this->set_card("Ranch", 1, 1, 2, 2, Icon::cow);
}
void Ranch::action()
{

}

Forest::Forest()
{
	this->set_card("Forest", 3, 1, 5, 5, Icon::gear);
}
void Forest::action()
{

}

Mine::Mine()
{
	this->set_card("Mine", 6, 3, 9, 9, Icon::gear);
}
void Mine::action()
{

}

AppleOrchard::AppleOrchard()
{
	this->set_card("AppleOrchard", 2, 1, 10, 10, Icon::grain);
}
void AppleOrchard::action()
{

}