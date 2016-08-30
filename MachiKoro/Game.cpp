#include "stdafx.h"
#include "Game.h"

Game::Game() 
{
	this->d = new Deck();
	this->slot_count = 0;
}

void Game::deal()
{
	Card *c;
	bool exists;
	while (this->d->deck.size() > 0 && this->slot.size() < 10)
	{
		exists = false;
		c = this->d->deck.back();
		for (int i = 0; i < this->slot.size(); i++)
		{
			if ( c->get_name().compare(this->slot[i][0]->get_name()) == 0 )
			{
				slot[i].push_back(c);
				exists = true;
				break;
			}
		}

		if (!exists)
		{
			vector<Card*> v;
			v.push_back(c);
			this->slot.push_back(v);
			this->slot_count++;
		}
		this->d->deck.pop_back();
	}
}

Deck* Game::get_deck()
{
	return this->d;
}

vector<vector<Card *>> Game::get_slot()
{
	return this->slot;
}