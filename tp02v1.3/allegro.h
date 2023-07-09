#ifndef ALLEGRO_H
#define ALLEGRO_H


#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#define TAM 51



int inicializar();

void manipular_entrada(ALLEGRO_EVENT event, char *str);

void interface(Labirinto *pLab, Percurso* pTra, int k);

#endif // PERCURSO_H
