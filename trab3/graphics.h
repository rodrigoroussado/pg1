#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__


//Fazer includes
#include "pg/pglib.h"
#include "cards.h"
#include <stdio.h>
#include <stdbool.h>


//Definir constantes

/*Tamanho da janela*/
#define MAX_WIDTH 820
#define MAX_HEIGHT 820

/*Definir cores*/
#define BACKGROUND_COLOR graph_rgb(41,153,97)
#define PANEL_COLOR graph_rgb(64,64,64)

/*Painel de informações*/
#define X1_INFO 20
#define Y1_INFO 20
#define INFO_WIDTH 780
#define INFO_HEIGHT 50

/*Zona de stacks*/
#define X1_STACKS 20
#define Y1_STACKS 200
#define STACKS_WIDTH 780
#define STACKS_HEIGHT 600

/*Zona de plays*/
#define X_PLAYS_LABEL 25
#define Y_PLAYS_LABEL 50
#define X_PLAYS_VALUE 115
#define Y_PLAYS_VALUE 50
#define X_PLAYS_RECT 75
#define Y_PLAYS_RECT 25
#define PLAYS_RECT_WIDTH 75
#define PLAYS_RECT_HEIGHT 40

/*Zona de points*/
#define X_POINTS_LABEL 310
#define Y_POINTS_LABEL 50
#define X_POINTS_RECT 370
#define Y_POINTS_RECT 25
#define POINTS_RECT_WIDTH 75
#define POINTS_RECT_HEIGHT 40
#define X_POINTS_VALUE 410
#define Y_POINTS_VALUE 50

/*Zona de temporizador*/
#define X_TIMER_RECT 700
#define Y_TIMER_RECT 25
#define TIMER_RECT_WIDTH 80
#define TIMER_RECT_HEIGHT 40
#define X_TIMER_VALUE 715
#define Y_TIMER_VALUE 50

/*Locais das pilhas*/
#define X_DECK_STACK 20
#define Y_DECK_STACK 85

#define X_DISCARD_STACK 126
#define Y_DISCARD_STACK 85

#define X_FOUNDATION_STACK0 409
#define Y_FOUNDATION_STACK0 85

#define X_FOUNDATION_STACK1 515
#define Y_FOUNDATION_STACK1 85

#define X_FOUNDATION_STACK2 621
#define Y_FOUNDATION_STACK2 85

#define X_FOUNDATION_STACK3 727
#define Y_FOUNDATION_STACK3 85

#define X_CARD_STACK0 53
#define Y_CARD_STACK0 220

#define X_CARD_STACK1 159
#define Y_CARD_STACK1 220

#define X_CARD_STACK2 265
#define Y_CARD_STACK2 220

#define X_CARD_STACK3 371
#define Y_CARD_STACK3 220

#define X_CARD_STACK4 477
#define Y_CARD_STACK4 220

#define X_CARD_STACK5 583
#define Y_CARD_STACK5 220

#define X_CARD_STACK6 689
#define Y_CARD_STACK6 220

/*Tamanho das cartas*/
#define CARD_WIDTH 73
#define CARD_HEIGHT 97

/*Tamanho do nome das cartas*/
#define MAX_CARD_NAME 10

/*Máximo de caracteres para representar os valores dos contadores*/
#define MAX_STRING_PLAYS 4
#define MAX_STRING_TIME 6
#define MAX_STRING_POINTS 4


/*Função que desenha o fundo do tabuleiro de jogo*/
void background_draw();

/*Função que desenha todo o board (elementos estáticos e móveis)*/
void draw_board(Board *board);

/*Função que desenha os contadores de jogadas, pontos e tempo*/
void draw_counters(Board *board);

/*Função que converte um inteiro para char*/
void timeConvert(int valor_int, int *minutos, int *segundos);

/*Função que desenha as cartas do baralho*/
bool draw_cards(Board *board);


#endif
