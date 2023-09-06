//#pragma once
//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//
//using namespace std; //külön .h .cpp
//
//class Card {
//protected:
//	unsigned number;
//	char color;
//	char type;
//public:
//	friend class Player;
//	Card(char type = 'd', char color = 'f', unsigned number = 0);
//	void setCardNumber(unsigned n);
//	void setCardColor(char c);
//	void setCardType(char t);
//	unsigned getCardNumber() const;
//	char getCardColor() const;
//	char getCardType() const;
//	string getCardColorS() const;
//	string getCardTypeS() const;
//	void drawCard() const;
//	void getRandomCard();
//	void operator=(Card b);
//	virtual void cardAction() { cout << "Nope"; }
//};
//class Player {
//protected:
//	string name;
//	unsigned numberofCards;
//	Card* cards;
////	vector<Card> r;
//public:
//	friend class Game;
//	Player(string iname, Card* card, unsigned cardNumber);
//	Player(unsigned cardNumber=7);
//	Player(Player& p);
//	~Player() {
//		if(cards!=nullptr)
//		delete[] cards;
//	}
//	Card getCard(unsigned n) const;
//	void operator=(Player b);
//};
//
//class Game {
//	static bool GameOver;
//	unsigned playercount;
//	Player* players;
//	Player* currentP;
//	Card topcard;
//public:
//	Game();
//	~Game();
//	void init_game();
//	void newPlayer();
//	void gameplay();
//};