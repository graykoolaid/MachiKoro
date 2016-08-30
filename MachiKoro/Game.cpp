#include "stdafx.h"
#include "Game.h"

Game::Game() 
{
	this->d = new Deck();
	this->slot_count = 0;
	this->is_game_over = false;
	this->turn = 0;
	this->deal();
	
	this->create_player("Michael");
	this->create_player("Dave");
	this->create_player("Bob");
	this->create_player("Jim");
}

void Game::create_player(string name)
{
	player *p = new player();
	p->bank = new Bank();
	p->name = name;
	players.push_back(p);
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

int Game::roll_dice()
{
	return rand() % 6;
}

void Game::iterate(Color c)
{

}

void Game::yellow_card_check()
{

}
void Game::red_card_check()
{

}
void Game::blue_card_check()
{

}
void Game::green_card_check()
{

}
void Game::purple_card_check()
{

}
void Game::buy_propery()
{

}
void Game::end_of_turn()
{

}