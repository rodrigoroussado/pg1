#include <stdio.h>
#include <stdbool.h>

//Função que retorna true se um número for oblongo
bool is_oblong(int n){
	
	for(int i=0; i != n; i++){
		
				
		if( (n = i*(i+1)) ){
			
			break;
			
			}

			return false;

		}

	return true;
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
