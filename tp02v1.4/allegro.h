#ifndef ALLEGRO_H
#define ALLEGRO_H


#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#define TAM 21
#define TAM2 50



int inicializar();

void manipular_entrada(ALLEGRO_EVENT event, char *str);

void exibir_texto(char str[TAM], ALLEGRO_FONT *font);

void interface(Labirinto *pLab, Percurso* pTra, int k, int achou);

Labirinto* abreArquivo();

#endif // PERCURSO_H
