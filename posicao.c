#include <stdio.h>
#include <stdlib.h>

#include "posicao.h"


Posicao* alocaPos(){
    Posicao* newpos = (Posicao*)malloc(sizeof(Posicao));
    return newpos;
}

void desalocaPos(Posicao** ppos){
    free(*ppos);
}

void updatePos(Posicao* posicao, int y, int x){
    //função de atribuição para x e y de posicao    
    
    posicao->y = y;
    posicao->x = x;
}

int valueX(Posicao* posicao){
    //função pega uma posição e retorna o seu valor x

    return posicao->x;
}

int valueY(Posicao* posicao){
    //função pega uma posição e retorna o seu valor y

    return posicao->y;
}
