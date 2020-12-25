/*
* Name: Mansi Patel
*/

#ifndef CARDDECK_H
#define CARDDECK_H

#include <iostream>
#include <iomanip> 
#include <string>
#include <vector>
#include <stack> 
#include <time.h>
#include <math.h>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

const int SUIT_SIZE = 4;
const int RANK_SIZE = 9;

class CardDeck
{
public:
	struct Card {
		string rank;
		string suit;
	} cardStruct;

	vector <CardDeck::Card> vectorOfDeck;	//vector of deck
	stack <CardDeck::Card> stackOfDeck;		//stack of deck

	CardDeck();
	int rnd_num(int, int);
	void createDeck(int);
	void createTempDeck();
	int searchDeck(int);
	void deleteDeck();
	bool displayDeletedCardDeck();
	void displayDeck();
	void addNewCardToDeck();
	void addDeletedCardToDeck(int);
	void deleteCardFromDeck();
	void normalShuffle();
	void cutShuffle(int);
};


#endif