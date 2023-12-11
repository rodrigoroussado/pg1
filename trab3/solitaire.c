//Fazer includes
#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include "cards.h"



//void mouse(){}
//void timer(){}
Board board;


	

//Main
int main(){
	
	graph_init2("Solitaire", MAX_WIDTH, MAX_HEIGHT);
	//graph_regist_mouse_handler(mouseEventHandler);	//Registar ações do rato
	//graph_regist_timer_handler(timerEventHandler, TIME_TICK);	//Registar ações temporais
	//times_register(timer,TIMER);
	boardInit(board);
	draw_board(/*&board*/); //Função que tem o background_draw dentro!
	graph_start(); //DEFINIR EVENTOS DE RATO AQUI!
	
}
