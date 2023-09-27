#include <stdio.h>
#include <stdbool.h>

//Função que valida as unidades de medida selecionadas
bool validarUnidades(int unidade){
	
	if(unidade < 1 || unidade > 7){
		
		printf("Unidade inválida!\n");
		return false;
		
		}
		
return true;
	
	}


int main(){
	
	//Declarar variáveis
	double valor;
	int uni_inicial,uni_final,fator_mult;
	
	//Apresentar o programa
	printf("Programa que lê um valor numa certa unidade e o converte para outra unidade selecionada.\n");
	
	//Receber valor (e validar scanf)
	printf("Insira o valor a converter: ");
	if( scanf("%lf",&valor)!=1 ){
		
		printf("Erro de leitura do valor!\n");
		
		}
		
	else{
		
		//Receber unidade de medida inicial (e validar scanf)
		printf("Insira a unidade inicial: ");
		if( scanf("%d",&uni_inicial)!=1 ){
			
			printf("Erro de leitura da unidade inicial!\n");
			
			}
		
		else{
			
			//Receber unidade de medida final (e validar scanf)
			printf("Insira a unidade final: ");
			if( scanf("%d",&uni_final)!=1 ){
				
				printf("Erro de leitura da unidade final!\n");
				
				}
				
			
			else{
				
				//Validar as unidades (se estão dentro das opções de unidades existentes)
				validarUnidades(uni_inicial);
				validarUnidades(uni_final);
				
				//Calcular a diferença entre as unidades final e inicial (se a diferença for 0, o resultado é igual ao valor inserido inicialmente)
				fator_mult = uni_final - uni_inicial;
				if(fator_mult == 0){
					
					printf("O resultado é: %0.4lf", valor);
					
					}
				
				else{
					//Converter o valor da unidade inicial para a final
				
					//Se a unidade final for maior que a inicial - faz divisão
					if(fator_mult < 0){
					
						fator_mult = fator_mult * (-1);
						for(int i=0 ; i!= fator_mult ; i++){
						
							valor = valor*10;
						
							}
							
						printf("O valor final é: %lf",valor);
					
						}
					
					else{
					
					//Se a unidade final for menor que a inicial
					
						for(int i=0 ; i!=fator_mult ; i++){
							
							valor = valor/10;
							
							}
					
						}
						
					printf("O valor final é: %lf",valor);
				
					}
				
			}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			}
		
		}
	
	}
