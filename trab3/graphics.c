//Fazer includes
#include "pg/pglib.h"
#include "graphics.h"
#include <stdio.h>
#include <stdbool.h>

//Desenhar o tabuleiro
void background_draw(){
	
	graph_rect(0, 0, MAX_WIDTH, MAX_HEIGHT, BACKGROUND_COLOR, true); 			//Fundo
	graph_rect(X1_INFO, Y1_INFO, INFO_WIDTH, INFO_HEIGHT, PANEL_COLOR, true);    		//Painel de informações
	graph_rect(X1_STACKS, Y1_STACKS, STACKS_WIDTH, STACKS_HEIGHT, PANEL_COLOR, true);  //Zona de stacks
	
	graph_text2(X_PLAYS_LABEL,Y_PLAYS_LABEL, c_orange, PANEL_COLOR, "Plays", MEDIUM_FONT);
	graph_rect(X_PLAYS_RECT, Y_PLAYS_RECT, PLAYS_RECT_WIDTH, PLAYS_RECT_HEIGHT, c_gray, true);
	
	graph_text2(X_POINTS_LABEL, Y_POINTS_LABEL, c_orange, PANEL_COLOR, "Points", MEDIUM_FONT);
	graph_rect(X_POINTS_RECT, Y_POINTS_RECT, POINTS_RECT_WIDTH, POINTS_RECT_HEIGHT, c_gray, true);
	
	graph_rect(X_TIMER_RECT, Y_TIMER_RECT, TIMER_RECT_WIDTH, TIMER_RECT_HEIGHT, c_gray, true);
	
	return;
	
}
