#include "funclib.h"
#include "testLib.h"

#include <cstdio>

void setupTest3_onePair_1(Card* const wDeck)
{
	wDeck[0].id = 5; //Three of Diamonds
	wDeck[1].id = 8; //Four of Clubs
	wDeck[2].id = 7; //Three of Spades
}

void setupTest3_onePair_2(Card* const wDeck)
{
	wDeck[0].id = 8; //Four of Clubs
	wDeck[1].id = 4; //  Three of Clubs
	wDeck[2].id = 12; //  Five of Clubs
}


void setupTest3_onePair_3(Card* const wDeck)
{
	wDeck[0].id = 4; // Three of Clubs
	wDeck[1].id = 6; //  Three of Hearts
	wDeck[2].id = 5; //Three of Diamonds
}


void setupTest5_fourOfAKind_1(Card* const wDeck)
{
	wDeck[0].id = 1; // Deuce of Diamonds
	wDeck[1].id = 0; // Deuce of Clubs
	wDeck[2].id = 3; // Deuce of Spades
	wDeck[3].id = 4; //  Three of Clubs
	wDeck[4].id = 5; //  Three of Diamonds
}


void setupTest5_fourOfAKind_2(Card* const wDeck)
{
	wDeck[0].id = 0; // Deuce of Clubs
	wDeck[1].id = 8; //Four of Clubs
	wDeck[2].id = 4; // Three of Clubs
	wDeck[3].id = 12;//Five of Clubs
	wDeck[4].id = 16; //  Six of Clubs
}


void setupTest5_fourOfAKind_3(Card* const wDeck)
{
	wDeck[0].id = 0; // Deuce of Clubs
	wDeck[1].id = 28; // Nine of Clubs
	wDeck[2].id = 34; //Ten of Hearts
	wDeck[3].id = 29; // Nine of Diamonds
	wDeck[4].id = 33; //Ten of Diamonds
}

void setupTest5_fourOfAKind_4(Card* const wDeck)
{
	wDeck[0].id = 48; 
	wDeck[1].id = 5; 
	wDeck[2].id = 9; 
	wDeck[3].id = 16;
	wDeck[4].id = 13; 
}

void testF(Card* const deck)
{
	shuffle(deck);
	test3(deck);
	sort(deck, 3);//�]�w���յP���@��(3�i)
	determine(deck, 3); //�M�w�P���@��(3�i): return true

	setupTest3_onePair_2(deck);   //�]�w���յP���@��(3�i)
	sort(deck, 3);
	determine(deck, 3); //�M�w�P���@��(3�i): return true

	setupTest3_onePair_3(deck);   //�]�w���յP�����O�@��(3�i)
	sort(deck, 3);
	determine(deck, 3); //�M�w�P���@��(3�i): return false

	setupTest5_fourOfAKind_1(deck);		//�]�w���յP���|��
	sort(deck, 5);
	determine(deck, 5);		//�M�w�P���|�� (5�i): return true


	setupTest5_fourOfAKind_2(deck);	//�]�w���յP���|��
	sort(deck, 5);
	determine(deck, 5);		//�M�w�P���|�� (5�i): return true


	setupTest5_fourOfAKind_3(deck);	//�]�w���յP�����O�|��
	sort(deck, 5);
	determine(deck, 5);		//�M�w�P���|�� (5�i): return false


	setupTest5_fourOfAKind_4(deck);	//�]�w���յP�����O�|��
	sort(deck, 5);
	determine(deck, 5);
	
}

void test3(Card* const wDeck)
{
	//sort(wDeck, 3);
	wDeck[0].id = 5; //Three of Diamonds
	wDeck[1].id = 8; //Four of Clubs
	wDeck[2].id = 7; //Three of Spades	 //�]�w���յP���@��(3�i)
}
