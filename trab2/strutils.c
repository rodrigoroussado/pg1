#include "strutils.h"
    
/**
 * Descrição:
 * 	Cria a string "dst" a partir da string "src", removendo os espaços iniciais e finais 
 *  e mais do que um espaço entre as palavras da string "src"
 * Parâmetros:
 * 	"src": texto original
 *  "dst": texto sem os espaços "a mais" do texto original
 * Retorno:
 * 	Não tem
 */

void str_trim(char src[], char dst[]) {
	
     //"Limpar" os espaços iniciais
   
		//Encontrar a posição em que está a primeira letra na string
		int i = 0;					//Variável usada para percorrer a string "src"
		int j = 0;					//Variável usada para percorrer a string "dst"
		int aux;
		while(src[i] == ' '){i++;}	//Quando o while acaba, i tem o valor da posição da primeira letra da string
		
		
	//"Limpar" os espaços em excesso entre palavras
	
	//Copiar src[] para dst[] até encontrar o terminador
	bool espaco_anterior = false;
	while(src[i] != '\0'){
		
		/*Se encontrar um espaço (sem ter havido espaço anteriormente), "anota" que há um espaço, 
		*copia o espaço e passa à próxima iteração*/
		
		if(src[i] == ' ' && espaco_anterior == false){
			
			espaco_anterior = true;
			dst[j] = src[i];				//Coloca o espaço único em dst[]
			i++; j++;
			continue;
			
			}
		
		/*Se encontrar um espaço (quando há um antes deste), ignora todos os espaços até
		encontrar uma letra e copia esta para dst*/
		
		if(src[i] == ' ' && espaco_anterior == true){
			
			while(src[i] == ' '){i++;}	//i para na posição da primeira letra depois dos espaços
			
			}
				
		espaco_anterior = false;
		aux = j;					//Guarda a posição (para o caso em que a palavra copiada é a última
		dst[j] = src[i];			//Copia o caractere
		i++; j++;
		
	} 
	//Quando este while acaba, j está na primeira posição que pode receber um caractere
	
	/*Neste while, se houverem espaços finais em src[], apenas será copiado para dst[] o último
	 * destes, pelo que, se o último caractere copiado for um espaço, temos de removê-lo*/
	
	
    //"Limpar" o espaço final que resta
    //A variável auxiliar encontra e guarda a posição do terminador
    aux = 0;
    while(dst[aux] != '\0'){aux++;}
    
    //Se atrás do terminador (fim da frase) sobrar um espaço, o terminador
    //"recua", eliminando-o
    if(dst[aux-1] == ' '){dst[aux-1] = '\0';}

}



/**
 * Descrição:
 *    a função  "snake_2_camel_case" coloca na string "dst" a conversão da string "src", em formato snake case (ver https://en.wikipedia.org/wiki/Snake_case),
 *    para formato  Camel Case (ver https://en.wikipedia.org/wiki/Camel_case). 
 *    No caso da string "src" começar e/ou acabar por uma sequência de "_" estes caracteres devems er mantidos na string "dst" 
 * Retorno:
 * 	  Não tem.
 * Exs:
 *    A string em snake case “some_var” será escrita no formato Camel Case como “SomeVar".
 *    A string em snake "case "__var_start_end__with_underscores__" será escrita no formato Camel Case como “__VarStartEndWithUnderscores__".
 *    A string em snake "case "__" será escrita no formato Camel Case como “__".
 */
 
