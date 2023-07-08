#include <stdio.h>
#include "labirinto.h"
#include "percurso.h"
#include "posicao.h"

int main(){

    //inicio do Programa
    // alocação e atribuição para as variaveis principais e de controle
    char opcao=' ';
    int valida=1;
    int achou = 0;
    Percurso *pTra;
    Posicao *inicio = alocaPos();//aloca o inicio
    Posicao *saida = alocaPos();//aloca a posição para saida
    Posicao *mause = alocaPos();//aloca uma posição para o rato
    Labirinto *pLab;
    
    //leitura do terminal
    pLab = lelabirinto(opcao);
    printf("\n"); 
    
    //atualização das posições e execução do programa
    posMause(pLab, mause);
    updatePos(inicio, valueY(mause), valueX(mause));  
    updatePos( saida, pLab->tamL - 2, pLab->tamC - 2);
    pTra = alocaPer(pLab->v);
    valida = escolheSaida(pLab, saida, mause,pTra, inicio, achou);
    
    //impressão da saida
    if(valida == 1){
        pLab = imprimepercursoNolabirinto(pLab,pTra,inicio,saida);
        if(pLab->op=='c' || pLab->op=='C'){
            printf("%d, %d\n",saida->y,saida->x);
        }
    }else if(valida != 1){
        pLab->mapa[inicio->y][inicio->x] = 'M';
        printf("%d\n ",pTra->mcom+1);
        printLab(pLab);
        printf("EPIC FAIL\n");
    }
    
    //desalocação da memoria
    desalocaPos(&inicio);
    desalocaPos(&mause); 
    desalocaPos(&saida);
    desalocaPer(&pTra);
    desalocaLab(&pLab);
    
    //fim do Programa
    return 0;
}
