#pragma once
#include "include.h"
#include"card.h"
#include"normal.h"
#include"miss.h"
#include"reverse.h"
#include"colorswitch.h"
#include"colorswitchplusfour.h"
#include"drawtwo.h"
#include"player.h"
#include <chrono>
#include <thread>
class Game {
	friend Card;
	friend ColorSwitch;
	friend ColorSwitchPlusFour;
	friend DrawTwo;
	friend Miss;
	friend Reverse;
protected:
	static bool GameOver;
	static bool order; //a kor iranyat hatarozza meg
	static char topcolor; //azert kell, mert a szinvalasztonal meghat. egy uj szint, ami nem a szinvalaszto ('f'=fekete) szine
	unsigned playercount;
	Player* playersHead;
	Player* lastP;
	Player* currentP;
	Card* topcard;
public:
	Game();
	~Game();
	static char getTopColor();
	static string getTopColorS();
	static void setTopColor(char c);
	void init_game();
	void newPlayer();
	void gameplay();
	void advance();
	void switchOrder();
	void colorswitchAction();
	void colorswitchplusfourAction();
	void playCard();
};
