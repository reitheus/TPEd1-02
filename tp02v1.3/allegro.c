#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "labirinto.h"
#include "percurso.h"
#include "posicao.h"
#include "allegro.h"

int inicializar(){

    al_init();
    al_init_font_addon();
    al_init_image_addon();//função adicionar imagem

    return 1;

}


void manipular_entrada(ALLEGRO_EVENT event, char *str){

    if (event.type == ALLEGRO_EVENT_KEY_CHAR){
        if (strlen(str) <= 16){
            char temp[] = {event.keyboard.unichar, '\0'};
            if (event.keyboard.unichar == ' '){
                strcat(str, temp);
            }
            else if (event.keyboard.unichar >= '0' && event.keyboard.unichar <= '9'){
                strcat(str, temp);
            }
            else if (event.keyboard.unichar >= 'A' && event.keyboard.unichar <= 'Z'){
                strcat(str, temp);
            }
            else if (event.keyboard.unichar >= 'a' && event.keyboard.unichar <= 'z'){
                strcat(str, temp);
            }
        }
 
        if (event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && strlen(str) != 0){
            str[strlen(str) - 1] = '\0';
        }
    }

    
}

void interface(Labirinto *pLab, Percurso* pTra, int k, int achou){
    int tam = 920;
    int posLabX = 10, posLabY = 40;
    char texto[TAM];
    char modo[TAM2];
    if(pLab->tamC < 25 || pLab->tamL < 25){
        tam = 480;
    }

    inicializar();
    

    switch(pLab->op){
        case 'r':
             strcpy(modo, "Achou saida Utilizando Recursão");
        break;
        case 'p':
             strcpy(modo, "Achou saida Utilizando Pilha");
        break;
        case 'f':
             strcpy(modo, "Achou saida Utilizando Fila");
        break;

    }

    ALLEGRO_DISPLAY * display = al_create_display(tam,tam);
    al_set_window_position(display, 200, 200);
    al_set_window_title(display, "Labirinto");

    ALLEGRO_FONT *font = al_create_builtin_font();
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_BITMAP *muro = al_load_bitmap("./muro02.png");//pega a imagem do png
    ALLEGRO_BITMAP *bola = al_load_bitmap("./bola02.png");//pega a imagem do png
    ALLEGRO_BITMAP *rato = al_load_bitmap("./rato.png");//pega a imagem do png
    
    ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    int saida = 0;
    while(saida == 0){
    ALLEGRO_EVENT event;
    
    while(!al_is_event_queue_empty(event_queue)){
        al_wait_for_event(event_queue, &event);
        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
            printf("fechar");
            saida = 1;
            break;
        }
    }

    al_clear_to_color(al_map_rgb(255,255,255));
    
    //ponteiro da imagem, posx, posy, flag 0;

    if(k == pTra->mcom){
        k = 0;
        al_rest(0.5);
        //break;

    }
    

    if(achou > 0){
        al_draw_text(font, al_map_rgb(0, 0, 0), 10, 10, 0, "Labirinto Resovido!");//escreve na tela
        al_draw_text(font, al_map_rgb(0, 0, 0), 10, 25, 0, modo);

        for(int i = 0; i < pLab->tamL ; i++){
            for(int j = 0; j <  pLab->tamC; j++){
                
                if(pLab->mapa[i][j] == '*' || pLab->mapa[i][j] == '#'){
                    al_draw_bitmap(muro, j * 16 + posLabX,i * 16 + posLabY , 0);
                }else if(pLab->mapa[i][j] == 'o' || pLab->mapa[i][j] == '.'){
                    al_draw_bitmap(bola, j * 16 + posLabX,i * 16 + posLabY , 0);
                }
                
            }
            
        }
        al_draw_bitmap(rato, pTra->mCaminho[k].y * 16 + posLabX, pTra->mCaminho[k].x * 16 + posLabY , 0);
        al_rest(0.15);
        k++;
    }else{
        al_draw_text(font, al_map_rgb(0, 0, 0), 10, 15, 0, "EPIC FAIL");
        al_draw_text(font, al_map_rgb(0, 0, 0), 10, 30, 0, "Labirinto sem Saída");
    }
    
    // Segura a execução por 10 segundos
    // al_rest(0.1);

    
    al_flip_display();
    }


    al_destroy_bitmap(rato);
    al_destroy_bitmap(bola);
    al_destroy_bitmap(muro);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

}


