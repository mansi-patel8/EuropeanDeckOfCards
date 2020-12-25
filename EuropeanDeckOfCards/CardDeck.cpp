/*
* Name: Mansi Patel
*/

#include "CardDeck.h" 

string suits[SUIT_SIZE] = { "Clubs","Diamonds","Hearts","Spades" };
string ranks[RANK_SIZE] = { "6","7","8","9","10","Joker","Queen","King", "Ace" };

vector <CardDeck::Card> tempvectorOfDeck;		//temporary vector of deck to hold all 36 cards
stack <CardDeck::Card> tempstackOfDeck;			//temporary stack of deck to hold all 36 cards 
vector <CardDeck::Card> vectorOfDeletedCards;	//vector of deck of deleted cards
stack <CardDeck::Card> stackOfDeletedCards;		//stack of deck  of deleted cards

/// <summary>
/// Method Name:rnd_num(int MIN, int MAX)
/// Purpose: This method will create the random numbers between MIN and MAX value 
/// </summary>
/// <param name="MIN"></param>
/// <param name="MAX"></param>
/// <returns></returns>
int CardDeck::rnd_num(int MIN, int MAX) {
	random_device rd;
	default_random_engine rng(rd());
	uniform_int_distribution<int> dist(MIN, MAX);
	return dist(rng);
}

/// <summary>
/// Method Name:CardDeck
/// Purpose: This is a default constructor of the class. This will create temp deck.
/// </summary>
/// <returns></returns>
CardDeck::CardDeck()
{
	//creating the temporary deck
	createTempDeck();
}

/// <summary>
/// Method Name:createDeck()
/// Purpose: This method will create the temperarory deck with all 36 cards. 
/// </summary>
void CardDeck::createTempDeck()
{
	if (stackOfDeck.empty() && vectorOfDeck.empty())
	{
		//this for loop will create the temp deck with 36 cards 
		for (int i = 0; i < SUIT_SIZE; i++)
		{
			cardStruct.suit = suits[i];
			for (int j = 0; j < RANK_SIZE; j++)
			{
				cardStruct.rank = ranks[j];
				//pushing the cardStruct in temstackOfDeck
				tempstackOfDeck.push(cardStruct);

				//pushing the cardStruct in tempvectorOfDeck
				tempvectorOfDeck.push_back(cardStruct);
			}
		}
	}
}

/// <summary>
/// Method Name:searchDeck(int newRandom)
/// Purpose: This method will goes through the vectorOfDeck and return -1 if the card already exists in the deck otherwise it returns 0. 
/// </summary>
/// <param name="newRandom"></param>
/// <returns></returns>
int CardDeck::searchDeck(int newRandom)
{
	for (int i = 0; i < vectorOfDeck.size(); i++)
	{
		//check if card exists
		if (vectorOfDeck[i].rank == tempvectorOfDeck[newRandom].rank && vectorOfDeck[i].suit == tempvectorOfDeck[newRandom].suit)
		{
			return -1;
		}
	}
	return 0;
}

/// <summary>
/// Method Name:createDeck(int noCardsForDeck)
/// Purpose: This method will create the deck with x (userinput = noCardsForDeck) cards. 
/// </summary>
/// <param name="noCardsForDeck"></param>
void CardDeck::createDeck(int noCardsForDeck)
{
	//if the deck is already created cannnot create new one - just add new cards in the deck
	if (!vectorOfDeck.empty())
	{
		cout << "Sorry, the deck has been created already, you cannot create a new deck." << endl;
	}
	else
	{
		int newRandom = 0;	//varible to hold the random number for the card to be added in the deck 
		int cardFlag = -1;	//flag to check if the card already exists in the deck or not
		int m = 0; //while loop counter

		//this while loop will create the deck with the number of cards specified by user randomly from the temp deck 
		while (m < noCardsForDeck)
		{
			//generate the random numbers between 1,36
			newRandom = rnd_num(0, 35);

			//check if card exists in the system
			cardFlag = searchDeck(newRandom);

			//if card does not exist in the deck
			if (cardFlag == 0)
			{
				vectorOfDeck.push_back(tempvectorOfDeck[newRandom]);
				m++;
			}
		}

		//this for loop will copy the data from vector to stack
		for (int n = 0; n < vectorOfDeck.size(); n++)
		{
			stackOfDeck.push(vectorOfDeck[n]);
		}
		cout << "Successfully created the European deck of cards." << endl;
		cout << "Size of Deck is: " << stackOfDeck.size() << endl;
		cout << "Deck top is : " << stackOfDeck.top().rank << " of " << stackOfDeck.top().suit << endl;
	}
}

