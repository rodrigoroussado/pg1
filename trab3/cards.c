//Fazer includes
#include "pg/pglib.h"
#include "graphics.h"
#include "cards.h"
#include <stdio.h>
#include <stdbool.h>


//board_init aqui!


//Variáveis globais
Card c[MAX_CARDS];

int dimC = 0;
	
	

void criarBaralhoOrdenado(){
	
	for(int n = 0; n < MAX_NAIPE; n++){
		
		for(int j = 0; j < MAX_CARDS; j++){
			
			Card x;
			x.suit = n;
			x.value = j;
			c[dimC++] = x;
			
		}
		
	}
	
}
