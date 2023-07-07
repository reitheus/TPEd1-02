#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

void iniciaFila(Fila *pFila){
    pFila=(Fila*)malloc(sizeof(Fila));
    pFila->cabeca = NULL;
    pFila->ultimo = NULL;
    printf("fila iniciada\n");

}

int FilaEhVazia(Fila *pfila){
    if(pfila->cabeca == pfila->ultimo){
        return 1;
    }else{
        return 0;
    }
    
}

void insereFila ( Fila *pfila ,Iten pitem) {
    Celula * aux = ( Celula *) malloc ( sizeof ( Celula ) );
    if (aux == NULL) {
        printf("Erro: Memória insuficiente.\n");
        exit(1);
    }
    aux->iten=pitem;
    aux->prox = NULL ;

    if (pfila->ultimo == NULL) {
        pfila->cabeca = aux;
    } else {
        pfila->ultimo->prox = aux;
    }
    pfila->ultimo = aux;
}

int FilaDesenfileira ( Fila *pfila ,Iten *pitem) {
    if (FilaEhVazia(pfila)) {
        return 0;
    }else{

        Celula* aux = pfila->cabeca;
        *pitem = aux->iten;

        pfila->cabeca = pfila->cabeca->prox;

        if (pfila->cabeca == NULL) {
            pfila->ultimo = NULL;
        }

        free(aux);

        return 1;
    }

}

void FilaLibera ( Fila *pfila) {
    Iten t;
    while ( FilaDesenfileira (pfila, &t)) ;
    free ( pfila->cabeca );
}