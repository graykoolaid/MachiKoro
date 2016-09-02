#include "stdafx.h"
#include <iomanip>
#include <sstream>
#include "Game.h"
#include <regex>;

using namespace std;

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

void print_card(Card *c)
{
	cout << left <<
		setw(10) << c->get_string_color() <<
		setw(25) << c->get_name() <<
		setw(5) << c->get_cost() <<
		setw(5) << c->get_value() <<
		setw(5) << c->get_low_roll() <<
		setw(5) << c->get_high_roll() << endl;
}

void print_card_heading()
{
	cout << left <<
		setw(10) << "color" <<
		setw(25) << "name" <<
		setw(5) << "cost" <<
		setw(5) << "val" <<
		setw(5) << "low" <<
		setw(5) << "high" << endl;
}

void Game::view_slot_cards(bool cls)
{
	if (cls) system("cls");
	cout << left <<
		setw(5) << "slot" <<
		setw(5) << "qty";
	print_card_heading();
	for (int i = 0; i < this->slot.size(); i++)
	{
		cout << left <<
			setw(5) << i <<
			setw(5) << this->slot[i].size();
		print_card(this->slot[i][0]);
	}
	cout << endl;
}

void Game::view_player_cards(int index, bool cls)
{
	if (cls) system("cls");
	print_card_heading();
	for (int i = 0; i < this->players[index]->blue_cards.size(); i++) { print_card(this->players[index]->blue_cards[i]); }
	cout << endl;
	for (int i = 0; i < this->players[index]->green_cards.size(); i++) { print_card(this->players[index]->green_cards[i]); }
	cout << endl;
	for (int i = 0; i < this->players[index]->red_cards.size(); i++) { print_card(this->players[index]->red_cards[i]); }
	cout << endl;
	for (int i = 0; i < this->players[index]->purple_cards.size(); i++) { print_card(this->players[index]->purple_cards[i]); }
	cout << endl;
	for (int i = 0; i < this->players[index]->yellow_cards.size(); i++) { print_card(this->players[index]->yellow_cards[i]); }
	cout << endl;
}

vector<string> split(string str)
{
	stringstream ss(str);
	string item;
	vector<string> tokens;
	while (getline(ss, item, ' ')) {
		tokens.push_back(item);
	}
	return tokens;
}

int Game::player_input(string message)
{
	string cmds = "(no)"
		"|(view [0-9]+)"
		"|(view table)"
		"|(buy [0-9]*)";
	regex view(cmds);
	bool complete = false;
	while (true)
	{
		string str;
		getline(cin, str);
		vector<string> input = split(str);
		if (!regex_match(str, view))
		{
			cout << "Unknown Command" << endl;
		}
		else if (input[0] == "no") return -1;
		else if (input[0] == "view")
		{
			if (input[1] == "table") view_slot_cards(true);

			else if (stoi(input[1]) > this->players.size() - 1)
			{
				cout << "There is no player " << stoi(input[1]) << endl;
				continue;
			}
			else view_player_cards(stoi(input[1]), true);
			cout << message << endl;
		}
		else if (input[0] == "buy")
		{
			if (stoi(input[1]) > this->slot.size())
			{
				cout << "No card at number: " << stoi(input[1]) << endl;
				continue;
			}
			if (this->players[this->turn]->bank->get_coins() < this->slot[stoi(input[1])][0]->get_cost())
			{
				cout << "You cant afford that" << endl;
				continue;
			}
			return stoi(input[1]);
		}
	}
	return 'a';
}

void Game::roll_dice()
{
	system("cls");
	this->deal();
	this->view_slot_cards(true);
	this->view_player_cards(this->turn, false);
	
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
	cout << "Player: " << this->turn << " | rolled a " << this->dice << " | Coins: " << this->players[this->turn]->bank->get_coins() << endl;
	this->red_card_check();
}

