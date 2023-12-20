//Fazer includes
#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include "cards.h"
#include "pg/pglib.h"


//Constante para debug



//Definir constantes
#define TIME_TICK_MS 1000 //Período em ms
#define DEBUG 0

//Definir variáveis globais
Board board;
int clique_inicial = false;


int getPile(Board *board, int x, int y){
	
	#if DEBUG
	printf("Mouse: %d %d\n", x, y);
	#endif
	
	for(int i = 0; i < board->nPiles; i++){
		
		#if DEBUG
		printf("%d %d %d\n", i, board->piles[i].x, board->piles[i].y);
		#endif
		
		if(board->piles[i].pileType != PILETYPE_MIX){
			if(x > board->piles[i].x && x < board->piles[i].x + CARD_WIDTH && 
				y > board->piles[i].y && y < board->piles[i].y + CARD_HEIGHT)return i;
		}
		
	}
	
	return -1;
	
	
}


void mouseEventHandler(MouseEvent me){
	
	if(me.type == MOUSE_BUTTON_EVENT && me.button == BUTTON_LEFT && me.state == BUTTON_CLICK){
		board.plays++;
		int auxPile = getPile(&board, me.x, me.y);
		
		#if DEBUG
		printf("auxPile = %d\n", auxPile);
		#endif
		
		if(auxPile == 0){
			transferirCarta(&board, 0, 1);
			draw_board(&board);
		}
	}
	
}


void timerEventHandler(MouseEvent me){
	
	if(board.plays >= 1){clique_inicial = true;}
	if(clique_inicial == true){board.tempo_jogo++;}
	draw_board(&board);
	
}
	

//Main
int main(){
	
	graph_init2("Solitaire", MAX_WIDTH, MAX_HEIGHT); 				//Iniciar uma janela gráfica com o título e tamanho especificados
	graph_regist_mouse_handler(mouseEventHandler); 					//Registar eventos do rato
	graph_regist_timer_handler(timerEventHandler, TIME_TICK_MS); 	//Registar eventos de tempo (a cada TIME_TICK_MS em milissegundos)
	boardInit(&board); 												//Inicializar o board
	background_draw();
	draw_board(&board); 											//Desenhar o board
	graph_start(); 													//Inicializar a parte gráfica
	
}
