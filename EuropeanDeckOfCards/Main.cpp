/*
* Name: Mansi Patel
* Problem: Implement a program to simulate a typical European deck of cards. This program shoudl be able to create (with user specified cards), delete and display the deck. It should be able to also do regular shuffle (reverse the deck) and cut shuffle. This program should be able to add the unique cards in the deck and also allow the users to add the delete cards back in the deck.
* Pseducode:
			- create a menu system
			- create the deck
				- create the deck with user specified number of cards which are unique
				- cannot create the deck if the deck has been created already
			- delete the deck
				- delete all the cards from the deck
			- display the deck
				- display the deck from top(0) to bottom (n)
			- add the cards in the deck
				- add the deleted card
					- check if there are any cards deleted by user and only add if the card is not full and it doesnot already exists in the deck
				- add new card
					- add the new card in the deck which doesnot exists in the deck
			- delete the cards from the deck
				- delete the top(n) card from the deck
			- shuffle the deck
				- regular shuffle
					- reverse the card order in the deck
				- cut shuffle
					- perform cut shuffle on the deck of cards with user speicified number of the card
*/

#include "CardDeck.h"

int main()
{
	//creating class object
	CardDeck newCardDeck;

	bool programFlag = true;		//this flag will keep the program going unless user enters 5 to stop it
	int menuOption;					//userinput for the main menu
	int noCardsForDeck = 0;			//number of cards the decck
	int cutIndex = 0;				//at which card you would like to cut the deck
	int addSubOption = 0;			//adding cards menu sub option for userinput
	int deleteCardNum = 0;			//userinput to specify which deleted card user wants to add back in the deck

	while (programFlag)
	{
		cout << "Welcome!" << endl;
		cout << "Please select one of the following options:" << endl;
		cout << "1. Create the deck of cards." << endl;
		cout << "2. Delete the deck of cards." << endl;
		cout << "3. Display the deck of cards. " << endl;
		cout << "4. Add the new card to the deck." << endl;
		cout << "5. Remove the card from the deck." << endl;
		cout << "6. Shuffle the deck." << endl;
		cout << "7. Shuffle the deck by cutting it into two." << endl;
		cout << "8. Exit the program" << endl;
		cin >> menuOption;

		switch (menuOption)
		{
		case 1:																						//Create Deck Of Cards
			//userinput for how many cards user wants in the deck
			cout << "How many cards of deck, you would like to create? : ";
			cin.ignore(INT_MAX, '\n');
			cin >> noCardsForDeck;
			//error check for correct noCardsForDeck
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Incorrect input value! Please Try again: ";
				cin >> noCardsForDeck;
			}

			//userinput for noCardsForDeck cannot be <= 0 or > 36
			if (noCardsForDeck <= 0 || noCardsForDeck > 36)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "The max size of European deck is 36 and minimum is 1." << endl;
				cout << "Please try again.: ";
				cin >> noCardsForDeck;
			}
			else
			{
				//calling createDeck(noCardsForDeck) method
				newCardDeck.createDeck(noCardsForDeck);
			}
			break;
		case 2: 																					//Delete Deck Of Cards
			//calling deleteDeck() method
			newCardDeck.deleteDeck();
			break;
		case 3:																				     	//Print Deck Of Cards
			//calling displayDeck() method
			newCardDeck.displayDeck();
			break;
		case 4: 																					//Add the card to the deck			
			//user input for adding new card sub menu 
			cout << "Would you like to add the card you delete before or new one?" << endl;
			cout << "1. To add the deleted card" << endl << "2. To new card: " << endl;
			cin.ignore(INT_MAX, '\n');
			cin >> addSubOption;

			//error check for correct addSubOption
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Incorrect input value! Please Try again: ";
				cin >> addSubOption;
			}

			//add the previously deleted card from the deck back in the deck
			if (addSubOption == 1)
			{
				//check if there are any cards deleted from the deck yet
				bool deleteDeckExists = false;

				//calling displayDeletedCardDeck() method
				deleteDeckExists = newCardDeck.displayDeletedCardDeck();

				//if deleteCardsDeck exists then ask userinput for which one to be added back in the deck
				if (deleteDeckExists == true)
				{
					cout << "Which card you would like to delete from above, please enter the number: " << endl;
					cin >> deleteCardNum;

					//error check for correct deleteCardNum
					while (cin.fail())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "Incorrect input value! Please Try again: ";
						cin >> deleteCardNum;
					}
					//calling addDeletedCardToDeck(deleteCardNum) method
					newCardDeck.addDeletedCardToDeck(deleteCardNum);
				}
				else
				{
					cout << "You haven't deleted any cards yet, please delete the card first and then try to add it back." << endl;
				}

			}
			else if (addSubOption == 2)			//add a brand new card in the deck
			{
				//calling addNewCardToDeck() method
				newCardDeck.addNewCardToDeck();
			}
			else
			{
				cout << "Incorrect Input. Please try again." << endl;
				break;
			}
			break;
		case 5: 																					//Remove the card from the deck
			//calling deleteCardFromDeck() method
			newCardDeck.deleteCardFromDeck();
			break;
		case 6: 																					//Shuffle the deck
			//calling normalShuffle()
			newCardDeck.normalShuffle();
			break;
		case 7: 																					//Shuffle the deck by 'Cut'		
			//user input, at which card user wants to cut the deck from
			cout << "Please provide at which card you would like to do the cut." << endl;
			cout << "Note: The cut index has to be greater than 0 and less than deck size." << endl;
			cout << "Now please enter the index where you would like to cut the deck : ";
			cin >> cutIndex;
			//error check for correct cutIndex
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Incorrect input value! Please Try again: ";
				cin >> cutIndex;
			}
			//calling cutShuffle(cutIndex)
			newCardDeck.cutShuffle(cutIndex);
			break;
		case 8: // exit
			programFlag = false;
			break;
		default:
			cout << "Invalid input for Menu Option! Please try again." << endl;
			break;
		}
	}

	return 0;
}