void snake_2_camel_case(char src[], char dst[]) {

    int i = 0;			//Variável usada para percorrer o array src
    int j = 0;			//Variável usada para percorrer o array dst
    bool maiuscula_seguinte = false; //Indica se a letra na posição seguinte tem de ser maiúscula
    
	//Copiar os underscores iniciais para dst[]
	while(src[i] == '_'){dst[j] = src[i]; i++; j++;}
	
	//Copiar a primeira letra (já não há underscores) para dst[]
	dst[j] = src[i];
	i++; j++;
	
	//Retirar os underscores do meio e colocar letras maiúsculas (deixa 1 único underscore no fim se houverem 1 ou +!)
	while(src[i] != '\0'){
		
		if(src[i] == '_'){						//Se encontrar um underscore, "memoriza" para que o próximo caractere seja maiúsculo
			
			maiuscula_seguinte = true;
			i++;
			
		}
		
		else{
			
			if(maiuscula_seguinte == true){		//Se tiver havido um underscore em src na posição anterior, escreve em maiúscula
				
				dst[j] = src[i] - ('a' - 'A');
				maiuscula_seguinte = false;
				
			}
			
			else{								//Senão, copia normalmente
				
				dst[j] = src[i];
				
				}
				
		j++; i++;								//Avançar uma posição em cada um dos arrays
			
		}

	} //No fim do while, i tem a posição do terminador de src e j tem a primeira posição dos underscores finais
	

	//Copiar underscores finais
	
	i = i - 1; 				//Passamos i para o último caractere da string (uma posição atrás do terminador)
	
	while(src[i] == '_'){	//Enquanto houverem underscores em src, copiamos para o final de dst
		
		dst[j] = '_';
		j++;
		i--;
		
		}
		
		
	//Colocar o terminador no fim da string
	dst[j] = '\0';	

}

/**
 * Descrição:
 *		A função "anagram" verifica se as duas strings recebidas em parâmetro são anagramas, 
 * 		ou seja, se têm, exatamente, as mesmas letras (ignorando os espaços), 
 * 		embora os carateres possam estar dispostos  em diferentes posições.
 * 		Na verificação não distinga entre letras maiúsculas e minúsculas. 
 * Parâmetros:
 *		"str1": primeira string a avaliar
 *	    "str2": segunda string a avaliar
 * Retorno:
 *	"true" se as string "str1" e "str2" só contiverem letras (pelo menos duas) e espaços, e forem anagramas, 
 *  "false" caso contrário. 
 * Ex: “setimo ANDAR” e “desmontaria” são anagramas.
 *     "ator" e "rota1" não são anagramas
 */
 
static bool apenasLetras(char str[]){
	
	for(int i = 0; str[i] != '\0'; i++){
		
		char c = str[i];
		
		bool ok = ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' '));
		
		if(ok == false){return false;}
		
	}
	
	return true;
	
}


static bool letrasMinimas(char str[]){
	
	int i = 0;
	int nletras = 0;
	
	while(str[i] != '\0'){
		
		i++;
		
	}
	
	nletras = i;
	
	if(nletras < 2){return false;}
	else{return true;}
	
}
 
 
static void limparContadores(int contador[]){
	
	for(int i = 0; i < MAX_LETRAS; i++){
		
		contador[i] = 0;
		
	}
	
} 
 

bool anagram(char str1[], char str2[]) {
   
    int contador1[MAX_LETRAS];
    int contador2[MAX_LETRAS];
	
	if(str1[0] == '\0' || str2[0] == '\0'){return false;}
	
	if( !(letrasMinimas(str1) && letrasMinimas(str2)) ){return false;}
	
	if( !(apenasLetras(str1) && apenasLetras(str2)) ){return false;}
	
	//Limpar os contadores (colocar os elementos de 0 a MAX_LETRAS - 1 a 0)
	limparContadores(contador1);
	limparContadores(contador2);
	
	//conta quantas letras ha na str1
	for (int i = 0; str1[i] != '\0'; i++) {
		
		char c = str1[i];
		if (c >= 'a' && c <= 'z') {
			
			contador1[c - 'a']++;
            
		}
        
        else{
			if (c >= 'A' && c <= 'Z') {
				
				contador1[c - 'A']++;
			}
		}
	}

	//conta quantas letras ha na str2
	for (int i = 0; str2[i] != '\0'; i++) {
		
		char c = str2[i];
		if (c >= 'a' && c <= 'z') {
			
			contador2[c - 'a']++;
            
		}
		 
		else {
			if (c >= 'A' && c <= 'Z') {
				
				contador2[c - 'A']++;
            
			}
		}
	}

	//compara as duas strings
	for (int i = 0; i < MAX_LETRAS; i++) {
		
		if (contador1[i] != contador2[i]) {
			
			return false;
            
		}
	}

	return true;
}

