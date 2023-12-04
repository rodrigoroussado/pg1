//Fazer includes
#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include "cards.h"


//Definir estruturas


//Definir variáveis globais

	

//Main
int main(){
	
	graph_init2("Solitaire", MAX_WIDTH, MAX_HEIGHT);
	//game_init();
	background_draw();
	graph_start(); //DEFINIR EVENTOS DE RATO AQUI!
	
}
