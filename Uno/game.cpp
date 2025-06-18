#include"game.h"
#include"card.h"
#include"player.h"
#include<iostream>

using namespace std;

bool Game::GameOver = false;
bool Game::order = true;
char Game::topcolor = 'f';

Game::Game() {
	playercount = 0;
	playersHead = nullptr;
	currentP = nullptr;
	lastP = nullptr;
	topcard = getRandomCard();
	order = true;
	topcolor = topcard->getCardColor();
}

Game::~Game() { //playersHead torolve lesz, nem kell kulon kiirni a torleset
	//lastP = currentP->Prev;
	//while (currentP != lastP) {
	//	Player* tmp = currentP->Next;
	//	currentP->~Player();
	//	currentP = tmp;
	//}
	//lastP->~Player();
	delete topcard;
	lastP = currentP->Prev;
	while (currentP != lastP) {
		Player* tmp = currentP->Next;
		delete currentP;
		currentP = tmp;
	}
	delete lastP;
	//cout << "hey";
}

void Game::init_game() {
	playercount = 2;
	playersHead = new Player;
	Player* p2 = new Player;
	playersHead->Next = p2;
	playersHead->Next->Prev = playersHead;
	currentP = playersHead->Next;
	cout << "Elso jatekos neve:" << endl;
	cin >> playersHead->name;
	cout << "Masodik jatekos neve:" << endl;
	cin >> playersHead->Next->name;
	cout << "Szeretnel meg jatekosokat hozzaadni? (y/n)" << endl;
	while (true) {
		char ans;
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			newPlayer();
			cout << "Szeretnel meg jatekosokat hozzaadni? (y/n)" << endl;
		}
		else if (ans == 'n' || ans == 'N')
		{
			lastP = currentP;
			currentP->Next = playersHead;
			playersHead->Prev = currentP;
			currentP = playersHead;
			break;
		}
		else
			cout << "Ervenytelen bemenet. Irj y-t, ha szeretnel meg jatekosokat, n-t, hogyha kezdodhet a jatek." << endl;
	}
}

void Game::newPlayer() {
	Player* newp = new Player;
	newp->Prev = currentP;
	currentP->Next = newp;
	currentP = currentP->Next;
	cout << "Jatekos neve:" << endl;
	cin >> currentP->name;
	playercount++;
}

bool canitbeplaced(Card* next, Card* top, Game* uno) {
	if (next->getCardType() == 'c' || next->getCardType() == '4') //szinvalasztot mindig lehet rakni
		return true;
	if (next->getCardType() == top->getCardType() && top->getCardType() != 'n') //ha egyezik a tipus, de nem sima kartya, akokr mindig lehet rakni
		return true;
	if (uno->getTopColor() == 'f' || next->getCardColor() == uno->getTopColor()) //uno->getTopColor() == 'f' csakis akkor lehet, ha fordul a kor a legelso random gen. kartya, fordul a kor lerakasnal szint hataroz meg a lerako
		return true;
	if (top->getCardType() == 'n' && next->getCardType() == 'n' && next->getCardNumber() == top->getCardNumber()) //ha a szam egyezik
		return true;
	return false;
}

void Game::advance() {
	if(order)
		currentP = currentP->Next;
	else
		currentP = currentP->Prev;
}

void Game::switchOrder() {
	if (order)
		order = false;
	else
		order = true;
}

void Game::colorswitchAction() {
	cout << "Milyen szint szeretnel? (p=piros; z=zold; s=sarga; k=kek)" << endl;
	char c;
	while (true) {
		cin >> c;
		if (c == 'p' || c == 'z' || c == 's' || c == 'k') {
			setTopColor(c);
			break;
		}
		cout << "Ervenytelen szin. Probald ujra. (p=piros; z=zold; s=sarga; k=kek)" << endl;
	}
	system("CLS"); //kepernyo torles innentol-
	cout << "Kovetkezo szin: " << this->getTopColorS();
	this_thread::sleep_for(std::chrono::milliseconds(2500)); //idaig output informacio a jatekokosnak / alszik 2.5s-ig
}

void Game::colorswitchplusfourAction() {
	if (order) {
		for (int i = 0; i < 4; i++)
			currentP->Next->newCard();
	}
	else {
		for (int i = 0; i < 4; i++)
			currentP->Prev->newCard();
	}
	colorswitchAction();

	cout << endl; //innentol-
	if (order)
		currentP->Next->displayName();
	else
		currentP->Prev->displayName();
	cout << " felhuzott 4 lapot.";
	this_thread::sleep_for(std::chrono::milliseconds(2500)); //idaig output informacio a jatekokosnak / alszik 2.5s-ig

	advance();
}

