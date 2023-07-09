#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"
#include "labirinto.h"

Labirinto* alocaLab(int L, int C){
    //função de alocação do labirinto com mensagem de erros em caso de erro    
    
    Labirinto* newlab = (Labirinto*)malloc(sizeof(Labirinto));
    if (newlab == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    newlab->mapa = (char**)malloc(L * sizeof(char*));
    if (newlab->mapa == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    for (int i = 0; i < L; i++){
        newlab->mapa[i] = (char*)malloc(C * sizeof(char));
        if (newlab->mapa[i] == NULL){
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
    for (int i = 0; i < pLab->tamL; i++){
        for (int j = 0; j < pLab->tamC; j++){
            if (pLab->mapa[i][j] == ' '){
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

    for (int i = 0; i < L; i++){
        for (int j = 0; j < C; j++){
            scanf("%c", &(plab->mapa[i][j]));
        }
    }
    plab->v = verificavazio(plab);// verificação e armazenamento da quantidades de espaços vazios
    plab->op = opcao;
    return plab;
}

void printLab(Labirinto* pLab){
    //função para imprimir o labirinto salvo

    for (int i = 0; i < pLab->tamL; i++){
        for (int j = 0; j < pLab->tamC; j++){
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


int corrigiLab(Labirinto* pLab){

    for (int i = 0; i < pLab->tamL; i++){
        for (int j = 0; j < pLab->tamC; j++){
            if (pLab->mapa[i][j] == 'b')
            {
                pLab->mapa[i][j] =' ';
            }
        }
    }

    return 1;
}

int achaSaida(Labirinto* pLab, Posicao *saida, Posicao *mause, Percurso *pTra, int i,Posicao *inicio, int achou){
    //função recursiva
    
    if (valueY(mause) == valueY(saida) && valueX(mause) == valueX(saida)){
        
        if(i < pTra->mcom){
            pTra->mcom = i;
            for(int j=0;j <= pTra->mcom;j++){
            	pTra->mCaminho[j] = pTra->trajetos[j];
            	
            }
            
        }
        return 1;//se o rato acha a saida retorna 1
    }
    pLab->mapa[valueY(mause)][valueX(mause)] = 'b';
    
    if (valueX(mause) + 1 > 0 && valueX(mause) + 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) + 1] == ' '){
        //teste para direita   
        updatePos(mause, valueY(mause), valueX(mause) + 1);
        updateTra(pTra,i ,valueX(mause),valueY(mause));
        achou = achaSaida(pLab, saida, mause, pTra, i+1,inicio, achou);
        updatePos(mause, valueY(mause), valueX(mause) - 1);
        

    }

    if (valueY(mause) + 1 > 0 && valueY(mause) + 1 < pLab->tamL && pLab->mapa[valueY(mause) + 1][valueX(mause)] == ' '){
        //teste para baixo
        updatePos(mause, valueY(mause) + 1, valueX(mause));
        updateTra(pTra,i ,valueX(mause),valueY(mause));
        achou = achaSaida(pLab, saida, mause, pTra, i+1,inicio, achou);
        updatePos(mause, valueY(mause) - 1, valueX(mause));
        
    }

    if (valueX(mause) - 1 > 0 && valueX(mause) - 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) - 1] == ' '){   
        //teste para esquerda
        updatePos(mause, valueY(mause), valueX(mause) - 1);
        updateTra(pTra,i ,valueX(mause),valueY(mause));
        achou = achaSaida(pLab, saida, mause, pTra, i+1,inicio, achou);
        updatePos(mause, valueY(mause), valueX(mause) + 1);
        
    }
    
    //teste para cima
    if (valueY(mause) - 1 > 0 && valueY(mause) - 1 < pLab->tamL && pLab->mapa[valueY(mause) - 1][valueX(mause)] == ' '){
        
        updatePos(mause, valueY(mause) - 1, valueX(mause));
        updateTra(pTra,i ,valueX(mause),valueY(mause));
        achou = achaSaida(pLab, saida, mause, pTra, i+1,inicio, achou);
        updatePos(mause, valueY(mause) + 1, valueX(mause));
        

    }
    
    pLab->mapa[valueY(mause)][valueX(mause)] = ' ';
    
    if( valueX(inicio) == valueX(mause) && valueY(inicio) == valueY(mause) && achou == 0){
        //teste para ver se não foi possivel chegar a saida
        return achou;
    }
    
    return achou;
}


//função que acha a saida utilizando pilha e metodo de procura em profundidade
int achaSaidaPilha(Labirinto* pLab, Posicao *saida, Posicao *mause, Percurso *pTra, int achou,int i){
    Pilha *pPilha;
    Pilha *pPilhaCaminho;
    pPilha = PilhaInicia(verificavazio(pLab));
    pPilhaCaminho = PilhaInicia(verificavazio(pLab));
    
    Item item;
   
    while(mause->x != saida->x || mause->y != saida->y){
       
        pLab->mapa[valueY(mause)][valueX(mause)] = 'b';
        
        item.x = mause->x;
        item.y = mause->y;
        item.pai.x = mause->x;
        item.pai.y = mause->y;

        if (valueX(mause) + 1 > 0 && valueX(mause) + 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) + 1] == ' '){
            //teste para direita
            item.x++;
            insertPilha(pPilha, item);
            item.x--;
            
        }
        
        if (valueY(mause) + 1 > 0 && valueY(mause) + 1 < pLab->tamL && pLab->mapa[valueY(mause) + 1][valueX(mause)] == ' '){
            //teste para baixo
            item.y++;
            insertPilha(pPilha, item);
            item.y--;
            
        }

        if (valueX(mause) - 1 > 0 && valueX(mause) - 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) - 1] == ' '){   
            //teste para esquerda
            item.x--;
            insertPilha(pPilha, item);
            item.x++;
            
        }
        
        if (valueY(mause) - 1 > 0 && valueY(mause) - 1 < pLab->tamL && pLab->mapa[valueY(mause) - 1][valueX(mause)] == ' '){
            //teste para Cima
            item.y--;
            insertPilha(pPilha, item);
            item.y++;
        }

        //atualiza o valor do rato com o ultimo valor da pilha principal pPilha
        updatePos(mause, pPilha->item[pPilha->ultimo - 1].y, pPilha->item[pPilha->ultimo - 1].x);
        
        //Enquanto o item o ultimo da Pilha caminho não for o pai do item que tera a proxima posição do mause, vai remover itens
        while( !testePaiItem(pPilhaCaminho->item[pPilhaCaminho->ultimo - 1], pPilha->item[pPilha->ultimo - 1]) ){
            if(PilhaEhVazia(pPilhaCaminho)){
                break;
            }
            
            removePilha(pPilhaCaminho);

        }
        
        //inseri na pilha pPilhaCaminho a as coordenadas co caminho endo feito
        insertPilha(pPilhaCaminho, pPilha->item[pPilha->ultimo - 1]);

        if(mause->x == saida->x && mause->y == saida->y){
            //printf("\nachou a saida\n");
            achou = 1;
            break;
            
        }
        else if(PilhaEhVazia(pPilha) && achou == 0){
            printf("\nultimo %i\n",pPilha->ultimo);
            printf("\n\nnão achou saida\n\n");
            printf("\n\n%i\n\n",PilhaEhVazia(pPilha));
            desalocaPilha(&pPilhaCaminho);
            desalocaPilha(&pPilha);
            return achou;
            break;

        }
        removePilha(pPilha);

    }
    
    //retira os caracteres b do labirinto, o caracter b é utilizado para o rato não passa em uma posição mais de uma vez
    corrigiLab(pLab);

    //passa os valores da pilha caminho para o vetor trajeto
    while(i < pPilhaCaminho->ultimo){

        updateTra(pTra, i,  pPilhaCaminho->item[i].x,pPilhaCaminho->item[i].y);
        pTra->mCaminho[i] = pTra->trajetos[i];
        i++;
    }
    pTra->mcom = i;

    //desaloca as pilhas utilizadas
    desalocaPilha(&pPilhaCaminho);
    desalocaPilha(&pPilha);
    return 1;
}

int achaSaidaFila(Labirinto *pLab, Posicao *saida, Posicao *mause, Percurso *pTra,int achou){
    Fila *pFila = iniciaFila( );
    Iten casa;
    casa.atual.x = valueX(mause);
    casa.atual.y = valueY(mause);
    casa.distancia = 0;
    updateTra(pTra,casa.distancia,valueX(&casa.atual),valueY(&casa.atual));
    insereFila(pFila,&casa);
    while(!FilaEhVazia(pFila)){

        casa = FilaDesenfileira(pFila, &casa);
        pLab->mapa[valueY(mause)][valueX(mause)] = 'o';

        //verificação da saida
        if(casa.atual.x == saida->x && casa.atual.y == saida->y){

            casa.distancia++;
            updatePos(mause,valueY(&casa.atual),valueX(&casa.atual));
            pLab->mapa[valueY(mause)][valueX(mause)] = 'o';
            updateTra(pTra,casa.distancia,valueX(&casa.atual),valueY(&casa.atual));
            achou = 1;
            pTra->mcom = casa.distancia;
            for (int i = 0; i <= casa.distancia; i++) {
                pTra->mCaminho[i] = pTra->trajetos[i];
            }
            break;

        }else{

            casa.distancia++;
            updatePos(mause,valueY(&casa.atual),valueX(&casa.atual));
            updateTra(pTra,casa.distancia,valueX(&casa.atual),valueY(&casa.atual));
           
        }
        
        //inicio dos testes de posição
        if (valueX(mause) + 1 > 0 && valueX(mause) + 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) + 1] == ' '){
            //teste para direita
            casa.atual.x++;
            insereFila(pFila, &casa);
            casa.atual.x--;
            
        }
        
        if (valueY(mause) + 1 > 0 && valueY(mause) + 1 < pLab->tamL && pLab->mapa[valueY(mause) + 1][valueX(mause)] == ' '){
            //teste para baixo
            casa.atual.y++;
            insereFila(pFila, &casa);
            casa.atual.y--;
            
        }

        if (valueX(mause) - 1 > 0 && valueX(mause) - 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) - 1] == ' '){   
            //teste para esquerda
            casa.atual.x--;
            insereFila(pFila, &casa);
            casa.atual.x++;
            
        }

        if (valueY(mause) - 1 > 0 && valueY(mause) - 1 < pLab->tamL && pLab->mapa[valueY(mause) - 1][valueX(mause)] == ' '){
            //teste cima
            casa.atual.y--;
            insereFila(pFila, &casa);
            casa.atual.y++;

        }       
    }

    //atualição do vetor e do tamanho
    for (int i = 0; i <= casa.distancia; i++) {
        pTra->mCaminho[i] = pTra->trajetos[i];
    }
    pTra->mcom = casa.distancia;
    
    FilaLibera(pFila);
    return achou;
}


