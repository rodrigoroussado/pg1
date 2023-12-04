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
#define EMPTY_PILE_COLOR_TOP graph_rgb(20,120,50)
#define EMPTY_PILE_COLOR_BOTTOM graph_rgb(82,74,67)

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

#define X_DECK_STACK 20
#define Y_DECK_STACK 85

#define X_DISCARD_STACK 126
#define Y_DISCARD_STACK 85

#define X_FOUNDATION_STACK0 265
#define Y_FOUNDATION_STACK0 85
#define FOUNDATION_STACK0_WIDTH 73
#define FOUNDATION_STACK0_HEIGHT 97

#define X_FOUNDATION_STACK1 371
#define Y_FOUNDATION_STACK1 85
#define FOUNDATION_STACK1_WIDTH 73
#define FOUNDATION_STACK1_HEIGHT 97 //METER ISTO EM RELAÇÃO À PRIMEIRA PILHA!!! SE NÃO LEMBRAR PERGUNTAR JOÃO

#define CARD_WIDTH 73
#define CARD_HEIGHT 97


/*Função que desenha o fundo do tabuleiro de jogo*/
void background_draw();

#endif
