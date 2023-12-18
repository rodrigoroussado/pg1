//Fazer includes
#include "pg/pglib.h"
#include "graphics.h"
#include <stdio.h>
#include <stdbool.h>


//Desenhar o tabuleiro
void background_draw(){
	
	graph_rect(0, 0, MAX_WIDTH, MAX_HEIGHT, BACKGROUND_COLOR, true); 					//Fundo
	graph_rect(X1_INFO, Y1_INFO, INFO_WIDTH, INFO_HEIGHT, PANEL_COLOR, true);    		//Painel de informações
	graph_rect(X1_STACKS, Y1_STACKS, STACKS_WIDTH, STACKS_HEIGHT, PANEL_COLOR, true);  	//Zona de stacks
	
	//Zona de informação de "Plays"
	graph_text2(X_PLAYS_LABEL,Y_PLAYS_LABEL, c_orange, PANEL_COLOR, "Plays", MEDIUM_FONT);
	graph_rect(X_PLAYS_RECT, Y_PLAYS_RECT, PLAYS_RECT_WIDTH, PLAYS_RECT_HEIGHT, c_gray, true);
	
	//Zona de informação de "Points"
	graph_text2(X_POINTS_LABEL, Y_POINTS_LABEL, c_orange, PANEL_COLOR, "Points", MEDIUM_FONT);
	graph_rect(X_POINTS_RECT, Y_POINTS_RECT, POINTS_RECT_WIDTH, POINTS_RECT_HEIGHT, c_gray, true);
	
	//Zona de informação de tempo
	graph_rect(X_TIMER_RECT, Y_TIMER_RECT, TIMER_RECT_WIDTH, TIMER_RECT_HEIGHT, c_gray, true);
	
	//Sombras (stacks vazias)
	graph_rect(X_DECK_STACK, Y_DECK_STACK, CARD_WIDTH, CARD_HEIGHT, c_white, false); 		//Deck Stack
	graph_rect(X_DISCARD_STACK, Y_DISCARD_STACK, CARD_WIDTH, CARD_HEIGHT, c_white, false);  //Discard Stack
	
	graph_rect(X_FOUNDATION_STACK0, Y_FOUNDATION_STACK0, CARD_WIDTH, CARD_HEIGHT, c_white, false);
	graph_rect(X_FOUNDATION_STACK1, Y_FOUNDATION_STACK1, CARD_WIDTH, CARD_HEIGHT, c_white, false);
	graph_rect(X_FOUNDATION_STACK2, Y_FOUNDATION_STACK2, CARD_WIDTH, CARD_HEIGHT, c_white, false);
	graph_rect(X_FOUNDATION_STACK3, Y_FOUNDATION_STACK3, CARD_WIDTH, CARD_HEIGHT, c_white, false);
	
	graph_rect(X_CARD_STACK0, Y_CARD_STACK0, CARD_WIDTH, CARD_HEIGHT, c_white, false);
	graph_rect(X_CARD_STACK1, Y_CARD_STACK1, CARD_WIDTH, CARD_HEIGHT, c_white, false);
	graph_rect(X_CARD_STACK2, Y_CARD_STACK2, CARD_WIDTH, CARD_HEIGHT, c_white, false);
	graph_rect(X_CARD_STACK3, Y_CARD_STACK3, CARD_WIDTH, CARD_HEIGHT, c_white, false);
	graph_rect(X_CARD_STACK4, Y_CARD_STACK4, CARD_WIDTH, CARD_HEIGHT, c_white, false);
	graph_rect(X_CARD_STACK5, Y_CARD_STACK5, CARD_WIDTH, CARD_HEIGHT, c_white, false);
	graph_rect(X_CARD_STACK6, Y_CARD_STACK6, CARD_WIDTH, CARD_HEIGHT, c_white, false);
	
	return;
	
}


void draw_board(Board *board){
	
	background_draw(); 	 //Desenhar os elementos estáticos
	draw_counters(*board);   //Desenhar os contadores de pontos, jogadas e tempo
	//draw_cards(board);
	
}



void draw_counters(Board board){
	
	//Plays
	char string_plays[MAX_STRING_PLAYS];
	sprintf(string_plays, "%d", board.plays);
	graph_text2(X_PLAYS_VALUE, Y_PLAYS_VALUE, c_black, c_gray, string_plays, MEDIUM_FONT);
	
	//Time
	char string_time[MAX_STRING_TIME];
	int minutos = 0;
	int segundos = 0;
	timeConvert(board.tempo_jogo, &minutos, &segundos);
	sprintf(string_time, "%02d:%02d", minutos, segundos);
	graph_text2(X_TIMER_VALUE, Y_TIMER_VALUE, c_black, c_gray, string_time, MEDIUM_FONT);
	
	//Points
	
}


void timeConvert(int valor_int, int *minutos, int *segundos){
	
	*minutos = valor_int/60;
	*segundos = valor_int%60;

}
