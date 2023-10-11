#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//Função que valida se os lados formam um triângulo e têm um comprimento maior que zero
bool validarLados(int l1, int l2, int l3){
	
	if( (l1 > l2 + l3 || l2 > l1 + l3 || l3 > l1 + l2) || l1 <= 0 || l2 <= 0 || l3 <= 0 ){return false;}
	else{return true;}
	
	}
	

//Função que valida se os pontos são distintos
bool validarPontosDistintos(int x1, int x2, int x3, int y1, int y2, int y3){
	
	
	if( (x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3) ){return false;}
	else{return true;}
	
	}


//Função que calcula o declive de uma reta
double decliveReta(int x1, int x2, int y1, int y2){
	
	double declive = ((y2 - y1)/(x2 - x1));
	return declive;
	
	}


//Função que valida se os pontos pertencem à mesma reta (pelo seu declive)
bool validarReta(double declive1, double declive2, double declive3){
	
	
	if(declive1 == declive2 || declive1 == declive3 || declive2 == declive3){return false;}
	else{return true;}
	
	}


//Função que calcula o comprimento de um lado
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
	
	//Validar lados
	if( validarLados(l1,l2,l3) == false){printf("Lados inválidos!");}
	else{
		
		if( validarPontosDistintos(x1,x2,x3,y1,y2,y3) == false ){printf("Pontos não distintos!");}
		else{
			
			double declive1, declive2, declive3;
			
			declive1 = decliveReta(x1,x2,y1,y2);
			declive2 = decliveReta(x1,x3,y1,y3);
			declive3 = decliveReta(x2,x3,y2,y3);
			
			
			if( validarReta(declive1,declive2,declive3) == false ){printf("Existem pelo menos duas retas iguais!");}
			else{
				
				// Somar os lados (valores calculados pela função criada)
				perimetro = l1 + l2 + l3;
		
				// Mostrar valor do perímetro
				printf("Perímetro = %0.2lf metros!", perimetro);
				
				}
			
			}
		
		}
	
	}
