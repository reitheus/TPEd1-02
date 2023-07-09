#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

Fila* iniciaFila(void){
    Fila *pFila = (Fila*)malloc(sizeof(Fila));
    pFila->ultimo = NULL;
    pFila->cabeca = NULL;
    return pFila;

}

int FilaEhVazia(Fila *pfila){
    if(pfila->cabeca == NULL){
        return 1;
    }else{
        return 0;
    }
    
}

void insereFila ( Fila *pfila ,Iten *pitem) {
    Celula *aux = (Celula*) malloc (sizeof(Celula));
    if (aux == NULL) {
        printf("Erro: Memória insuficiente.\n");
        exit(1);
    }else{
        aux->iten = *pitem;
        aux->prox = NULL ;

        if (pfila->cabeca == NULL) {
            pfila->cabeca = aux;
            pfila->ultimo = aux;
            
        } else {
            pfila->ultimo->prox = aux;
            pfila->ultimo = aux;
        }
        pfila->ultimo = aux;
    }
}

Iten FilaDesenfileira ( Fila *pfila, Iten *pitem) {
    
    if (FilaEhVazia(pfila)) {
        exit(1);
    }
    
    Celula *aux = pfila->cabeca;
    *pitem = aux->iten;
    pfila->cabeca = aux->prox;

    if (pfila->cabeca == NULL) {
        pfila->ultimo = NULL;
    }

    free(aux);
    return *pitem;

}

void FilaLibera ( Fila *pfila) {
    Celula *t;
    Celula *q = pfila->cabeca;
    while ( q != NULL){
        t = q->prox;
        free(q);
        q=t;
    }
    free (pfila);
}