void Game::red_card_check()
{
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
				// Should be Shopping Mall
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
	for (int i = 0; i < this->players[this->turn]->green_cards.size(); i++)
	{
		if (this->dice <= this->players[this->turn]->green_cards[i]->get_high_roll() &&
			this->dice >= this->players[this->turn]->green_cards[i]->get_low_roll())
		{
			Card *c = NULL;
			// Should be Shopping Mall
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

// TODO: Refactor this. Especially the card swapping. It u-g-l-y
void Game::purple_card_check()
{
	for (int i = 0; i < this->players[this->turn]->purple_cards.size(); i++)
	{
		if (this->players[this->turn]->purple_cards[i]->get_name().compare("Stadium") == 0)
		{
			for (int j = 0; j < this->players.size(); j++)
			{
				this->players[this->turn]->bank->deposit(this->players[j]->bank->withdraw(2));
			}
		}
		if (this->players[this->turn]->purple_cards[i]->get_name().compare("TV Station") == 0)
		{
			cout << "Take up to 5 coins from: ";
			for (int j = 0; j < this->players.size(); j++)
			{
				cout << j << ": " << this->players[j]->bank->get_coins() << " ";
			}
			int player_num;
			cin >> player_num;
			this->players[this->turn]->bank->deposit(this->players[player_num]->bank->withdraw(5));
		}
		if (this->players[this->turn]->purple_cards[i]->get_name().compare("Business Center") == 0)
		{
			cout << "Trade Cards with a player:" << endl;
			for (int j = 0; j < this->players.size(); j++)
			{
				cout << "Player: " << j << endl;
				cout << "Blue(1): ";
				for (int k = 0; i < this->players[j]->blue_cards.size(); k++)
				{
					cout << " |" << k << ": " << this->players[j]->blue_cards[k]->get_name();
				}
				cout << endl;
				cout << "Green(2): ";
				for (int k = 0; i < this->players[j]->green_cards.size(); k++)
				{
					cout << " |" << k << ": " << this->players[j]->green_cards[k]->get_name();
				}
				cout << endl;
				cout << "Red(3): ";
				for (int k = 0; i < this->players[j]->red_cards.size(); k++)
				{
					cout << " |" << k << ": " << this->players[j]->red_cards[k]->get_name();
				}
				cout << endl;
			}
			int player_num;
			int color_num;
			int card_num;
			cout << "Select Player to take: ";
			cin >> player_num;
			cout << endl;

			cout << "Select Color to take: ";
			cin >> color_num;
			cout << endl;

			cout << "Select Card to take: ";
			cin >> card_num;
			cout << endl;

			if (color_num == 1)
			{
				this->players[this->turn]->blue_cards.push_back(this->players[player_num]->blue_cards[card_num]);
				this->players[player_num]->blue_cards.erase(this->players[player_num]->blue_cards.begin() + card_num);
			}
			else if (color_num == 2)
			{
				this->players[this->turn]->green_cards.push_back(this->players[player_num]->green_cards[card_num]);
				this->players[player_num]->green_cards.erase(this->players[player_num]->green_cards.begin() + card_num);
			}
			else
			{
				this->players[this->turn]->red_cards.push_back(this->players[player_num]->red_cards[card_num]);
				this->players[player_num]->red_cards.erase(this->players[player_num]->red_cards.begin() + card_num);
			}

			cout << "Select Color to give: ";
			cin >> color_num;
			cout << endl;

			cout << "Select Card to give: ";
			cin >> card_num;
			cout << endl;

			if (color_num == 1)
			{
				this->players[player_num]->blue_cards.push_back(this->players[this->turn]->blue_cards[card_num]);
				this->players[this->turn]->blue_cards.erase(this->players[this->turn]->blue_cards.begin() + card_num);
			}
			else if (color_num == 2)
			{
				this->players[player_num]->green_cards.push_back(this->players[this->turn]->green_cards[card_num]);
				this->players[this->turn]->green_cards.erase(this->players[this->turn]->green_cards.begin() + card_num);
			}
			else
			{
				this->players[player_num]->red_cards.push_back(this->players[this->turn]->red_cards[card_num]);
				this->players[this->turn]->red_cards.erase(this->players[this->turn]->red_cards.begin() + card_num);
			}
		}
	}
	this->buy_propery();
}

// TODO: Allow buying of property
void Game::buy_propery()
{
	cout << "Coins after cards: " << this->players[this->turn]->bank->get_coins() << endl;
	cout << "Which property would you like to buy (n or 0-9)?" << endl;
	int selection;
	bool complete = false;
	while (!complete)
	{
		selection = this->player_input("Which property would you like to buy (n or 0-9)?");
		cout << endl;
		if (selection > 0)
		{
			int select = selection;
			if (Color::blue == this->slot[select][0]->get_color())
			{
				this->players[this->turn]->blue_cards.push_back((BlueCard*)this->slot[select].back());
				this->slot[select].pop_back();
				complete = true;
			}
			else if (Color::green == this->slot[select][0]->get_color())
			{
				this->players[this->turn]->green_cards.push_back((GreenCard*)this->slot[select].back());
				this->slot[select].pop_back();
				complete = true;
			}
			else if (Color::red == this->slot[select][0]->get_color())
			{
				this->players[this->turn]->red_cards.push_back((RedCard*)this->slot[select].back());
				this->slot[select].pop_back();
				complete = true;
			}
			else if (Color::purple == this->slot[select][0]->get_color())
			{
				bool purp = true;
				for (int i = 0; i < this->players[this->turn]->purple_cards.size(); i++)
				{
					if (this->slot[select].back()->get_name().compare(this->players[this->turn]->purple_cards[i]->get_name()) == 0)
					{
						cout << "You already have this establishment" << endl;
						purp = false;
					}
				}
				if (purp)
				{
					this->players[this->turn]->purple_cards.push_back((PurpleCard*)this->slot[select].back());
					this->slot[select].pop_back();
					complete = true;
				}
			}
			else if (Color::yellow == this->slot[select][0]->get_color())
			{
				//TODO: Implement buying mello yello
			}
			if (this->slot[select].size() == 0)
			{
				this->slot.erase(this->slot.begin() + select);
			}
		}
		else
		{
			break;
		}
	}
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
	if (this->players[this->turn - 1]->yellow_cards[2]->active)
	{
		turn--;
	}
	if (this->turn == players.size()) this->turn = 0;
	cout << " | " << this->turn << "'s turn next" << endl;
	return;
}