#include"card.h"
#include"normal.h"
#include"miss.h"
#include"reverse.h"
#include"colorswitch.h"
#include"colorswitchplusfour.h"
#include"drawtwo.h"

Card* getRandomCard() {
	char c; //kártya színe piros(p)/sárga(s)/zöld(z)/kék(k)/fekete_színválasztó(f)
	int n = rand() % 108; //108 kártya van az unoban, itt először eldöntjük, milyen színű legyen
	if (0 <= n && n < 4) { // 4 db színválasztó
		ColorSwitch* ret = new ColorSwitch;
		return ret;
	}
	else if (4 <= n && n < 8) { // 4 db +4 színválasztó
		ColorSwitchPlusFour* ret = new ColorSwitchPlusFour;
		return ret;
	}
	else if (8 <= n && n < 33) //piros
		c = 'p';
	else if (33 <= n && n < 58) //sárga
		c = 's';
	else if (58 <= n && n < 83) //zöld
		c = 'z';
	else //kék
		c = 'k';
	n = rand() % 25;
	if (n == 0) {
		Card* ret = new Normal;
		ret->setCardColor(c);
		ret->setCardNumber(0);
		return ret;
	}
	else if (n == 1 || n == 2) {
		Card* ret = new Normal;
		ret->setCardColor(c);
		ret->setCardNumber(1);
		return ret;
	}
	else if (n == 3 || n == 4) {
		Card* ret = new Normal;
		ret->setCardColor(c);
		ret->setCardNumber(2);
		return ret;
	}
	else if (n == 5 || n == 6) {
		Card* ret = new Normal;
		ret->setCardColor(c);
		ret->setCardNumber(3);
		return ret;
	}
	else if (n == 7 || n == 8) {
		Card* ret = new Normal;
		ret->setCardColor(c);
		ret->setCardNumber(4);
		return ret;
	}
	else if (n == 9 || n == 10) {
		Card* ret = new Normal;
		ret->setCardColor(c);
		ret->setCardNumber(5);
		return ret;
	}
	else if (n == 11 || n == 12) {
		Card* ret = new Normal;
		ret->setCardColor(c);
		ret->setCardNumber(6);
		return ret;
	}
	else if (n == 13 || n == 14) {
		Card* ret = new Normal;
		ret->setCardColor(c);
		ret->setCardNumber(7);
		return ret;
	}
	else if (n == 15 || n == 16) {
		Card* ret = new Normal;
		ret->setCardColor(c);
		ret->setCardNumber(8);
		return ret;
	}
	else if (n == 17 || n == 18) {
		Card* ret = new Normal;
		ret->setCardColor(c);
		ret->setCardNumber(9);
		return ret;
	}
	else if (n == 19 || n == 20) {
		Card* ret = new Miss;
		ret->setCardColor(c);
		return ret;
	}
	else if (n == 21 || n == 22) {
		Card* ret = new Reverse;
		ret->setCardColor(c);
		return ret;
	}
	else
	{
		Card* ret = new DrawTwo;
		ret->setCardColor(c);
		return ret;
	}
}