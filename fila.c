#include "fila.h"
#include "posicao.h"

int inciaFila(Fila *pFila){
    pFila->cabeca = (Celula*) malloc (sizeof(Celula));
    if (pFila->cabeca == NULL) return 0;
    pFila->ultimo = pFila->cabeca;
    return 1;

}

int FilaEhVazia(Fila *pfila){
    return pfila->cabeca == pfila->ultimo;
}

void FilaEnfileira ( Fila *pfila , Posicao pos) {
Celula * aux = ( Celula *) malloc ( sizeof ( Celula ) );
aux->pos = pos;
aux->prox = NULL ;
pfila->ultimo->prox = aux ;
pfila->ultimo = aux;
}

int FilaDesenfileira ( Fila *pfila ,Posicao *pos) {
if ( FilaEhVazia (pfila))
return 0;
Celula * aux = pfila->cabeca->prox;
pfila->cabeca->prox = pfila->cabeca->prox->prox;
*pos = aux->pos;
free ( aux );
return 1;
}

void FilaLibera ( Fila *pfila) {
/* Considere que a fila foi declarada estaticamente na main */
Posicao t ;
while ( FilaDesenfileira (pfila, &t)) ;
free ( pfila->cabeca );
}