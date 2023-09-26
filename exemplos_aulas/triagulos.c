#include <stdio.h>

int main(){
	
	int a,b,c; 															  // Inicializar as variáveis
	
	printf("Analisa os lados de um triângulo e identifica o seu tipo\n"); // Descrever a utilidade do programa
	printf("Introduza os três lados do triângulo:"); 					  // Pedir a introdução de dados
	scanf("%d%d%d", &a,&b,&c);
	
	if(a<=0 || b<=0 || c<=0 || a>=b+c || b>=a+c || c>=a+b){				  // Condições de validação dos dados (lados > 0 e suficientes para formar triângulo)
		
		printf("Dados inválidos!\n");
		
		}
	
	else{
		
		if (a == b && b==c){											  // Todos os lados iguais
			
			printf("Triângulo equilátero\n");
			
			}
		
		else{
			
			if(a == b || a == c || b ==c){								  // Dois lados iguais
				
				printf("Triângulo escaleno\n");
				
				}
				
			else{
				
				printf("Triângulo isósceles\n");						  // Lados todos diferentes
				
				}
			
			}
		
		}
	
	}
