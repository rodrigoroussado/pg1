
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
	for(int i = big_size(big); i != 0; i--){ printf("%d",big[i]); }
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
	
    for(int i = 0; i <= big_size(bsrc); i++){
		
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
	
	int tamanho = 0;
	int posicao_terminador = 0;
	int j = 0;		//Variável usada para colocar os valores em big
	
	for(int i = 0; n[i] != '\0'; i++){posicao_terminador++;}
	
	if(n[0] == '\0'){return false;}
	
	for(int i = posicao_terminador - 1; i >= 0; i--){
		
		if(n[i] >= '0' && n[i] <= '9'){
		
			big[j+1] = n[i] - '0'; 		//i + 1 porque deixamos um espaço (big[0]) para colocar o tamanho do big int
			
			tamanho++;
			
		}
		
		else{return false;}
		
		j++;
	}
	
	big[0] = tamanho;
	
	return true;
	
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
 
static int digitosReais (const BIG_INT b){
	
	int zeros = 0;
	int tamanhoReal = big_size(b);
	
	for(int i = big_size(b); b[i] == 0; i--){zeros++;}
		
		tamanhoReal -= zeros;
		
		return tamanhoReal; 

}
 
int big_cmp(const BIG_INT b1, const BIG_INT b2) {
    
    int diferenca;
    
    //b1 > b2
	if( digitosReais(b1) > digitosReais(b2) ){return 1;}
		
	else{
		
		//b1 < b2
		if( digitosReais(b1) < digitosReais(b2) ){return -1;}
		
		else{
			
			//b1 == b2
			for(int i = digitosReais(b1); i != 0; i--){
			
				diferenca = b1[i] - b2[i];
				
				if(diferenca != 0){return diferenca;}
			}
		}
	}
	
	return 0;
	
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
 
bool big_add(const BIG_INT b1, const BIG_INT b2, BIG_INT bm) {
	
	int carry = 0;
	int tamanho_bm;
	
    //Descobrir qual é o maior entre b1 e b2
	if ( big_size(b1) > big_size(b2) ) {
		tamanho_bm = big_size(b1);
	}
		
	else {
		
		tamanho_bm = big_size(b2);
    
	}
	
	//Percorrer o array para ir fazendo as somas com o respetivo carry
	for (int i = 1; i <= tamanho_bm; i++) {
		
		int c = carry;
		
		if ( i <= big_size(b1) ){c += b1[i];}
        
		if ( i <= big_size(b2) ){c += b2[i];}

		carry = c / 10;
		bm[i] = c % 10;
	}
    
	//Aumentar sempre 1 no tamanho da array quando o carry for 1
	if (carry == 1) {
		
		bm[tamanho_bm + 1] = carry;
		
		tamanho_bm++;
	}
    
	//Retorna falso caso tenha havido OVERFLOW
	if( bm[tamanho_bm + 1] >= MAX_DIGITS ){return false;}
	
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
	
	big_copy(b,bres);
	
    // Verifica se d é válido (entre 0 e 9) e retorna falso caso não seja
    if (d < 0 || d > 9) {return false;}

	// Se d for 0
	if (d == 0) {
		
		// Define o tamanho do array como 1
		bres[0] = 1;
        
		// Define o valor como 0
		bres[1] = 0;
        
	} 
	else{
		
		//Somar d vezes 
		while( d > 1){
			
			if(big_add(bres, b, bres) == false){return false;}
			
			
			d--;
			
		}
		
	}
	
	return true;
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
	
	if(big_size(b) + 1 > MAX_DIGITS){return false;}
    
    //Percorrer a array b, colocando todos os elementos uma posição para a frente
		for(int i = big_size(b); i != 0; i--){
			
			b[i+1] = b[i];
			
		}
		
		
	//Colocar o zero na primeira posição dos dígitos de big_int
	b[1] = 0;
	
	
	//Adicionar 1 ao número de dígitos do big_int
	b[0]++;
	
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
	
	int digitos = big_size(b);
    
    if(digitos + exp > MAX_DIGITS){return false;}
    
    for(int i = 0; i < exp; i++){
		
		big_mul_10(b);
		
	}
	
	return true;
    
    
    
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
    
    //MULTIPLICAÇÃO DE MATRIZES!!!
    
	return false;
}
 
 