void Game::playCard() {
	int szam;
	while (!(cin >> szam)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while (1 <= szam && szam <= currentP->cards.size()) { //amig ervenyes a bemenet, de esetleg nem lehet lerakni, akkor ebben a loopban porog a jatekos.
		szam--; //ez azert van, mert a kartya kiiratasnal 1-tol kezdodnek a kartyak.
		if (canitbeplaced(currentP->cards[szam], topcard, this)) { //ha le lehet rakni a kartyat, akkor ez lefut, vegen kilep a fuggvenybol
			delete topcard;
			topcard = currentP->cards[szam];
			setTopColor(currentP->cards[szam]->getCardColor()); //lerakott kartya szine == legfelso szinnel
			currentP->cards.erase(currentP->cards.begin() + szam);
			if (currentP->cards.size() == 0) { //ha nem maradt lapja, akkor gameover
				Game::GameOver = true;
				return;
			}
			if (topcard->getCardType() == 'c') //kartya hatasok innentol**
				colorswitchAction();
			else if (topcard->getCardType() == '4') // -||-
				colorswitchplusfourAction();
			else if (topcard->getCardType() == '+') {

				system("CLS"); //kepernyo torles innentol-
				if (order)
					currentP->Next->displayName();
				else
					currentP->Prev->displayName();
				cout << " felhuzott 2 lapot.";
				this_thread::sleep_for(std::chrono::milliseconds(2500)); //idaig output informacio a jatekokosnak / alszik 2.5s-ig

				if (order) {
					currentP->Next->newCard();
					currentP->Next->newCard();
				}
				else {
					currentP->Prev->newCard();
					currentP->Prev->newCard();
				}
				advance();
			}
			else if (topcard->getCardType() == 'm') {

				system("CLS"); //kepernyo torles innentol-
				if (order)
					currentP->Next->displayName();
				else
					currentP->Prev->displayName();
				cout << " kimarad.";
				this_thread::sleep_for(std::chrono::milliseconds(2500)); //idaig output informacio a jatekokosnak / alszik 2.5s-ig

				advance();
			}
			else if (topcard->getCardType() == 'r') { //**idaig

				system("CLS"); //kepernyo torles innentol-
				cout << "Fordul a kor.";
				this_thread::sleep_for(std::chrono::milliseconds(2500)); //idaig output informacio a jatekokosnak / alszik 2.5s-ig

				switchOrder();
			}
			advance(); //vegen a kov. jatekos jon
			return; //kilep a fuggvenybol
		}
		else {
			cout << "Ezt a kartyat nem tudod lerakni, probalkozz masikkal, vagy huzz egy lapot." << endl; //ha ervenyes szamot irt, de nem lehet rarakni az elozo kartyara, ujra kerunk tole szamot
			while (!(cin >> szam)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}
	currentP->newCard(); //ha nem jo lap, akkor huz egyet
	advance(); //vegen a kov. jatekos jon
}

void Game::gameplay() {
	do {
		system("CLS"); //kepernyo torles
		cout << "Mostani jatekos:" << endl;
		currentP->displayName(); //nev kiiratas
		cout << endl << endl;
		currentP->displayCards(); //kartyak kiiratasa, elso elem 1-es, nem 0-as szamu
		cout << endl << endl;
		cout << "Legfelso kartya: " << endl;
		this->topcard->drawCard();
		cout << endl;
		cout << "Elfogadhato szin: (" << this->getTopColor()<<")="<<this->getTopColorS();
		cout << endl << endl;
		cout << "Kovetkezo jatekos: ";
		if (order)
			currentP->Next->displayName();
		else
			currentP->Prev->displayName();
		cout << endl;
		cout << "Kartyainak szama: ";
		if (order)
			cout << currentP->Next->cardnumber() << endl << endl;
		else
			cout << currentP->Prev->cardnumber() << endl << endl;
		cout << "Melyik kartyat szeretned kijatszani?	(a kartya szamat ird le, vagy ha huzni akarsz, irj ervenytelen szamot.)" << endl;
		playCard();
	} while (GameOver==false);
	system("CLS"); //kepernyo torles
	cout << "Nyert ";
	currentP->displayName();
	cout << "!" << endl;
}

char Game::getTopColor() {
	return topcolor;
}

string Game::getTopColorS() {
	string c;
	if (getTopColor() == 'p')
		c = "Piros";
	else if (getTopColor() == 'z')
		c = "Zold";
	else if (getTopColor() == 's')
		c = "Sarga";
	else if (getTopColor() == 'k')
		c = "Kek";
	else if (getTopColor() == 'f')
		c = "Fekete (Minden johet)";
	else
		c = "Error";
	return c;
}

void Game::setTopColor(char c) {
	topcolor = c;
}
