//Fazer includes
#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include "cards.h"
#include "pg/pglib.h"


//Constante para debug



//Definir constantes
#define TIME_TICK_MS 1000 //Período em ms


//Definir variáveis globais
Board board;
int clique_inicial = false;


//Função que retorna true se o clique do rato acontecer em qualquer parte do ecrã de jogo
bool coordenadasEcra(MouseEvent me){
	
	if(me.x > 0 && me.x < 820 && me.y > 0 && me.y < 820){return true;}
	else{return false;}
	
}


void mouseEventHandler(MouseEvent me){
	
	
	if(me.type == MOUSE_BUTTON_EVENT && me.button == BUTTON_LEFT && me.state == BUTTON_CLICK && coordenadasEcra(me)){board.plays++;}
	
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
	draw_board(&board); 											//Desenhar o board
	graph_start(); 													//Inicializar a parte gráfica
	
}