/// <summary>
/// Method Name: deleteDeck()
/// Purpose: This method will delete all the cards from the deck.
/// </summary>
void CardDeck::deleteDeck()
{
	//error checking to see if deck is empty or not 
	if (stackOfDeck.empty() && vectorOfDeck.size() <= 0)
	{
		cout << "Cannot destroy the deck because it is empty." << endl;
	}
	else
	{
		cout << "Deleting the European deck of cards." << endl;

		//deleting the stackOfDeck
		while (!stackOfDeck.empty())
		{
			stackOfDeck.pop();
		}

		//deleting the vectorOfDeck
		while (!vectorOfDeck.empty())
		{
			vectorOfDeck.clear();
		}
		cout << "Successfully deleted the European deck of cards." << endl;
	}
}

/// <summary>
/// Method Name: displayDeletedCardDeck()
/// Purpose: This method will display the cards deleted by user from the original deck from bottom to top. This method return true value if the deck is not empty, otherwise will retun false.
/// </summary>
bool CardDeck::displayDeletedCardDeck()
{
	//check if the cards has been deleted
	if (!vectorOfDeletedCards.empty())
	{
		cout << "Printing the deleted cards from the deck in reverse order (from bottom to top)." << endl;
		cout << "The deleted European deck of cards has: " << vectorOfDeletedCards.size() << " cards in the deck right now." << endl;

		//displaying deck of cards from bottom to top
		for (int k = 0; k < vectorOfDeletedCards.size(); k++)
		{
			cout << "[" << k << "] " << vectorOfDeletedCards[k].rank << " of " << vectorOfDeletedCards[k].suit << endl;
		}
		return true;
	}
	else
	{
		cout << "No card has been deleted. Please try again later." << endl;
		return false;
	}
}

/// <summary>
/// Method Name: displayDeck()
/// Purpose: This method will display the original deck of cards from bottom to top.
/// </summary>
void CardDeck::displayDeck()
{
	if (!vectorOfDeck.empty())
	{
		cout << "The European deck of cards has: " << vectorOfDeck.size() << " cards in the deck right now." << endl;
		cout << "Printing the deck of cards in reverse order (from bottom to top)." << endl;

		//displaying deck of cards from bottom to top
		for (int k = 0; k < vectorOfDeck.size(); k++)
		{
			cout << "[" << k << "] " << vectorOfDeck[k].rank << " of " << vectorOfDeck[k].suit << endl;
		}
	}
	else
	{
		cout << "The deck is empty right now. Please try again later." << endl;
	}
}

