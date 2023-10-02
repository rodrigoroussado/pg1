#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//Função que encontra a solução de i²+i-n = 0
double zerosSegundoGrau(int a, int b, int c, double *z1, double *z2){
	// a = 1; b = 1; c = -n
	
	
	
	double aux = (b*b)-4*a*c;
	if(aux < 0){return false;}
		
	*z1 = (-b + sqrt(aux))/2*a;
	*z2 = (-b - sqrt(aux))/2*a;
	
}

	


//Função que retorna true se um número for oblongo
bool is_oblong(int n){
	
	int i = 0;
	double z1, z2;
	
	if(n < 0){return false;}
	else{
		
		if(n%2 != 0){return false;}
		else{
			
			if( i*i + i > n){return false;}
			else{
				
				zerosSegundoGrau(1,1,-n,&z1,&z2);

				for(int i = 0; i <= n; i++){
		
					if( z1 == 0 || z2 == 0){  //Se a função retornar 0: é oblongo!
			
						return true;
						break;
			
						}
		
					return false;
		
					}
				
				}
			
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
