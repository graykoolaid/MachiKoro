// MachiKoro.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

#include "Deck.h"

using namespace std;

int main()
{
	Deck *d = new Deck();
//	Players *p = new Player();

	cout << d->deck.size() << endl;

	char t;
	cin >> t;
    return 0;
}

