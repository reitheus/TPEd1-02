#ifndef PILHA_H
#define PILHA_H


//#define MAXTAM 1000
#define INICIO 0
#define TAM 1

typedef struct{
    int y;
    int x;

}Pai;

typedef struct{
    int y;
    int x;
    Pai pai;

}Item;

typedef struct {
    int n;
    Item *item;
    int primeiro, ultimo;
}Pilha;

Pilha* alocaPilha(int n);

void desalocaPilha(Pilha **ppPilha);

Pilha* PilhaInicia(int n);

int PilhaEhVazia(Pilha *pPilha);

int insertPilha(Pilha *pPilha, Item x);

int removePilha(Pilha *pPilha);

int testePaiItem(Item item1, Item item2);

void pilhaImprime(Pilha *pPilha);



#endif 

