#include <stdio.h>
#include <stdlib.h>

#include "percurso.h"
#include "posicao.h"


Percurso* alocaPer(int x){
    //função de alocação do percurso

    Percurso* newper = (Percurso*)malloc(sizeof(Percurso));
    newper->tamTrajeto = x;
    newper->mCaminho = (Posicao*) malloc (newper->tamTrajeto * sizeof(Posicao));
    newper->trajetos = (Posicao*) malloc (newper->tamTrajeto * sizeof(Posicao));
    newper->mcom=x;
    return newper;
}

void updateTra(Percurso *newper, int i, int posy, int posx){
    //função de atualização do trajeto, com a atribuição de posx e posy a um ponto do vetor de posição.
    
    newper->trajetos[i].x = posx;
    newper->trajetos[i].y = posy;
    
}

void desalocaPer(Percurso** pTra){
    //função de desalocação de percurso
    
    free((*pTra)->trajetos);
    free((*pTra)->mCaminho);
    free(*pTra);
}
