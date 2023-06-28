#include <stdio.h>
#include <stdlib.h>

#include "labirinto.h"

Labirinto* alocaLab(int L, int C){
    //função de alocação do labirinto com mensagem de erros em caso de erro    
    
    Labirinto* newlab = (Labirinto*)malloc(sizeof(Labirinto));
    if (newlab == NULL)
    {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    newlab->mapa = (char**)malloc(L * sizeof(char*));
    if (newlab->mapa == NULL)
    {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    for (int i = 0; i < L; i++)
    {
        newlab->mapa[i] = (char*)malloc(C * sizeof(char));
        if (newlab->mapa[i] == NULL)
        {
            printf("Memoria insuficiente.\n");
            exit(1);
        }
    }
    //atribuição de valores iniciais para as variaveis do TAD
    newlab->op=' ';
    newlab->tamL = L;
    newlab->tamC = C;
    newlab->v = 0;
    return newlab;
}

void desalocaLab(Labirinto** pLab){
    //função de desaloção do labirinto

    for (int i = 0; i < (*pLab)->tamL; i++){
    
        free((*pLab)->mapa[i]);
    }
    free((*pLab)->mapa);
    free(*pLab);
}

int verificavazio(Labirinto* pLab){
    //função de verificação da quantidade de espaços vazios

    int vazio = 0;
    for (int i = 0; i < pLab->tamL; i++)
    {
        for (int j = 0; j < pLab->tamC; j++)
        {
            if (pLab->mapa[i][j] == ' ')
            {
                vazio += 1;
            }
        }
    }

    return vazio;
}

Labirinto* lelabirinto(char opcao){
    //leitura dos dados do labirinto

    int L, C;
    Labirinto* plab;
    char lixo;

    scanf("%d %d", &L, &C);// leitura das dimenções do labirinto
    scanf("%c", &lixo);//eliminação do \n
    scanf("%c", &opcao);//leitura da opção de impressão

    C += 1;

    plab = alocaLab(L, C);

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%c", &(plab->mapa[i][j]));
        }
    }
    plab->v = verificavazio(plab);// verificação e armazenamento da quantidades de espaços vazios
    plab->op = opcao;
    return plab;
}

void printLab(Labirinto* pLab){
    //função para imprimir o labirinto salvo

    for (int i = 0; i < pLab->tamL; i++)
    {
        for (int j = 0; j < pLab->tamC; j++)
        {
            printf("%c", pLab->mapa[i][j]);
        }
    }
    printf("\n");
}

void posMause(Labirinto* pLab, Posicao* mause){
    //função para ubtenção da posição do rato

    for (int i = 0; i < pLab->tamL; i++){
        for (int j = 0; j < pLab->tamC; j++){
            if (pLab->mapa[i][j] == 'M' || pLab->mapa[i][j] == 'm')
            {
                updatePos(mause, i, j);
            }
        }
    }
}

int achaSaida(Labirinto* pLab, Posicao *saida, Posicao *mause, Percurso *pTra, int i,Posicao *inicio, int achou){
    //função recursiva
    

    if (valueY(mause) == valueY(saida) && valueX(mause) == valueX(saida)){

        if(i < pTra->mcom){
            pTra->mcom = i;
            for(int j=0;j < pTra->mcom;j++){
            	
                pTra->mCaminho[j] = pTra->trajetos[j];
            	
            }
            
        }
        return 1;//se o rato acha a saida retorna 1
    }
    pLab->mapa[valueY(mause)][valueX(mause)] = 'b';
    
    //teste para cima
    if (valueY(mause) - 1 > 0 && valueY(mause) - 1 < pLab->tamL && pLab->mapa[valueY(mause) - 1][valueX(mause)] == ' '){
        
        updatePos(mause, valueY(mause) - 1, valueX(mause));
        updateTra(pTra,i ,valueX(mause),valueY(mause));
        achou = achaSaida(pLab, saida, mause, pTra, i+1,inicio, achou);
        updatePos(mause, valueY(mause) + 1, valueX(mause));
        

    }
    
    if (valueY(mause) + 1 > 0 && valueY(mause) + 1 < pLab->tamL && pLab->mapa[valueY(mause) + 1][valueX(mause)] == ' '){
        //teste para baixo
        updatePos(mause, valueY(mause) + 1, valueX(mause));
        updateTra(pTra,i ,valueX(mause),valueY(mause));
        achou = achaSaida(pLab, saida, mause, pTra, i+1,inicio, achou);
        updatePos(mause, valueY(mause) - 1, valueX(mause));
        
    }
    
    if (valueX(mause) + 1 > 0 && valueX(mause) + 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) + 1] == ' '){
        //teste para direita   
        updatePos(mause, valueY(mause), valueX(mause) + 1);
        updateTra(pTra,i ,valueX(mause),valueY(mause));
        achou = achaSaida(pLab, saida, mause, pTra, i+1,inicio, achou);
        updatePos(mause, valueY(mause), valueX(mause) - 1);
        

    }
    
    if (valueX(mause) - 1 > 0 && valueX(mause) - 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) - 1] == ' '){   
        //teste para esquerda
        updatePos(mause, valueY(mause), valueX(mause) - 1);
        updateTra(pTra,i ,valueX(mause),valueY(mause));
        achou = achaSaida(pLab, saida, mause, pTra, i+1,inicio, achou);
        updatePos(mause, valueY(mause), valueX(mause) + 1);
        
    }
    
    pLab->mapa[valueY(mause)][valueX(mause)] = ' ';
    
    if( valueX(inicio) == valueX(mause) && valueY(inicio) == valueY(mause) && achou == 0){
        //teste para ver se não foi possivel chegar a saida
        return achou;
    }
    
    return achou;
}

Labirinto* imprimepercursoNolabirinto(Labirinto *plab,Percurso *pTra){
    //impressão da saida de acordo com a opção de entrada
    
    //imprime o menor percurso feito
    if(plab->op == 'p' || plab->op == 'p'){
        
        for (int i = 0; i < pTra->mcom; i++){
            Posicao pos = pTra->mCaminho[i];
            plab->mapa[pos.x][pos.y] = '.';
            
        }
        printf("%d\n ",pTra->mcom+1);
        printLab(plab);
    }
    
    //imprime o menor caminho feito
    if(plab->op == 'c' || plab->op == 'C'){
    
        printf("%d\n",pTra->mcom+1);
        for(int i = 0;i < pTra->mcom;i++){
            Posicao pos = pTra->mCaminho[i];
            printf("%d, %d\n",pos.x,pos.y-1);
        }
        
    }
    
    return plab;
}
