//Fazer includes
#include "pg/pglib.h"
#include "graphics.h"
#include "cards.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#define DEBUG 1


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
	board->tempo_jogo = 0;
	
	addPile(board, pileInit(PILETYPE_DOWN, 0, X_DECK_STACK, Y_DECK_STACK)); //Deck pile
 	criarBaralhoOrdenado(&board->piles[0]);
	shuffle(&board->piles[0]);

	addPile(board, pileInit(PILETYPE_TOP, 1, X_DISCARD_STACK, Y_DISCARD_STACK)); //Discard pile
	
	addPile(board, pileInit(PILETYPE_TOP, 0, X_FOUNDATION_STACK0, Y_FOUNDATION_STACK0));
	addPile(board, pileInit(PILETYPE_TOP, 0, X_FOUNDATION_STACK1, Y_FOUNDATION_STACK1));
	addPile(board, pileInit(PILETYPE_TOP, 0, X_FOUNDATION_STACK2, Y_FOUNDATION_STACK2));
	addPile(board, pileInit(PILETYPE_TOP, 0, X_FOUNDATION_STACK3, Y_FOUNDATION_STACK3));
	
	addPile(board, pileInit(PILETYPE_MIX, 1, X_CARD_STACK0, Y_CARD_STACK0));
	addPile(board, pileInit(PILETYPE_MIX, 1, X_CARD_STACK1, Y_CARD_STACK1));
	addPile(board, pileInit(PILETYPE_MIX, 1, X_CARD_STACK2, Y_CARD_STACK2));
	addPile(board, pileInit(PILETYPE_MIX, 1, X_CARD_STACK3, Y_CARD_STACK3));
	addPile(board, pileInit(PILETYPE_MIX, 1, X_CARD_STACK4, Y_CARD_STACK4));
	addPile(board, pileInit(PILETYPE_MIX, 1, X_CARD_STACK5, Y_CARD_STACK5));
	addPile(board, pileInit(PILETYPE_MIX, 1, X_CARD_STACK6, Y_CARD_STACK6));
	

}


void criarBaralhoOrdenado(Pile *p){
	
	p->nCards = 0;
	
	for(int n = 0; n < MAX_SUIT; n++){
		
		for(int j = 0; j < MAX_VALUE; j++){
			
			Card x;
			x.suit = n;
			x.value = j;
			p->cards[p->nCards++] = x;
			
		}
		
	}
	
}


bool transferirCarta(Board *board, int ind_pi, int ind_pf){ 
	
	#if DEBUG
	printf("Transferir %d %d\n", ind_pi, ind_pf);
	printf("Dimensões Iniciais %d %d\n", board->piles[ind_pi].nCards, board->piles[ind_pf].nCards);
	#endif
	
	//Verificar se existem elementos na pilha inicial
	if(board->piles[ind_pi].nCards == 0){return false;}
	
	//Copiar elemento da posição dim da pilha inicial para a posição dim da pilha final
	board->piles[ind_pf].cards[board->piles[ind_pf].nCards].visible = true;
	
	board->piles[ind_pf].cards[board->piles[ind_pf].nCards++] = board->piles[ind_pi].cards[board->piles[ind_pi].nCards--];
	
	
	#if DEBUG
	printf("Dimensões Finais %d %d\n", board->piles[ind_pi].nCards, board->piles[ind_pf].nCards);
	#endif
	
	return true;
	
}


void incrementarPontos(Board *board){
	
	board->points++;
	
}


bool getCardName(Card c, char cardName[]) {
	char suits[] = { 'd', 'h', 's', 'c' };
	char values[] = { '2','3','4','5','6','7','8','9','t','q','j','k','a'};

  	if (  c.visible ) sprintf(cardName, "%s%s", CARD_BACK, IMAGE_TYPE);
  	else {
	  if ( c.suit < 0 || c.suit >= MAX_SUIT || c.value < 0 || c.value >= MAX_VALUE ) return false;
	  sprintf(cardName, "%c%c%s", suits[c.suit], values[c.value], IMAGE_TYPE);
	}
	return true;
}
