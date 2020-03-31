#include <cstdlib>
#include <stdio.h>
#include <time.h>

#include "funclib.h"
#include "oldLib.h"
#include "testLib.h"

int main()
{
    Card deck[52];
    const char* face[] = {  "Deuce", "Three",
                           "Four", "Five",
                           "Six", "Seven", "Eight",
                           "Nine", "Ten",
                           "Jack", "Queen", "King" ,"Ace" };

    const char* suit[] = {"Clubs","Diamonds","Hearts","Spades"   };			////////////////////

    srand(time(NULL));

    Card* dealptr = deck;

    int operation=0;
    fillDeckFaceFirst(deck, face, suit);
	while(1)
	{
        printf("Input your operation(1~6):");
        scanf_s("%d", &operation, 10);
		
		if(operation==1)
		{
			// 設牌初始值
            shuffle(deck);
            dealptr = deck;
            printf("洗牌完成!!\n");
            system("pause");
            system("cls");
			
		}else if(operation == 2)
		{
            shuffle(deck);
            //test3(deck);
            sort(deck, 3);
            deal(deck, 3);
            determine(deck, 3);
            system("pause");
            system("cls");
			
		}else if(operation==3)
		{
            shuffle(deck);
            sort(deck, 5);
            
            deal(deck, 5);
            
            
     

			printf("\nisFlush:%d  isStraight:%d\n ",isFlush(deck,5),isStraight(deck,5));
            printf("hasFourOfaKind:%d isFullHouse:%d\n",hasFourOfaKind(deck,5),isFullHouse(deck,5));
            printf("hasThreeOfaKind:%d pairsCount:%d\n", hasThreeOfaKind(deck, 5), countPairs(deck, 5));
            printf("2:%d  3:%d 4:%d\n",howManyOfaKind(2,deck,5), howManyOfaKind(3, deck, 5), howManyOfaKind(4, deck, 5));

            determine(deck, 5);
			system("pause");
            system("cls");
		}else if(operation==4)
		{
            fillDeckFaceFirst(deck, face, suit);
            deal(deck, 52);
            system("pause");
            system("cls");
		}else if (operation == 5)  //單純測試用
        {
            shuffle(deck);
            testF(deck);
            //deal(deck, 52);
            system("pause");
            system("cls");
        }
        else if(operation==6)
		{
            break;
		}
	}

    																						// 洗牌
    //deal(deck);																						// 列印牌

    //testF(deck);

    system("pause");
    return 0;
}
