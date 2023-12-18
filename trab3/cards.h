#ifndef __CARDS_H__
#define __CARDS_H__

//Fazer includes
#include "pg/pglib.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h> 

#define PILETYPE_DOWN 0 //mostra a carta
#define PILETYPE_TOP 1 //mostra a back
#define PILETYPE_MIX 2

#define MAX_CARDS 53

#define MAX_PILES 13

#define MAX_SUIT 4
#define MAX_VALUE 13

#define IMAGE_TYPE 	".png"
#define CARD_BACK	"b"
#define DIR_IMAGES "cards/"
#define MAX_FILENAME 100


typedef struct{
	
	int suit;	//naipe - 0 a 3
	int value;	//valor - 0 a 12
	bool visible;
	
	}Card;
	
	
typedef struct{
	
	int nCards;
	Card cards[MAX_CARDS];
	int pileType;	//TOP, DOWN ou MIX
	int nVisible;
	int x; 		 	//Posição da pilha no board
	int y;
	
	}Pile;
	

typedef struct{
	
	int nPiles;
	Pile piles[MAX_PILES];
	int points;
	int plays;
	int tempo_jogo;
	
	}Board;
	
	
	
//Função que inicia o board
void boardInit(Board *board);


//Função que cria o baralho ordenado num array
void criarBaralhoOrdenado();


//Função que transfere x cartas de uma pilha para a outra
bool transferirCarta(Pile *pi, Pile *pf);


//Função que ordena as cartas de forma aleatória
void baralhar();


//Função que regista os eventos do rato
//void mouseEventHandler(MouseEvent me)

//Função que baralha o deck
void shuffle(Pile *pile);


//Função que inicializa uma pile
Pile pileInit(int pileType, int nVisible, int x, int y);


//Função que adiciona uma pile ao board
void addPile(Board *board, Pile pile);


//Função que copia uma pile para outra
void copyCards(Pile pile_inicial, Pile *pile_final);


//Função que escreve uma carta no board
bool writeCard(Card c);


//Função que incrementa os pontos
void incrementarPontos(Board *board);

//Função que procura a carta correspondente à struct
bool getCardName(Card c, char cardName[]);

#endif
