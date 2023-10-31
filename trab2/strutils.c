#include "strutils.h"
#include <string.h>
 

 
    
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
bool anagram(char str1[], char str2[]) {	//VERIFICAR NOVAMENTE!!!, FAIL NOS TESTES 3, 4 E 5!!!
    
    //Criar um array de MAX_LETRAS contadores para a str1 e outro para str2
    int contador1[MAX_LETRAS];
    int contador2[MAX_LETRAS];
    bool anagrama = true;

    //Limpar os as MAX_LETRAS posições desses arrays, colocando tudo a 0
    for(int i = 0; i < MAX_LETRAS; i++){
		
		contador1[i] = 0;
		contador2[i] = 0;
		
	}
    
    //Percorrer str 1, colocando tudo em maiúsculas e contar as ocorrências de cada letra
    for(int i = 0; str1[i] != '\0'; i++){
		
		if(str1[i] >= 'a' && str1[i] <= 'z'){str1[i] = str1[i] - 'a' + 'A';}
		if(str1[i] >= 'A' && str1[i] <= 'Z'){contador1[str1[i] - 'A']++;}
		
	}
    

    //Percorrer a str2, colocando tudo em maiúsculas e contar as ocorrências de cada letra
    for(int i = 0; str2[i] != '\0'; i++){
		
		if(str2[i] >= 'a' && str2[i] <= 'z'){str2[i] = str2[i] - 'a' + 'A';}
		if(str2[i] >= 'A' && str2[i] <= 'Z'){contador2[str2[i] - 'A']++;}
		
	}
    
    //Comparar os arrays de contadores
		for(int i = 0; i < MAX_LETRAS; i++){
		
			if(contador1[i] != contador2[i]){anagrama = false; break;}
			if(contador1[i] == contador2[i]){anagrama = true; continue;}
			
		}
    
	//Retornar se são anagramas ou não
	return anagrama;
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
bool name_middle_compressed(char orig[], char result[]) {
    //Usar a str_split
    return false;
}

 

/**
 * Descrição:
 *    Esta função coloca no array "words" as palavras (word_t) existentes no array "text" 
 * 	  até ao máximo de size palavras
 * Retorno:
 *    A função retorna o total de palavras colocadas no array "words"
 */
int str_split(char text[], word_t words[], int size) {
	
	//USAR STR_TRIM ANTES PARA GARANTIR QUE NÃO HÁ ESPAÇOS NO INÍCIO/FIM NEM DUPLICADOS NO MEIO!!!

}