/// <summary>
/// Method Name: addNewCardToDeck()
/// Purpose: This method will add a new card in the deck which doesnot exist in the deck, if exists it will throw an error.
/// </summary>
void CardDeck::addNewCardToDeck()
{
	cout << "The size of the deck before addition is: " << stackOfDeck.size() << endl;
	cout << "Adding the card on top the deck." << endl;

	int newRandom = 0;	//varible to hold the random number for the deck 
	int cardFlag = -1;

	//this for loop will create the deck with the number of cards specified by user randomly from the temp deck 
	if (vectorOfDeck.size() < 36)
	{
		newRandom = rnd_num(0, 35);

		//check if randomly picked card already exists in the deck 
		cardFlag = searchDeck(newRandom);

		//if card not found add in the deck otherwise throw an error
		if (cardFlag == 0)
		{
			vectorOfDeck.push_back(tempvectorOfDeck[newRandom]);
		}
		else
		{
			cout << "Sorry could not add duplicate card in the deck. Please try again." << endl;
		}
	}

	//clearing stack because cannot add element by index in stack! :(
	while (!stackOfDeck.empty())
	{
		stackOfDeck.pop();		//clearing stake
	}

	//this for loop will copy the data from vector to stack with newly added card
	for (int n = 0; n < vectorOfDeck.size(); n++)
	{
		stackOfDeck.push(vectorOfDeck[n]);
	}

	cout << "Successfully added the new card in the European deck of cards." << endl;
	cout << "Size of Deck is: " << stackOfDeck.size() << endl;
	cout << "Deck top is : " << stackOfDeck.top().rank << " of " << stackOfDeck.top().suit << endl;
}

/// <summary>
/// Method Name: addDeletedCardToDeck(int deleteCardNum)
/// Purpose: This method will add a previously deleted card in the deck, specified by user.
/// </summary>
/// <param name="deleteCardNum"></param>
void CardDeck::addDeletedCardToDeck(int deleteCardNum)
{
	cout << "The size of the deck before addition is: " << stackOfDeck.size() << endl;
	cout << "Adding the card on top the deck." << endl;
	bool foundCard = false;

	//check if user specified card exists in the system
	for (int i = 0; i < vectorOfDeletedCards.size(); i++)
	{
		if (vectorOfDeletedCards[i].rank == vectorOfDeletedCards[deleteCardNum].rank &&
			vectorOfDeletedCards[i].suit == vectorOfDeletedCards[deleteCardNum].suit)
		{
			foundCard = true;
			break;
		}
	}

	//only add the card back in the deck if it is not full
	if (vectorOfDeck.size() < 36)
	{
		if (foundCard == true)
		{
			//adding the specified card back in the deck
			vectorOfDeck.push_back(vectorOfDeletedCards[deleteCardNum]);

			//removing the same from the vectorOfDeletedCards, so can't be added back
			vectorOfDeletedCards.erase(vectorOfDeletedCards.begin() + deleteCardNum);

			//clearing stack because cannot add element by index in stack! :(
			while (!stackOfDeck.empty())
			{
				stackOfDeck.pop();		//clearing stake
			}

			//pushing newly added cards vector in the stack 
			for (int y = 0; y < vectorOfDeck.size(); y++)
			{
				stackOfDeck.push(vectorOfDeck[y]);
			}

			cout << "Successfully added the card on top the deck." << endl;
			cout << "The size of the deck after adding new card is: " << stackOfDeck.size() << endl;
		}
		else
		{
			cout << "Sorry could not add the entered card in the deck, please try again." << endl;
		}
	}
	else
	{
		cout << "Sorry could not add the entered card in the deck, exceed the deck size." << endl;
	}
}

/// <summary>
/// Method Name:deleteCardFromDeck
/// Purpose: This method will delete top card from the deck.
/// </summary>
void CardDeck::deleteCardFromDeck()
{
	if (!stackOfDeck.empty() && !vectorOfDeck.empty())
	{
		cout << "The size of the deck before deletion is: " << stackOfDeck.size() << endl;
		cout << "Deleting the top card from the deck." << endl;

		if (!stackOfDeck.empty())
		{
			cout << "The top card on the deck is: ";
			cout << stackOfDeck.top().rank << " of " << stackOfDeck.top().suit << endl;

			//pushing the last/top card to the stackOfDeletedCards stak if user wants to add it back later
			stackOfDeletedCards.push(stackOfDeck.top());

			//deleting the top card from stack
			stackOfDeck.pop();

		}
		if (!vectorOfDeck.empty())
		{
			//pushing the last/top card to the vectorOfDeletedCards vector if user wants to add it back later
			vectorOfDeletedCards.push_back(vectorOfDeck.back());

			//deleting the top card from vector
			vectorOfDeck.pop_back();
		}

		cout << "Successfully deleted the top card from the deck." << endl;
		cout << "The size of the deck after deletion is: " << stackOfDeck.size() << endl;
		//cout << "The top card in the deck after deletion is: " << stackOfDeck.top().rank << " of " << stackOfDeck.top().suit << endl;
	}
	else
	{
		cout << "Sorry the deck is empty. Cannot delete the card from the deck. Please try again after creating the deck!" << endl;
	}
}

