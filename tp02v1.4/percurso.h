#ifndef PERCURSO_H
#define PERCURSO_H

#include "posicao.h"

typedef struct percuso{
    Posicao *trajetos;
    Posicao *mCaminho;
    int mcom;
    int tamTrajeto;
}Percurso;

Percurso* alocaPer(int );
void desalocaPer(Percurso** );
void updateTra(Percurso* , int, int, int);

#endif // PERCURSO_H