//escolhe qal função achaSaida ira ser chamada
int escolheSaida(Labirinto* pLab, Posicao *saida, Posicao *mause, Percurso *pTra, Posicao *inicio, int achou){
    int valida;

    switch(pLab->op){

        case 'r':
            printf("\nAcho saida utilizando recursão\n");
            valida = achaSaida(pLab, saida, mause,pTra,0, inicio, achou);
            break;
        case 'p':
            printf("\nAchou saida utilizando Pilha\n");
            valida = achaSaidaPilha(pLab, saida, mause,pTra,0,0);
            break;
        case  'f':
            printf("\nAcha saida por fila\n");
            valida = achaSaidaFila(pLab, saida, mause, pTra,0);
            break;
        default:
            printf("\nOpção invalida\n");
            break;

    }
    return valida;
}



Labirinto* imprimepercursoNolabirinto(Labirinto *plab,Percurso *pTra, Posicao *inicio, Posicao *saida){
    //impressão da saida de acordo com a opção de entrada
    
    //imprime o menor percurso feito
    if(plab->op == 'p' || plab->op == 'r' || plab->op == 'f'){
        
        for (int i = 0; i < pTra->mcom; i++){
            Posicao pos = pTra->mCaminho[i];
            plab->mapa[pos.x][pos.y] = 'o';

        }
        plab->mapa[inicio->y][inicio->x] = 'M';
        plab->mapa[saida->y][saida->x + 1] = 'o';
        printf("%d\n ",pTra->mcom+1);
        printLab(plab);
    }
    
    //imprime o menor caminho feito
    if(plab->op == 'c' || plab->op == 'C'){
    
        printf("%d\n",pTra->mcom);
        for(int i = 0;i < pTra->mcom;i++){
            Posicao pos = pTra->mCaminho[i];
            printf("%d, %d\n",pos.x,pos.y-1);
        }
    }

    return plab;
}

