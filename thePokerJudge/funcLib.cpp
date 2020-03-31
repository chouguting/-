

#include <cstdio>
#include <cstdlib>

#include "funclib.h"





void fillDeckFaceFirst(Card* const wDeck, const char* wFace[],
	const char* wSuit[])
{
	int i = 0;
	int j;
	for (j = 0; j < 13; j++)
	{
		int k;
		for (k = 0; k < 4; k++)
		{
			wDeck[i].face = wFace[j];
			wDeck[i].suit = wSuit[k];
			wDeck[i].id = i;
			i++;
		}
	}
}

void fillDeck(Card* const wDeck, const char* wFace[],
	const char* wSuit[])
{
	int i;

	for (i = 0; i <= 51; i++) {
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}
}

void shuffle(Card* const wDeck)
{
	int i, j;
	Card temp;

	for (i = 0; i <= 51; i++) {
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void deal(const Card* const wDeck, int quantity)
{
	int i;

	for (i = 0; i < quantity; i++)
		printf("%d \t %5s of %-8s \t%d%c", i + 1, wDeck[i].face,
			wDeck[i].suit,wDeck[i].id, '\n');
}



//判斷同花
int isFlush(Card wDeck[],int size)
{
	int isflush = 1;
	int i;
	int lastSuit = (wDeck[0].id+1)%4;
	for(i=0;i<size;i++)
	{
		if((wDeck[i].id + 1) % 4!=lastSuit)
		{
			isflush = 0;
		}
		lastSuit = (wDeck[i].id + 1) % 4;
		
	}
	
	return isflush;
}

//判斷順
int isStraight(Card wDeck[], int size)
{
	
	
	
	int isstraight = 1;
	int i;
	
	int lastFace = (wDeck[0].id)/4;
	for (i = 1; i < size;i++)
	{
		//printf("FACE: %d LAST:%d\n", (wDeck[i].id) / 4,lastFace);
		if ((wDeck[i].id) / 4 != lastFace + 1)
		{
			isstraight = 0;
		}
		lastFace = (wDeck[i].id) / 4;
	}
	return isstraight;
}


//判斷A2345的順 (特殊的)
int isSpecialStraight(Card wDeck[], int size)
{



	int isspecialstraightraight = 1;
	int i;

	if (wDeck[0].id / 4 != 0)
	{
		isspecialstraightraight = 0;
	}
	int lastFace = (wDeck[0].id) / 4;
	for (i = 1; i < size - 1; i++)
	{
		//printf("FACE: %d LAST:%d\n", (wDeck[i].id) / 4,lastFace);
		if ((wDeck[i].id) / 4 != lastFace + 1)
		{
			isspecialstraightraight = 0;
		}
		lastFace = (wDeck[i].id) / 4;
	}
	if (wDeck[size - 1].id / 4 != 12)
	{
		isspecialstraightraight = 0;
	}
	return isspecialstraightraight;
}


//判斷給定值數量的牌出現幾次
//第一格參數判斷對子就輸入2 ,三條就輸入3,四條就輸入4
int howManyOfaKind(int multipleKind,Card wDeck[], int size)
{
	int howMany = 0;
	int i=0;
	while( i <= size- multipleKind)
	{
		int currentFace = (wDeck[i].id) / 4;
		int sameCount=0;  //計算重複幾個
		int j = 0;
		
		while(currentFace == (wDeck[i + j].id) / 4 && j+i<size) 
		{			
			sameCount++;
			j++;
		}
		if(sameCount == multipleKind) //超過也不算
		{
			i = i + multipleKind;
			howMany++;
		}
		else
		{
			i = i + sameCount;  //檢查過的不用再檢查
		}
	}
	return howMany;
}


//排序
void sort(Card wDeck[], int size)
{
	int i;

	for (i = 0; i < size - 1; i++)
	{
		Card min = wDeck[i];
		int minIndex = i;
		int j;
		for (j = i; j < size; j++)
		{
			if (wDeck[j].id < min.id)
			{
				min = wDeck[j];
				minIndex = j;
			}
		}
		Card cardTemp;
		cardTemp = wDeck[i];
		wDeck[i] = wDeck[minIndex];
		wDeck[minIndex] = cardTemp;
	}
}

void determine(Card wDeck[],int size)
{

	if (isFlush(wDeck, size) == 1 && (isSpecialStraight(wDeck, size)==1 || isStraight(wDeck, size) == 1) && size > 3)
	{
		printf("同花順!!\n\n");
	}else if(howManyOfaKind(4,wDeck,size)>=1)
	{
		printf("四條!!\n\n");
	}else if (howManyOfaKind(3,wDeck,size)>=1&& howManyOfaKind(2, wDeck, size)>=1)
	{
		printf("葫蘆!!\n\n" );
	}else if (isFlush(wDeck, size) == 1 && size > 3)
	{
		printf("同花!!\n\n" );
	}
	else if ((isSpecialStraight(wDeck, size) == 1 || isStraight(wDeck, size) == 1) && size > 3)
	{
		printf("順子!!\n\n");
	}else if (howManyOfaKind(3, wDeck, size) >= 1 )
	{
		printf("三條!!\n\n");
	}else if (howManyOfaKind(2, wDeck, size) == 2)
	{
		printf("二對!!\n\n");
	}else if (howManyOfaKind(2, wDeck, size) == 1)
	{
		printf("對子!!\n\n");
	}else
	{
		printf("散牌\n\n");
	}
}