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

Labirinto* imprimepercursoNolabirinto(Labirinto* ,Percurso* );

#endif // LABIRINTO_H
