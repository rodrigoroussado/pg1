//Grupo 02
//Alunos João Santos (nº51009) e Rodrigo Viegas (nº50977)
//LT13D

//Exercício 3

#include <stdio.h>
#include <stdbool.h>


//Função que retorna true se um número for oblongo
int is_oblong(int n){

	int aux = 0; //Variável que, caso seja = 1, o número é oblongo, caso seja = 0, o número não é oblongo

	if(n < 0){return aux;}
	else{
		
		if(n%2 != 0){return aux;}
		else{
			
			for(int i = 0; i <= n; i++){
		
				if(n == i*(i+1)){aux = 1; break;}
				
		
				}	
			
			return aux;
			
			}
		
		}



}


int main(){
	
//Declarar variáveis
	int n;


//Apresentar o programa
	printf("Programa que indica se um número é oblongo.\n");
	printf("Digite número e termine com um caractere não dígito:\n");

//While loop (pede um número ao utilizador até este terminar com um caractere não dígito
	while(scanf("%d",&n) == 1){
		
		if(is_oblong(n) == true){
			
			printf("É oblongo\n");
			
			}
		
		}

}
