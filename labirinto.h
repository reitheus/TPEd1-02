#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "percurso.h"
#include "posicao.h"

typedef struct {
    char **mapa;
    char op;
    int tamL;
    int tamC;
    int v;
}Labirinto;

Labirinto* alocaLab(int, int );

void desalocaLab(Labirinto** );
int verificavazio(Labirinto* );
Labirinto* lelabirinto(char );



void printLab(Labirinto* );

void posMause(Labirinto*, Posicao* );

int achaSaida(Labirinto*, Posicao* , Posicao* , Percurso* ,int ,Posicao* , int );

//função que acha a saida utilizando pilha e metodo de procura em profundidade
int achaSaidaPilha(Labirinto* pLab, Posicao *saida, Posicao *mause, Percurso *pTra, int i, int achou);

//escolhe qual função de achar saida será executada
int escolheSaida(Labirinto* pLab, Posicao *saida, Posicao *mause, Percurso *pTra, int i, Posicao *inicio, int achou);


Labirinto* imprimepercursoNolabirinto(Labirinto* ,Percurso* );

#endif // LABIRINTO_H
