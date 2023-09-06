//#include"classes.h"
//
//bool Game::GameOver = true;
//
//Player::Player(string iname, Card* card, unsigned cardNumber = 7) : numberofCards(cardNumber) {
//	name = iname;
//	cards = new Card[cardNumber];
//	for (int i = 0; i < cardNumber; i++) {
//		cards[i].number = card[i].getCardNumber();
//		cards[i].type = card[i].getCardType();
//	}
//}
//
//Player::Player(unsigned cardNumber) : numberofCards(cardNumber), name("Default") {
//	cards = new Card[numberofCards];
//	for (int i = 0; i < numberofCards; i++) {
//		cards[i].getRandomCard();
//	}
//}
//
//Player::Player(Player& p)
//{
//	name = p.name;
//	numberofCards = p.numberofCards;
//	cards = new Card[numberofCards];
//	for (int i = 0; i < numberofCards; i++) {
//		cards[i] = p.cards[i];
//	}
//}
//
//void Card::operator=(Card b) {
//	number = b.number;
//	color = b.color;
//	type = b.type;
//}
//
//void Player::operator=(Player b) {
//	name = b.name;
//	numberofCards = b.numberofCards;
//	cards = new Card[numberofCards];
//	for (int i = 0; i < numberofCards; i++) {
//		cards[i] = b.cards[i];
//	}
//}
//
//Card Player::getCard(unsigned n) const {
//	if (n <= numberofCards)
//		return cards[n];
//	return 0;
//}
//
//Card::Card(char ptype, char pcolor, unsigned pnumber) {
//	setCardType(ptype);
//	setCardColor(pcolor);
//	setCardNumber(pnumber);
//}
//
//void Card::setCardNumber(unsigned n) {
//	if (n >= 0 || n <=10)
//		number = n;
//}
//void Card::setCardColor(char c) {
//	if (c == 'p' || c == 'z' || c == 's' || c == 'k' || c == 'f')
//		color = c;
//}
//void Card::setCardType(char t) {
//	if (t == 'd' || t == 'm' || t == 'r' || t == '+' || t == 'c')
//		type = t;
//}
//
//unsigned Card::getCardNumber() const {
//	return number;
//}
//
//char Card::getCardColor() const {
//	return color;
//}
//
//char Card::getCardType() const {
//	return type;
//}
//
//string Card::getCardColorS() const {
//	string c;
//	if (color == 'p')
//		c = "Piros";
//	else if (color == 'z')
//		c = "Zold";
//	else if (color == 's')
//		c = "Sarga";
//	else if (color == 'k')
//		c = "Kek";
//	else
//		c = "Szinv";
//	return c;
//}
//
//string Card::getCardTypeS() const {
//	string c;
//	if (type == 'd')
//		c = "Sima";
//	else if (type == 'm')
//		c = "Kimar";
//	else if (type == 'r')
//		c = "Fordul";
//	else if (type == '+')
//		c = "Huzz";
//	else
//		c = "Szinv";
//	return c;
//}
//
//void Card::drawCard() const {
//	cout << getCardType() << "		" << getCardColor() << "		" << getCardNumber()<<endl;
//}
//
//void Card::getRandomCard() {
//	int v = 0; //kártya számát vagy a felvendő kártyák számát mutatja
//	char c; //kártya színe piros(p)/sárga(s)/zöld(z)/kék(k)/fekete_színválasztó(f)
//	char t; //kártya típusa default(d)/miss(m)/reverse(r)/plus_two(+)/color_switch(c)
//	int n = rand() % 108; //108 kártya van az unoban, itt először eldöntjük, milyen színű legyen
//	if (0 <= n && n < 4) { // 4 db színválasztó
//		c = 'f';
//		t = 'c';//obj konstruktora
//		v = 0;
//	}
//	else if (4 <= n && n < 8) { // 4 db +4 színválasztó
//		c = 'f';
//		t = 'c';
//		v = 4;
//	}
//	else if (8 <= n && n < 33) //piros
//		c = 'p';
//	else if (33 <= n && n < 58) //sárga
//		c = 's';
//	else if (58 <= n && n < 83) //zöld
//		c = 'z';
//	else //kék
//		c = 'k';
//	if (c != 'f') { //kiválasztjuk, melyik kártya legyen, ha nem színválasztó
//		n = rand() % 25;
//		if (n == 0) {
//			t = 'd';
//			v = 0;
//		}
//		else if (n == 1 || n == 2) {
//			t = 'd';
//			v = 1;
//		}
//		else if (n == 3 || n == 4) {
//			t = 'd';
//			v = 2;
//		}
//		else if (n == 5 || n == 6) {
//			t = 'd';
//			v = 3;
//		}
//		else if (n == 7 || n == 8) {
//			t = 'd';
//			v = 4;
//		}
//		else if (n == 9 || n == 10) {
//			t = 'd';
//			v = 5;
//		}
//		else if (n == 11 || n == 12) {
//			t = 'd';
//			v = 6;
//		}
//		else if (n == 13 || n == 14) {
//			t = 'd';
//			v = 7;
//		}
//		else if (n == 15 || n == 16) {
//			t = 'd';
//			v = 8;
//		}
//		else if (n == 17 || n == 18) {
//			t = 'd';
//			v = 9;
//		}
//		else if (n == 19 || n == 20) {
//			t = 'm';
//			v = 0;
//		}
//		else if (n == 21 || n == 22) {
//			t = 'r';
//			v = 0;
//		}
//		else
//		{
//			t = '+';
//			v = 2;
//		}
//	}
//	number = v;
//	color = c;
//	type = t;
//}
//
//Game::Game() { GameOver = false; playercount = 0; players = nullptr; topcard.getRandomCard(); }
//void Game::gameplay()
//{
//}
//;
//Game::~Game() {
//	delete[] players;
//}
//
//void Game::init_game() {
//	//Player** newptr = (Player**)malloc(sizeof(Player**) * (2));
//	//Player** newptr = new Player*[2];
//	playercount = 2;
//	players = new Player[playercount];
//	cout << "Elso jatekos neve:" << endl;
//	cin >> players[0].name;
//	cout << "Masodik jatekos neve:" << endl;
//	cin >> players[1].name;
//	while (true) {
//		cout << "Szeretnel meg jatekosokat hozzaadni? (y/n)" << endl;
//		char ans;
//		cin >> ans;
//		if (ans == 'y' || ans == 'Y') {
//			newPlayer();
//		}
//		else if (ans == 'n' || ans == 'N')
//			break;
//	}
//}
//
//void Game::newPlayer() { 
//	Player* newplayers = new Player[playercount + 1];
//	for (int i = 0; i < playercount; i++) {
//		newplayers[i] = players[i];
//	}
//	delete[] players;
//	players = newplayers;
//	cout << "Jatekos neve:" << endl;
//	cin >> players[playercount].name;
//	playercount++;
//}
//
//void Game::gameplay() {
//	do {
//		;
//	} while (GameOver == false);
//}