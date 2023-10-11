//Grupo 02
//Alunos João Santos (nº51009) e Rodrigo Viegas (nº50977)
//LT13D

//Exercício 1

#include <stdio.h>
#include <math.h>


// Função que calcula o comprimento de um lado
double comprimentoLado(double xa, double ya, double xb, double yb){
	double lado;
	
	lado = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
	
	return lado;
}


int main(){
	
	// Declarar variáveis
	double x1,y1,x2,y2,x3,y3;
	double perimetro;
	double l1,l2,l3;
	
	
	// Apresentar programa
	printf("Calcula o perímetro de um triângulo dadas coordenadas dos seus vértices.\n");
	
	// Pedir pontos
	printf("Insira as cordenadas do ponto 1: ");
	scanf("%lf%lf",&x1,&y1);
	
	printf("Insira as cordenadas do ponto 2: ");
	scanf("%lf%lf",&x2,&y2);
	
	printf("Insira as cordenadas do ponto 3: ");
	scanf("%lf%lf",&x3,&y3);
	
	// Calcular lados
	l1 = comprimentoLado(x1,y1,x2,y2);
	l2 = comprimentoLado(x2,y2,x3,y3);
	l3 = comprimentoLado(x1,y1,x3,y3);
	
	// Validações
		// l1 > l2 + l3 || l2 > l1 + l3 || l3 > l1 + l2 - inválido
		// l1, l2, l3 <= 0 - inválido
		
	if( (l1 > l2 + l3 || l2 > l1 + l3 || l3 > l1 + l2) || l1 <= 0 || l2 <= 0 || l3 <= 0 ){
		
		printf("Dados inválidos!");
				
		}
		
	else{

		// Somar os lados (valores calculados pela função criada)
		perimetro = l1 + l2 + l3;
		
		// Mostrar valor do perímetro
		printf("Perímetro = %0.2lf metros!", perimetro);
		
		}

	}
