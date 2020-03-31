

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



//�P�_�P��
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

//�P�_��
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


//�P�_A2345���� (�S��)
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


//�P�_���w�ȼƶq���P�X�{�X��
//�Ĥ@��ѼƧP�_��l�N��J2 ,�T���N��J3,�|���N��J4
int howManyOfaKind(int multipleKind,Card wDeck[], int size)
{
	int howMany = 0;
	int i=0;
	while( i <= size- multipleKind)
	{
		int currentFace = (wDeck[i].id) / 4;
		int sameCount=0;  //�p�⭫�ƴX��
		int j = 0;
		
		while(currentFace == (wDeck[i + j].id) / 4 && j+i<size) 
		{			
			sameCount++;
			j++;
		}
		if(sameCount == multipleKind) //�W�L�]����
		{
			i = i + multipleKind;
			howMany++;
		}
		else
		{
			i = i + sameCount;  //�ˬd�L�����ΦA�ˬd
		}
	}
	return howMany;
}


//�Ƨ�
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
		printf("�P�ᶶ!!\n\n");
	}else if(howManyOfaKind(4,wDeck,size)>=1)
	{
		printf("�|��!!\n\n");
	}else if (howManyOfaKind(3,wDeck,size)>=1&& howManyOfaKind(2, wDeck, size)>=1)
	{
		printf("��Ī!!\n\n" );
	}else if (isFlush(wDeck, size) == 1 && size > 3)
	{
		printf("�P��!!\n\n" );
	}
	else if ((isSpecialStraight(wDeck, size) == 1 || isStraight(wDeck, size) == 1) && size > 3)
	{
		printf("���l!!\n\n");
	}else if (howManyOfaKind(3, wDeck, size) >= 1 )
	{
		printf("�T��!!\n\n");
	}else if (howManyOfaKind(2, wDeck, size) == 2)
	{
		printf("�G��!!\n\n");
	}else if (howManyOfaKind(2, wDeck, size) == 1)
	{
		printf("��l!!\n\n");
	}else
	{
		printf("���P\n\n");
	}
}