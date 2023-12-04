//Fazer includes
#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include "cards.h"

//Board board; com a informação das cartas, baralhos, etc.
//void mouse(){}
//void timer(){}


//Definir estruturas


//Definir variáveis globais

	

//Main
int main(){
	
	graph_init2("Solitaire", MAX_WIDTH, MAX_HEIGHT);
	//mouse_register(mouse);
	//times_register(timer,TIMER);
	//boardInit();
	background_draw(/*&board*/);
	graph_start(); //DEFINIR EVENTOS DE RATO AQUI!
	
}