/**
 * Descrição:
 *	  Gera o formato alternativo para o nome recebido por parâmetro em que apenas 
 * 	  o primeiro nome e o ultimo apelido são apresentados por extenso, estando os nomes 
 * 	  intermédios apresentado na forma de abreviatura.
 * 	  Espaços iniciais e finais e espaços intermédios a mais devem ser eliminados.
 *    Nomes intermédios com 1 ou 2 caracteres são omitidos
 * 	 
 * Parâmetros:
 * 	"orig": nome a converter
 * 	"result": o nome no formato requerido
 * Retorno:
 * 	"true" se o nome for passível de conversão (tem de ter pelo menos um nome próprio e um 
 *   apelido), "false" caso contrário.
 * Exs: 
 *    Se o nome original for:  "  pedro manuel  vieira   rodrigues  ", a conversão é:  "Pedro M. V. Rodrigues".
 *    Se o nome original for:  "  pedro manuel  de  RODRIGUES  ", a conversão é:  "Pedro M. Rodrigues".
 */

static int e_espaco(char c) {
	return c == ' ' || c == '\t' || c == '\n';
}

static void maiuscula(char *str) {
	if (*str >= 'a' && *str <= 'z') {
		
	*str = *str - 'a' + 'A';
	
	}
}

bool name_middle_compressed(char orig[], char result[]) {
	
	//Remover os espaços finais e iniciais - podemos ver o str_trim
	char *inicio = orig;
	
	while (e_espaco(*inicio)) {
		
		++inicio;
	
	}

	char *fim = orig + strlen(orig) - 1;
	while (fim > inicio && e_espaco(*fim)) {
		
		--fim;
	}
	
	//poem o determinador no fim da string
	*(fim + 1) = '\0';   


	//Dibide o nome em varias partes - podemos depois ver se da para usar o str_split
	char *parts[MAX_PALAVRAS];
	int numParts = 0;
	int largura = strlen(inicio);
	int i = 0, j;

	while (i < largura) {
		
		//pula espaços iniciais
		while (i < largura && e_espaco(inicio[i])) {
			
			++i;
            
		}

		//enciontra o fim 
        
		j = i;
		while (j < largura && !e_espaco(inicio[j])) {
			
			++j;
            
		}

		//copia o array
		if (j > i) {
			
			inicio[j] = '\0';
			parts[numParts++] = &inicio[i];
			i = j + 1;
			
		}
		
		else {break;}
		
	}

	//ve se o nome é valido - mais que 2 nomes
	if (numParts < 2) {return false;}

	//Converter o nome para o formato pedido
	int resultLargura = 0;

	//poem em maiuscula a primeira letra de cada parte
	for (i = 0; i < numParts; ++i) {maiuscula(parts[i]);}

	//Escreve o primeiro nome
	resultLargura += sprintf(result + resultLargura, "%s ", parts[0]);

	//comprime os nomes do meio
	for (i = 1; i < numParts - 1; ++i) {
		if (strlen(parts[i]) > 2) {
			resultLargura += sprintf(result + resultLargura, "%c. ", parts[i][0]);
		}
	}

	//escrve o ultimo nome
	sprintf(result + resultLargura, "%s", parts[numParts - 1]);

	return true;
}

/**
 * Descrição:
 *    Esta função coloca no array "words" as palavras (word_t) existentes no array "text" 
 * 	  até ao máximo de size palavras
 * Retorno:
 *    A função retorna o total de palavras colocadas no array "words"
 */
 
int str_split(char text[], word_t words[], int size) {
	
    int contador = 0;
    char *inicio = text;
    char *fim = text;

    while (*fim != '\0' && contador < size) {
		//encontra o inicio da palavra tirando tudo o que ´eespaço e mudanaças de linha ou mesmo tab
        while (*inicio != '\0' && (*inicio == ' ' || *inicio == '\t' || *inicio == '\n')) {
			
            inicio++;
            
        }

        if (*inicio == '\0') {   //caso a string esteja vazia e chegamos ao fim saimos so while
			
            break;
            
        }
		// fim = inicio para começar a ler de onde parou anteriormente para agora encontrat o fim da palavra
        fim = inicio;

        while (*fim != '\0' && (*fim != ' ' && *fim != '\t' && *fim != '\n')) {
			
            fim++;
            
        }

        int largura_word = fim - inicio;


        strncpy (words[contador], inicio, largura_word);    //copia "start" vezes para words 
        words[contador][largura_word] = '\0';             //adiciona \0 no final da string!!

        contador++;                                     //vai sempre interando ate end = \0
        inicio = fim;
    }

    return contador;

}
