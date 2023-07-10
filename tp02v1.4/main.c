#include <stdio.h>
#include "labirinto.h"
#include "percurso.h"
#include "posicao.h"
#include "allegro.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

int main(){

    //inicio do Programa
    // alocação e atribuição para as variaveis principais e de controle


    char opcao=' ';
    int valida=1;
    int achou = 0;
    int ani = 0;
    Percurso *pTra;
    Posicao *inicio = alocaPos();//aloca o inicio
    Posicao *saida = alocaPos();//aloca a posição para saida
    Posicao *mause = alocaPos();//aloca uma posição para o rato
    Labirinto *pLab;
    
    //leitura do terminal
    //pLab = lelabirinto(opcao);
    pLab = abreArquivo();
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
        valida = -1;
    }
    pTra->mCaminho[pTra->mcom].y = saida->x+1;
    pTra->mCaminho[pTra->mcom++].x = saida->y;
    interface(pLab, pTra, ani, valida);

    //desalocação da memoria
    desalocaPos(&inicio);
    desalocaPos(&mause); 
    desalocaPos(&saida);
    desalocaPer(&pTra);
    desalocaLab(&pLab);
    
    //fim do Programa
    return 0;
}

// void interface(Labirinto *pLab, Percurso* pTra, int k){
//     int tam = 920;
//     if(pLab->tamC < 25 || pLab->tamL < 25){
//         tam = 480;
//     }

//     al_init();
//     al_init_font_addon();
//     al_init_image_addon();//função adicionar imagem
        
//     ALLEGRO_DISPLAY * display = al_create_display(tam,tam);
//     al_set_window_position(display, 200, 200);
//     al_set_window_title(display, "Labirinto");

//     ALLEGRO_FONT* font = al_create_builtin_font();
//     ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
//     ALLEGRO_BITMAP *muro = al_load_bitmap("./muro02.png");//pega a imagem do png
//     ALLEGRO_BITMAP *bola = al_load_bitmap("./bola02.png");//pega a imagem do png
//     ALLEGRO_BITMAP *rato = al_load_bitmap("./rato.png");//pega a imagem do png
    
//     ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
//     al_register_event_source(event_queue, al_get_display_event_source(display));
//     al_register_event_source(event_queue, al_get_timer_event_source(timer));
//     al_start_timer(timer);

    
//     while(true){
//     ALLEGRO_EVENT event;
//     al_wait_for_event(event_queue, &event);
//     if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
//       break;
//     }

//     al_clear_to_color(al_map_rgb(255,255,255));
//     al_draw_text(font, al_map_rgb(0, 0, 0), 10, 10, 0, "Labirinto Resovido!");
//     //ponteiro da imagem, posx, posy, flag 0;

//     if(k == pTra->mcom){
//         k = 0;
//         al_rest(1.0);
//         //break;

//     }
    

//     for(int i = 0; i < pLab->tamL ; i++){
//         for(int j = 0; j <  pLab->tamC; j++){
            
//             if(pLab->mapa[i][j] == '*' || pLab->mapa[i][j] == '#'){
//                 al_draw_bitmap(muro, j * 16 + 10,i * 16 + 25 , 0);
//             }else if(pLab->mapa[i][j] == 'o' || pLab->mapa[i][j] == '.'){
//                 al_draw_bitmap(bola, j * 16 + 10,i * 16 + 25 , 0);
//             }else if(pLab->mapa[i][j] == 'm' || pLab->mapa[i][j] == 'M'){
//                 //al_draw_bitmap(rato, pTra->mCaminho[k].y * 16 + 10, pTra->mCaminho[k].x * 16 + 25 , 0);

//             }
            

//         }
        
//     }
//     if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
//       break;
//     }
    
//     al_draw_bitmap(rato, pTra->mCaminho[k].y * 16 + 10, pTra->mCaminho[k].x * 16 + 25 , 0);
    
//     al_rest(0.15);
//     k++;
    
//     // Segura a execução por 10 segundos
//     // al_rest(0.1);

    
//     al_flip_display();
//     }


//     al_destroy_bitmap(rato);
//     al_destroy_bitmap(bola);
//     al_destroy_bitmap(muro);
//     al_destroy_font(font);
//     al_destroy_display(display);
//     al_destroy_event_queue(event_queue);

// }


