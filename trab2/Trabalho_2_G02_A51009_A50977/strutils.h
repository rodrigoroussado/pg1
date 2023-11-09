#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define MAX_LETRAS 'z' - 'a' +1  //MAX_LETRAS = 26
#define MAX_PALAVRAS 100        // para o codigo do middle_name_compressed
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
void str_trim(char src[], char dst[]);


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
void snake_2_camel_case (char src[], char dst[]);


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
bool anagram(char str1[], char str2[]);



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
bool name_middle_compressed(char orig[], char result[]);




#define MAX_CHARS 32

typedef char word_t[MAX_CHARS+1];

/**
 * Descrição:
 *    Esta função coloca no array "words" as palavras (word_t) existentes no array "text" 
 * 	  até ao máximo de size palavras
 * Retorno:
 *    A função retorna o total de palavras colocadas no array "words"
 */
int str_split(char text[], word_t words[], int size);
