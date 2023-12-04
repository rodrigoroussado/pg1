#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

//Fazer includes
#include "pg/pglib.h"
#include <stdio.h>
#include <stdbool.h>


//Definir constantes
#define MAX_WIDTH 820
#define MAX_HEIGHT 820

#define BACKGROUND_COLOR graph_rgb(41,153,97)

#define PANEL_COLOR graph_rgb(64,64,64)
#define INFO_BACKGROUND_COLOR graph_color(210,210,210)

#define X1_INFO 20
#define Y1_INFO 20
#define INFO_WIDTH 780
#define INFO_HEIGHT 50

#define X1_STACKS 20
#define Y1_STACKS 200
#define STACKS_WIDTH 780
#define STACKS_HEIGHT 600

#define X_PLAYS_LABEL 25
#define Y_PLAYS_LABEL 50

#define X_PLAYS_RECT 75
#define Y_PLAYS_RECT 25
#define PLAYS_RECT_WIDTH 75
#define PLAYS_RECT_HEIGHT 40

#define X_POINTS_LABEL 310
#define Y_POINTS_LABEL 50

#define X_POINTS_RECT 370
#define Y_POINTS_RECT 25
#define POINTS_RECT_WIDTH 75
#define POINTS_RECT_HEIGHT 40

#define X_TIMER_RECT 700
#define Y_TIMER_RECT 25
#define TIMER_RECT_WIDTH 80
#define TIMER_RECT_HEIGHT 40

#define CARD_WIDTH 73
#define CARD_HEIGHT 97


/*Função que desenha o fundo do tabuleiro de jogo*/
void background_draw();

#endif
