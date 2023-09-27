//Verificar se um número double é inteiro

#include <stdio.h>
#include <stdbool.h>



int main(){
	
	double n;
	int aux;
	
	printf("Insira um número para verificar se é inteiro: ");
	scanf("%lf",&n);
	
	aux = n; 				//Passa para a variável aux apenas a parte inteira de n
	
	if(n == aux){printf("inteiro");}
	else{printf("não inteiro");}
	
}
