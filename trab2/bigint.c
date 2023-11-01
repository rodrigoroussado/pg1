
#include "bigint.h"

  

/**
 * Descrição:
 * 		retorna o número de dígitos do BIG_INT recebido por parâmetro
 * Parâmetros:
 *     
 * 		b - BIG_INT  
 * Retorno:
 * 		o número de dígitos de "b"
 */
int big_size(const BIG_INT b) {
	return b[0];
}


/**
 * Descrição:
 *   A função apresenta no standard output o BIG_INT recebido por parâmetro
 *  
 * Parâmetros:
 *   big - BIG_INT  a apresentar
 * Retorno:
 *   não tem
 */
void big_show(const BIG_INT big) {
	for(int i = big_size(big); i >=1; i++){ printf("%c",big[i]); }
}

/**
 * Descrição:
 * 		copia um BIG_INT
 * Parâmetros:
 *      bsrc - BIG_INT original
 * 		bcopy - BIG_INT cópia
 * Retorno:
 * 		não tem
 */
void big_copy(const BIG_INT bsrc, BIG_INT bcopy) {
	
    for(int i = 0; i < big_size(bsrc); i++){
		
		bcopy[i] = bsrc[i];
		
		}
}

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
bool big_from_string(char n[], BIG_INT big) {
	 // TO IMPLEMENT
	return false;
}

/**
 * Descrição:
 * 		Inicia um BIG_INT com o valor de um inteiro longo
 * Parâmetros:
 *      n   - inteiro cujo valor deve ser colocado no BIG_INT
 * 		big - BIG_INT que vai conter o valor do inteiro "n"
 * Retorno:
 * 		não tem
 */
void big_from_long(long n, BIG_INT big) {
	
	int contador = 0;
	int i = 1;		//i é inicializado a 1 porque a posição 0 do big é para o seu tamanho (contador)
	int digito;
	
	//Dividir o long por 10 e obter o seu dígito de menor peso (resto da divisão)
	while(n >= 1){
		
		digito = n%10;
		big[i] = digito;
		
		n = n/10;
		contador++;
		
		}
		
	//Inserir o número de dígitos na primeira posição do array big (big[0])
	big[0] = contador;
	
}


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
int big_cmp(const BIG_INT b1, const BIG_INT b2) {
    
    int i = 1;
    int j = 1;
    int diferenca;
    
    //Descobrir posição do dígito de maior peso (última do número no array)
	
    while(i < b1[0]){		//Coloca i na posição do dígito de maior peso de b1
	
		i++;
		
	}
	
	while(j < b2[0]){		//Coloca j na posição do dígito de maior peso de b2
		
		j++;
		
	}
	
    
    
    //Comparar dígito a dígito enquanto b1[i] == b2[i] - maior peso para o menor peso
    while(b1[i] == b2[j]){	//i e j ficam nas respetivas posições em que os elementos são diferentes
		
		i--;
		j--;
		
	}
	
    
    //Quando os dígitos de b1 e b2, numa mesma posição n, forem diferentes, fazer b1[i] - b2[j]
    diferenca = b1[i] - b2[j];
    
    
    //Retornar o valor de diferenca
    return diferenca;
	
}



/**
 * Descrição:
 *   A função calcula a soma de dois BIG_INT guardando-a num terceiro BIG_INT  
 * Parâmetros:
 *   b1 - primeiro operando BIG_INT  
 *   b2 - segundo  operando BIG_INT  
 *   bm - BIG_INT que guarda  o resultado
 * Retorno:
 *   A função retorna false se ocorrer overflow, isto é, se 
 *   a soma não couber no máximo de dígitos permitido.
 *   A função retorna true se a operação for bem sucedida.
 */
bool big_add(const BIG_INT b1, const BIG_INT b2, BIG_INT bm){
	
	int i = 1;
	int tamanho_bm = 0; //Variável usada para colocar o número de dígitos de bm em bm[0]
	bool carry = false; //Variável usada para controlar a existência de carry na soma
	
	//Determinar qual o big int mais pequeno
	if(big_size(b1) > big_size(b2)){
		
		//Fazer a soma
		while(i < big_size(b2)){
			
			if(i >= 255){
				
				break;
				return false;
				
			}
			
			if(carry == true){
				
				bm[i] = b1[i] + b2[i] + 1;
				carry = false;
				
			}
			
			else{
				
				bm[i] = b1[i] + b2[i];
				
			}
			
			if(bm[i] >= 10){
				
				bm[i] = bm[i] - 10;
				carry = true;
				
			}
			
			i++;
			tamanho_bm++;
			
		}
		
		//Copiar para bm o resto dos dígitos de b1
		while(i < big_size(b1)){
			
			bm[i] = b1[i];
			i++;
			
		}
		
	}
	else{
		
		if(big_size(b1) < big_size(b2)){
			
		//Fazer a soma
		while(i < big_size(b1)){
			
			if(i >= 255){
				
				break;
				return false;
				
			}
			
			if(carry == true){
				
				bm[i] = b1[i] + b2[i] + 1;
				carry = false;
				
			}
			
			else{
				
				bm[i] = b1[i] + b2[i];
				
			}
			
			if(bm[i] >= 10){
				
				bm[i] = bm[i] - 10;
				carry = true;
				
			}
			
			i++;
			tamanho_bm++;
			
		}
		
		//Copiar para bm o resto dos dígitos de b2
		while(i < big_size(b2)){
			
			bm[i] = b2[i];
			i++;
			
		}
			
		}
		else{	//Caso em que os big ints têm o mesmo tamanho
			
			//Fazer a soma
			while(i < big_size(b2)){
			
				if(i >= 255){
				
					break;
					return false;
				
				}
			
				if(carry == true){
				
					bm[i] = b1[i] + b2[i] + 1;
					carry = false;
				
				}
			
				else{
				
					bm[i] = b1[i] + b2[i];
				
				}
			
				if(bm[i] >= 10){
				
					bm[i] = bm[i] - 10;
					carry = true;
				
				}
			
				i++;
				tamanho_bm++;
			}
		}	
		
	}
	
	bm[0] = tamanho_bm;
	return true;
}

/**
 * Descrição:
 *   A função multiplica um BIG_INT por um inteiro (de 0 a 9) guardando
 *   o resultado noutro BIG_INT 
 * Parâmetros:
 *   b - primeiro BIG_INT
 *   n - valor inteiro longo
 *   bres  - resultado da multiplicação
 * Retorno:
 *   A função retorna true ou false se sucesso ou insucesso ("overlfow")
 */	
bool big_mul_dig(const BIG_INT b, int d, BIG_INT bres) {
	 // TO IMPLEMENT
	return false;
		
}
 

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
bool big_mul_10(BIG_INT b) {
    
	
	return true;
}



// AS FUNÇÔES ABAIXO SÂO OPCIONAIS
// SENDO NATURALMENTE VALORIZADA A SUA CORRETA REALIZAÇÂO

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
bool  big_mul_pow_10(BIG_INT b, int exp) {
    // TO IMPLEMENT
	return false;
}


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
bool big_mul(const BIG_INT b1, const BIG_INT b2, BIG_INT bm) {
    // TO IMPLEMENT
	return false;
}
 
 