/// <summary>
/// Method Name: normalShuffle()
/// Purpose: This method will shuffle the cards. In this case it will sepcifically reverse the cards in the deck.
/// </summary>

void CardDeck::normalShuffle()
{
	if (!vectorOfDeck.empty() && !stackOfDeck.empty())
	{
		cout << "The size of the deck before shuffle is: " << stackOfDeck.size() << endl;
		cout << "The top card on the deck before shuffle is: " << stackOfDeck.top().rank << " of " << stackOfDeck.top().suit << endl;

		while (!stackOfDeck.empty())
		{
			stackOfDeck.pop();		//clearing stake
		}

		for (int i = 0; i < vectorOfDeck.size(); i++)
		{
			// Random for remaining positions. 
			int r = i + (rand() % (vectorOfDeck.size() - i));

			swap(vectorOfDeck[i], vectorOfDeck[r]);
		}
		
		//pushing shaffled vector in the stack 
		for (int y = 0; y < vectorOfDeck.size(); y++)
		{
			stackOfDeck.push(vectorOfDeck[y]);
		}

		cout << "Successfully shuffled the deck of cards." << endl;
		cout << "The size of the deck after shuffle is: " << stackOfDeck.size() << endl;
		cout << "The top card on the deck after shuffle is: " << stackOfDeck.top().rank << " of " << stackOfDeck.top().suit << endl;

	}
	else
	{
		cout << "Sorry the deck is empty. Cannot shuffle the deck. Please try again after creating the deck!" << endl;
	}
}

/// <summary>
/// Method Name: cutShuffle(int cutIndex)
/// Purpose: This method will shuffle the deck of cards using cut method. Here, it will divided into two decks. First deck will have (s-n) cards and second deck will have n cards and they will merged as one as second deck is at the bottom and the first deck is put on top of it.
/// </summary>
/// <param name="cutIndex"></param>
void CardDeck::cutShuffle(int cutIndex)
{
	//check if vector is empty
	if (!vectorOfDeck.empty() && cutIndex > 0 && cutIndex < vectorOfDeck.size())
	{
		//n to s elements pushing to splitOneVector 
		vector <CardDeck::Card> splitOneVector(vectorOfDeck.begin() + cutIndex, vectorOfDeck.end());

		//0 to n elements pushing to splitTwoVector 
		vector <CardDeck::Card> splitTwoVector(vectorOfDeck.begin(), vectorOfDeck.begin() + cutIndex);

		//emptying vectorOfDeck to add the split-vectors
		while (!vectorOfDeck.empty())
		{
			vectorOfDeck.clear();	//clearning vector
		}
		while (!stackOfDeck.empty())
		{
			stackOfDeck.pop();		//clearing stake
		}

		//inserting deck 1 on top
		vectorOfDeck.insert(vectorOfDeck.end(), splitOneVector.begin(), splitOneVector.end());

		//inserting deck 2 in the bottom
		vectorOfDeck.insert(vectorOfDeck.end(), splitTwoVector.begin(), splitTwoVector.end());

		//pushing shaffled vector in the stack 
		for (int y = 0; y < vectorOfDeck.size(); y++)
		{
			stackOfDeck.push(vectorOfDeck[y]);
		}

		cout << "Successfully shuffled the cards! Please print it to see the new order of the cards." << endl;
	}
	else
	{
		cout << "The deck should not be empty and the cut index has to be greater than 0 and less than deck size. Please try again." << endl;
	}
}