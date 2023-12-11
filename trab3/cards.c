//Fazer includes
#include "pg/pglib.h"
#include "graphics.h"
#include "cards.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>


//Variáveis globais
int curr_card_visible = true;


void addPile(Board *board, Pile pile){
	
	board->piles[board->nPiles++] = pile;
	
}


void shuffle(Pile *p){
	
	//Dar a seed para a geração aleatória baseada na hora
	srand(time(NULL));
	
	//Percorrer o array de cartas (baralho ordenado)
	for(int i = p->nCards; i > 0; i--){
		
		//Gerar um número aleatório (índice do array da carta que vai ser trocada com a da posição i)
		int j = rand() % (i+1);
		
		//Trocar a posição das cartas da posição i e j
		Card aux = p->cards[i];
		p->cards[i] = p->cards[j];
		p->cards[j] = aux;
		
	}
	
}


void copyCards(Pile pile_inicial, Pile *pile_final){
	
	for(int i = 0; i < pile_inicial.nCards; i++){
		
		pile_final->cards[i] = pile_inicial.cards[i];
		
	}
	
}

Pile pileInit(int pileType, int nVisible, int x, int y){
	
	Pile p;
	p.pileType = pileType;
	p.nVisible = nVisible;
	p.x = x;
	p.y = y;
	p.nCards = 0;
	
	return p;
	
}
	
void boardInit(Board *board){

	
	board->nPiles = 0;
	board->plays = 0;
	board->points = 0;
	
	addPile(board, pileInit(PILETYPE_DOWN, 0, X_DECK_STACK, Y_DECK_STACK));
 	criarBaralhoOrdenado(&board->piles[0]);
	shuffle(&board->piles[0]);

}


void criarBaralhoOrdenado(Pile *p){
	
	for(int n = 0; n < p->nCards; n++){
		
		for(int j = 0; j < p->nCards; j++){
			
			Card x;
			x.suit = n;
			x.value = j;
			p->cards[p->nCards++] = x;
			
		}
		
	}
	
}


bool transferirCarta(Pile *pi, Pile *pf){ 
	
	//Verificar se existem elementos na pilha inicial
	if(pi->nCards == 0){return false;}
	
	//Copiar elemento da posição dim-1 da pilha inicial para a posição dim da pilha final
	pf->cards[pf->nCards] = pi->cards[(pi->nCards)];
	
	//Atualizar nCards da pilha inicial (dim--)
	pi->nCards--;
	
	//Atualizar nCards da pilha final (dim++)
	pf->nCards++;
	
	return true;
	
}



bool getCardName(int suit, int value, bool visible, char cardName[]) {
	
	//Buscar os nipes ( d = ouros; h = copas; c= paus; s = espadas)
	char suits[] = { 'd', 'h', 's', 'c' };	
	
	//Buscar os 13 valores	( t = 10; q = rainha; j = valete; k = rei; a = Ás)								
	char values[] = { '2','3','4','5','6','7','8','9','t','q','j','k','a'};

	//Se a carta não for visivel damos print na carta virada ao contrario
	//Em que o primeiro %s é o nipe e o segundo %s é o valor
	//Neste caso o %s sendo a parte de tras da carta será "b" e nao terá valor logo o segundo %s refere o tipo da imagem (.png)
  	if ( !visible ) sprintf(cardName, "%s%s", CARD_BACK, IMAGE_TYPE);
  	

  	else {

		//Se os valores nao tiverem dentro dos intervalos damos false
		if ( suit < 0 || suit >= MAX_SUIT || value < 0 || value >= MAX_VALUE ) {return false;}
		
		//Se passar por todos os testes escrevemos a carta
		//Aqui o priemiro %c sera o nipe, o segundo %c será o valor e o %s sera o tipo da imagem (.png)
		sprintf(cardName, "%c%c%s", suits[suit], values[value], IMAGE_TYPE);
	}
	return true;
}

