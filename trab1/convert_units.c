#include <stdio.h>



int main(){
	
	double n;
	int uni_inicial, uni_final;
	
	
	// Apresenta o propósito do programa
	printf("Lê um valor e converte-o para qualquer unidade de comprimento (mm,cm,dm,m,dam,hm.km)\n");
	printf("Escreva um número de 1-7 para definir a unidade inicial e a unidade para a qual pretende converter!\n");
	printf("1 = mm, 2 = cm, 3 = dm, 4 = m, 5 = dam, 6 = hm, 7 = km \n");
	
	//Pede o Valor
	printf("\nInsira o valor: ");
	scanf("%lf",&n);
	
	//Pede a unidade Inicial e Valida
	printf("\nInsira a unidade do valor inicial: ");
	if (scanf("%d",&uni_inicial)!=1 || (uni_inicial <= 0 || uni_inicial >= 8)){
		
		printf("Unidade inicial Inválida");
																				
	}
		
	else {
	//Pede a Unidade Final e Valida
	printf("\nInsira a unidade para o valor final: ");
		if (scanf("%d",&uni_final) !=1 || (uni_inicial <= 0 || uni_inicial >= 8)){
		
			printf("Unidade final Inválida");
		
		}
	}
	
	
	
	
}
