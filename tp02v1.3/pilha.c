#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "pilha.h"


//aloca a pilha
Pilha* alocaPilha(int n){

    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));

    pilha->item = (Item*)malloc(n * sizeof(Item));
    pilha->n = n;
    return pilha;

}

//desaloca a pilha
void desalocaPilha(Pilha **ppPilha){

	free( (*ppPilha)->item );
	free(*ppPilha);

}

//inicia a pilha com os valores inicias de cada variavel
Pilha* PilhaInicia(int n){
    
    Pilha *pPilha;

    pPilha = alocaPilha(n);
    pPilha->primeiro = INICIO;
    pPilha->n = n;
    pPilha->ultimo = pPilha->primeiro;

    return pPilha;
}

//verificase a pilha está vazia
int PilhaEhVazia(Pilha *pPilha){

    if(pPilha->ultimo == pPilha->primeiro){
        return 1;
    }

    return 0;


}


//inseri um item no final da pilha
//Pilha *pPilhaponteiro da lista
//Item x o item que vai ser inserido
int insertPilha(Pilha *pPilha, Item x){
    
    if(pPilha->ultimo == pPilha->n){
        printf("\nPilhacheia\n");
        return 0;
    }

    //printf("\ninseriu pilha item.x %i item.y %i\n", x.x, x.y);
    pPilha->item[pPilha->ultimo] = x;

    pPilha->ultimo++;
    return 1;

}

//remove um valor no final da pilha
int removePilha(Pilha *pPilha){

    if(PilhaEhVazia(pPilha)){
        printf("\nPilha vazia não tem como remover \n");
        return 0;

    }
    //printf("removeu da pilha item.x %i item.y %i", pPilha->item[pPilha->ultimo - 1].x,pPilha->item[pPilha->ultimo - 1].y);

    pPilha->ultimo--;
    return 1;

}

//verifica se o valor do pai do item 2 é igual ao valor do item 1
int testePaiItem(Item item1, Item item2){

    if(item1.x == item2.pai.x && item1.y == item2.pai.y){

        return 1;

    }else{

        return 0;

    }
    return 0;

}

//imprime os valores da pilha
void pilhaImprime(Pilha *pPilha){
    printf("\n");

    for(int i = pPilha->primeiro; i < pPilha->ultimo; i++){

        printf("\nx %i y %i \n", pPilha->item[i].x, pPilha->item[i].y);

    }

    printf("\n");


}














