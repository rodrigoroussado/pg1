#ifndef __CARDS_H__
#define __CARDS_H__

//Fazer includes
#include "pg/pglib.h"
#include <stdio.h>
#include <stdbool.h>


#define PILETYPE_TOP 0
#define PILETYPE_DOWN 1
#define PILETYPE_MIX 2

#define MAX_CARDS 53

#define MAX_PILES 13

#define MAX_NAIPE 4

typedef struct{
	
	int suit;	//naipe - 0 a 3
	int value;	//valor - 0 a 12
	
	}Card;
	
	
typedef struct{
	
	int nCards;
	Card cards[MAX_CARDS];
	int pileType;	//TOP, DOWN ou MIX
	int nVisible; 	//só usado se pileType = 2 (MIX)
	int x; 		 	//Posição da pilha no board
	int y;
	
	}Pile;
	

typedef struct{
	
	Pile piles[MAX_PILES];
	int nPiles;
	
	}Board;
	


//Função que cria o baralho ordenado num array
void criarBaralhoOrdenado();





#endif
