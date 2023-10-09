#include <stdio.h>
#include <stdbool.h>

bool validarValor(double valor){
	
	if(valor < 0){return false;}
	else{return true;}
	
	}


bool validarUnidade(int unidade){
	
	if(unidade < 1 || unidade > 7){return false;}
	else{return true;}
	
	}
	

bool verificarInteiro(double resultado){
	
	int resultadoInt = resultado;
	
	if((resultado = resultadoInt)){return true;}
	else{return false;}
	
	}

int main(){
	
	//Declarar variáveis
	double valor;
	int uni_inicial, uni_final;
	int fator_mult;
	
	//Apresentar o programa
	printf("Lê um valor e converte-o para qualquer unidade de comprimento (mm,cm,dm,m,dam,hm,km)\n");
	printf("Escreva um número de 1-7 para definir a unidade inicial e a unidade para a qual pretende converter!\n");
	printf("1 = mm, 2 = cm, 3 = dm, 4 = m, 5 = dam, 6 = hm, 7 = km \n");
	
	//Receber valor
	printf("Insira o valor a converter: ");
	if( scanf("%lf",&valor)!= 1 ){printf("Valor inválido!\n");}
	else{
		
		if(validarValor(valor) == false){printf("Valor inválido!\n");}
		else{
			
			//Receber unidade inicial e validar
			printf("Insira a unidade inicial: ");
			
			if( scanf("%d",&uni_inicial)!= 1 ){printf("Unidade inicial inválida!\n");}
			else{
				
				if(validarUnidade(uni_inicial) == false){printf("Unidade inicial inválida!\n");}
				else{
					
					//Receber unidade final e validar
					printf("Insira a unidade final: ");
					
					if( scanf("%d",&uni_final)!= 1 ){printf("Unidade final inválida!\n");}
					else{
						
						if(validarUnidade(uni_final) == false){printf("Unidade final inválida!\n");}
						else{
							
							//Calcular a diferença entre a unidade final e a inicial
							
							
							}
						
						}
					
					}
				
				}
			
			}
		
		}
	
	
	
}
