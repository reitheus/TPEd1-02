#ifndef fila_h
#define fila_h

#include <stdio.h>

typedef struct cel{
    Posicao pos;
    struct cel *prox;
} Celula;

typedef struct {
    Celula* cabeca;
    Celula* ultimo;
} Fila;

int iniciaFila (Fila *) ;
int FilaEhVazia (Fila *) ;
void FilaEnfileira (Fila *, Posicao ); /* insere no final */
int FilaDesenfileira (Fila *, Posicao* ) ; /* retira do iní cio */
void FilaLibera (Fila *) ;

#endif // fila.h