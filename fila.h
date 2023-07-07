#ifndef fila_h
#define fila_h

#include "posicao.h"

typedef struct iten{
    Posicao atual;
    int distancia;
}Iten;

typedef struct cel{
    Iten iten;
    struct cel *prox;
} Celula;

typedef struct {
    Celula* cabeca;
    Celula* ultimo;
} Fila;

void iniciaFila (Fila *) ;
int FilaEhVazia (Fila *) ;
void insereFila (Fila *, Iten ); /* insere no final */
int FilaDesenfileira (Fila* , Iten* ) ; /* retira do iní cio */
void FilaLibera (Fila *) ;

#endif // fila.h