#include "game.h"
#include "player.h"
#include "card.h"
#include <iostream>
#include "colorswitch.h"
#include "colorswitchplusfour.h"
#include "miss.h"
#include "normal.h"
#include "drawtwo.h"
#include "reverse.h"

int main() 
{
	srand(time(0));
	Game Uno;
	Uno.init_game();
	Uno.gameplay();
}