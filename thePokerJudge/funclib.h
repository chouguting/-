#ifndef FIG1003_H  // �קK���Х]�t���Y��
#define FIG1003_H


struct card {
    const char* face;
    const char* suit;

    int id;
};



typedef struct card Card;

void fillDeck(Card* const, const char* [], const char* []);	// �]�P��l��
void shuffle(Card* const);																		// �~�P
void deal(const Card* const,int quantity);



void fillDeckFaceFirst(Card* const wDeck, const char* wFace[],const char* wSuit[]);


int isFlush(Card wDeck[], int size);
int isStraight(Card wDeck[], int size);


int howManyOfaKind(int multipleKind, Card wDeck[], int size);
void determine(Card wDeck[], int size);
void sort(Card wDeck[], int size);
#endif

