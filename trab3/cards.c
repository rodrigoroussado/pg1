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


bool transferirCarta(Card pilhaInicial[], Card pilhaFinal[], int *dimPI, int *dimPF){
	
	//Verificar se existem elementos na pilha inicial
	if(*dimPI == 0){return false;}
	
	//Copiar elemento da posição dim-1 da pilha inicial para a posição dim da pilha final
	pilhaFinal[*dimPF] = pilhaInicial[(*dimPI)-1];
	
	//Atualizar dim da pilha inicial (dim--)
	*dimPI--;
	
	//Atualizar dim da pilha final (dim++)
	*dimPF++;
	
	return true;
	
}
