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
	sort(deck, 3);//設定測試牌型一對(3張)
	determine(deck, 3); //決定牌型一對(3張): return true

	setupTest3_onePair_2(deck);   //設定測試牌型一對(3張)
	sort(deck, 3);
	determine(deck, 3); //決定牌型一對(3張): return true

	setupTest3_onePair_3(deck);   //設定測試牌型不是一對(3張)
	sort(deck, 3);
	determine(deck, 3); //決定牌型一對(3張): return false

	setupTest5_fourOfAKind_1(deck);		//設定測試牌型四條
	sort(deck, 5);
	determine(deck, 5);		//決定牌型四條 (5張): return true


	setupTest5_fourOfAKind_2(deck);	//設定測試牌型四條
	sort(deck, 5);
	determine(deck, 5);		//決定牌型四條 (5張): return true


	setupTest5_fourOfAKind_3(deck);	//設定測試牌型不是四條
	sort(deck, 5);
	determine(deck, 5);		//決定牌型四條 (5張): return false


	setupTest5_fourOfAKind_4(deck);	//設定測試牌型不是四條
	sort(deck, 5);
	determine(deck, 5);
	
}

void test3(Card* const wDeck)
{
	//sort(wDeck, 3);
	wDeck[0].id = 5; //Three of Diamonds
	wDeck[1].id = 8; //Four of Clubs
	wDeck[2].id = 7; //Three of Spades	 //設定測試牌型一對(3張)
}
