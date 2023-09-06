#pragma once
#include "include.h"
#include"card.h"
#include<vector>
#include<iostream>

using namespace std;

class Player {
protected:
	string name;
	vector< Card* > cards;
	Player* Next;
	Player* Prev;
public:
	friend class Game;
	Player(string iname, vector< Card* > card, unsigned cardNumber);
	Player(unsigned cardNumber = 7);
	~Player() { //Next és Prev playerek csak pointerek, torli oket a game destruktora
		for (int i = 0; i < cards.size(); i++) { //cards pointereibol ramutatott helyek torlese
			delete cards[i];
		}
		cards.clear(); //cards torlese
	}
	unsigned cardnumber();
	void displayCards();
	void displayName();
	void newCard();
};