/*------------------------------------------------------------
 * Contem funções para efectuar cálculos com inteiros "grandes"
 *------------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


// máximo de dígitos num big integer
#define MAX_DIGITS 255

typedef unsigned char byte;


typedef byte BIG_INT[MAX_DIGITS+1];


/**
 * Descrição:
 * 		retorna o número de dígitos do BIG_INT recebido por parâmetro
 *      esta função já está implementada
 * Parâmetros:
 *     
 * 		b - BIG_INT  
 * Retorno:
 * 		o número de dígitos de "b"
 */
int big_size(const BIG_INT b);



/**
 * Descrição:
 *   A função apresenta no standard output o BIG_INT recebido por parâmetro
 *  
 * Parâmetros:
 *   big - BIG_INT  a apresentar
 * Retorno:
 *   não tem
 */
void big_show(const BIG_INT big);



/**
 * Descrição:
 * 		copia um BIG_INT
 * Parâmetros:
 *      bsrc - BIG_INT original
 * 		bcopy - BIG_INT cópia
 * Retorno:
 * 		não tem
 */
void big_copy(const BIG_INT bsrc, BIG_INT bcopy);
	 

/**
 * Descrição:
 * 		Inicia um BIG_INT com o valor de um inteiro longo
 * Parâmetros:
 *      n   - inteiro cujo valor deve ser colocado no BIG_INT
 * 		big - BIG_INT que vai conter o valor do inteiro "n"
 * Retorno:
 * 		não tem
 */
void big_from_long(long n, BIG_INT big);
	 

/**
 * Descrição:
 *   A função preenche um BIG_INT a partir de uma string com a representação de um valor inteiro  
 * Parâmetros:
 *   n - string de caracteres numéricos.
 *   big - BIG_INT a construir a partir de "n"
 * Retorno:
 *   A função retorna true se construiu o BIG_INT "big" com sucesso ou false 
 *   se foi encontrado algum caracter não numérico  
 */
bool big_from_string(char n[], BIG_INT big);
	 


/**
 * Descrição:
 *   A função compara dois BIG_INT e retorna um valor negativo, zero
 *   ou um valor positivo consoante o primeiro seja menor, igual ou superior ao segundo 
 * Parâmetros:
 *   b1 - primeiro BIG_INT
 *   b2 - segundo BIG_INT
 * Retorno:
 *    valor negativo -> b1 < b2
 *    0              -> b1 == b2
 *    valor positivo -> b1 > b2
 */
int big_cmp(const BIG_INT b1, const BIG_INT b2);
	 



/**
 * Descrição:
 *   A função calcula a soma de dois BIG_INT guardando-a num terceiro BIG_INT  
 * Parâmetros:
 *   b1 - primeiro operando BIG_INT  
 *   b2 - segundo  operando BIG_INT  
 *   bm - BIG_INT que guarda  o resultado
 * Retorno:
 *   A função retorna false se ocorrer overflow, isto é se 
 *   a soma não couber no máximo de dígitos permitido.
 *   A função retorna true se a operação for bem sucedida.
 */
bool big_add(const BIG_INT b1, const BIG_INT b2, BIG_INT bm);
	 


/**
 * Descrição:
 *   A função multiplica um BIG_INT por um número entre 0 e 9, guardando
 *   o resultado noutro BIG_INT 
 *   e o resultado é  colocado no terceiro
 * Parâmetros:
 *   b - primeiro BIG_INT
 *   d - valor entre 0 e 9
 *   bres  - resultado da multiplicação
 * Retorno:
 *   A função retorna true ou false se sucesso ou insucesso 
 *   (se "overlfow" ou o número "d" não estiver contido entre 0 e 9)
 */	
bool big_mul_dig(const BIG_INT b, int d, BIG_INT bres);
	
    
// AS FUNÇÔES ABAIXO SÂO OPCIONAIS
// SENDO NATURALMENTE VALORIZADA A SUA CORRETA REALIZAÇÂO

/**
 * Descrição:
 *   A função  multiplica o bigint "b" por 10
 * Parâmetros
 *   b: bigint a multiplicar por 10
 * Retorno
 *   A função retorna false se ocorrer overflow, isto é, se 
 *   a soma não couber no máximo de dígitos permitido.
 *   A função retorna true se a operação for bem sucedida.
 */
bool big_mul_10(BIG_INT b);


/**
 * Descrição:
 *   A função  multiplica o bigint "b" pela potência de 10 de expoente "exp"
 * Parâmetros
 *   b: bigint a multiplicar por 10 elevado a "exp"
 * Retorno
 *   A função retorna false se ocorrer overflow, isto é, se 
 *   a soma não couber no máximo de dígitos permitido.
 *   A função retorna true se a operação for bem sucedida.
 */
bool big_mul_pow_10(BIG_INT b, int exp);
 

/**
 * Descrição:
 *   A função recebe três BIG_INT:  os dois primeiros são os operandos da multiplicação
 *   e o resultado é  colocado no terceiro
 * Parâmetros:
 *   b1 - primeiro BIG_INT
 *   b2 - segundo BIG_INT.
 *   bm  - resultado da multiplicação
 * Retorno:
 *   A função retorna true ou false se sucesso ou insucesso ("overflow")
 */	
bool big_mul(const BIG_INT b1, const BIG_INT b2, BIG_INT bm);

