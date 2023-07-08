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
int achaSaidaPilha(Labirinto* , Posicao* , Posicao* , Percurso* , int ,int );

int achaSaidaFila(Labirinto* , Posicao*, Posicao* ,Percurso* ,int );

//escolhe qual função de achar saida será executada
int escolheSaida(Labirinto* , Posicao* , Posicao* , Percurso* , Posicao* , int );


Labirinto* imprimepercursoNolabirinto(Labirinto* ,Percurso* ,Posicao* ,Posicao* );

#endif // LABIRINTO_H
