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

	YellowCard *c;
	c = new TrainStation(); p->yellow_cards.push_back(c);
	c = new ShoppingMall(); p->yellow_cards.push_back(c);
	c = new AmusementPark(); p->yellow_cards.push_back(c);
	c = new RadioTower(); p->yellow_cards.push_back(c);

	BlueCard *b;
	b = new WheatField(); p->blue_cards.push_back(b);

	GreenCard *g;
	g = new Bakery(); p->green_cards.push_back(g);

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

void Game::rolling_dice(int dice_count)
{
	this->dice1 = rand() % 6 + 1;
	this->dice2 = 0;

	if (dice_count == 2)
	{
		this->dice2 = rand() % 6 + 1;
	}
	this->dice = this->dice1 + this->dice2;
}

void Game::roll_dice()
{
	int dice_count = 1;

	// Should be Train Station Card
	if (this->players[this->turn]->yellow_cards[0]->active)
	{
		cout << "1 or 2 dice: ";
		cin >> dice_count;
	}
	this->rolling_dice(dice_count);

	// Should be Radio Tower
	if (this->players[this->turn]->yellow_cards[3]->active)
	{
		cout << "Rolled a " << this->dice << ". Reroll(y/n): ";
		char response;
		cin >> response;
		if (response == 'y') this->rolling_dice(dice_count);
	}

	cout << endl;
	cout << "Player: " << this->turn << " | rolled a " << this->dice << " | Coins: " << this->players[turn]->bank->get_coins() << endl;

	this->red_card_check();
}

void Game::red_card_check()
{
	cout << "Checking Red Cards..." << endl;
	int tracker = this->turn - 1;
	if (tracker < 0) tracker = this->players.size() - 1;

	while (tracker != this->turn)
	{
		for (int i = 0; i < this->players[tracker]->red_cards.size(); i++)
		{
			if (this->dice <= this->players[tracker]->red_cards[i]->get_high_roll() &&
				this->dice >= this->players[tracker]->red_cards[i]->get_low_roll())
			{
				Card *c = NULL;
				if (this->players[tracker]->yellow_cards[2]->active) c = this->players[tracker]->red_cards[i];
				this->players[tracker]->red_cards[i]->action(
					this->players[tracker]->bank,
					this->players[this->turn]->bank,
					c,
					NULL,
					0
					);
			}
			//if (this->players[i]->bank->get_coins() == 0) break;
		}
		tracker--;
		if (tracker < 0) tracker = this->players.size() - 1;

	}
	this->blue_card_check();
}
void Game::blue_card_check()
{
	cout << "Checking Blue Cards..." << endl;
	for (int i = 0; i < this->players.size(); i++)
	{
		for (int j = 0; j < this->players[i]->blue_cards.size(); j++)
		{
			if (this->dice <= this->players[i]->blue_cards[j]->get_high_roll() &&
				this->dice >= this->players[i]->blue_cards[j]->get_low_roll())
			{
				this->players[i]->blue_cards[j]->action(
					this->players[i]->bank,
					NULL,
					NULL,
					NULL,
					0
					);
			}
		}
	}
	this->green_card_check();
}
void Game::green_card_check()
{
	cout << "Checking Green Cards..." << endl;
	for (int i = 0; i < this->players[this->turn]->green_cards.size(); i++)
	{
		if (this->dice <= this->players[this->turn]->green_cards[i]->get_high_roll() &&
			this->dice >= this->players[this->turn]->green_cards[i]->get_low_roll())
		{
			Card *c = NULL;
			if (this->players[this->turn]->yellow_cards[2]->active) c = this->players[this->turn]->red_cards[i];
			int val = 0;
			Icon icon = this->players[this->turn]->green_cards[i]->get_icon();
			if (icon != Icon::none)
			{
				for (int j = 0; j < this->players[this->turn]->blue_cards.size(); j++)
				{
					if (icon == this->players[this->turn]->blue_cards[j]->get_icon()) val++;
				}
			}
			this->players[this->turn]->green_cards[i]->action(
				this->players[this->turn]->bank,
				NULL,
				c,
				NULL,
				val
				);
		}
	}
	this->purple_card_check();
}

// TODO: Purple cards need to be referenced on the roll
void Game::purple_card_check()
{
	cout << "Checking Purple Cards..." << endl;
	cout << "Nothing to do" << endl;
	this->buy_propery();
}

// TODO: Allow buying of property
void Game::buy_propery()
{
	cout << "Which property would you like to buy?" << endl;
	this->end_of_turn();
}

void Game::end_of_turn()
{
	this->is_game_over = true;
	for (int i = 0; i < this->players[turn]->yellow_cards.size(); i++)
	{
		if (!this->players[turn]->yellow_cards[i]->active)
		{
			this->is_game_over = false;
			break;
		}
	}
	if (this->is_game_over) { cout << this->turn << " wins" << endl; return; }
	cout << "End of " << this->turn << "'s turn. Coins: " << this->players[turn]->bank->get_coins();
	this->turn++;

	// Should be Amusement Park card
	if (this->players[this->turn]->yellow_cards[2]->active)
	{
		turn--;
	}
	if (this->turn == players.size()) this->turn = 0;
	cout << " | " << this->turn << "'s turn next";
	return;
}