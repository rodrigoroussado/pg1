//Fazer includes
#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include "cards.h"

Board board = {[],0,0,0};
//void mouse(){}
//void timer(){}



	

//Main
int main(){
	
	graph_init2("Solitaire", MAX_WIDTH, MAX_HEIGHT);
	//mouse_register(mouse);
	//times_register(timer,TIMER);
	boardInit(&board);
	draw_board(&board); //Função que tem o background_draw dentro!
	graph_start(); //DEFINIR EVENTOS DE RATO AQUI!
	
}
