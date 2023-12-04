#include <stdbool.h>

#define IMAGE_TYPE 	".png"
#define CARD_BACK	"b"

#define MAX_SUIT 	4
#define MAX_VALUE 	13

int curr_card_visible = true;

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
