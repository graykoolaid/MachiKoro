#pragma once

#include <string>
#include "ColorAndIcon.h"
#include "Player.h"

using namespace std;
namespace machi {
	class Card {
	public:
		virtual void action(Player *p1, Player *p2, Card *c1, Card *c2, int val) = 0;
		void set_cost(int cost);
		void set_value(int value);
		void set_color(Color color);
		void set_name(string name);
		void set_renovation(bool renovation);
		void set_low_roll(int low);
		void set_high_roll(int high);
		void set_icon(Icon icon);
		void set_card(string name, int value, int cost, int low_roll, int high_roll, Icon icon);

		int get_value();
		int get_cost();
		Color get_color();
		Icon get_icon();
		bool get_renovation();
		string get_name();

	private:
		int low_roll;
		int high_roll;
		int cost;
		int value;
		Color color;
		Icon icon;
		bool renovation;
		string name;

	};
}