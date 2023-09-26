#include <stdio.h>
#define MIN_N 1
#define MAX_N 3999

int main(){
	int n;
	printf ("Lê um número (de 1 a 3999) e escreve-o em numeração romana\n");
	printf ("Insira o número:");
	if (scanf("%d",&n)!= 1){
		
		printf("ERRO");
	
		}
	
	if (n < MIN_N || n > MAX_N){
		
		printf("Número Inválido\n");
		
		}
	
		else{
		
			int milhares,centenas,dezenas,unidades;
			milhares = n/1000;
			centenas = (n/100)%10;
			dezenas = (n/10)%10;
			unidades = n%10;
			
			switch(milhares){
				
				case 3: printf("M");
				case 2: printf("M");
				case 1: printf("M");
				break;
				
			}
				
			switch(centenas){
				
				case 4: printf("CD");break;
				case 5: printf("D");break;
				case 6: printf("DC");break;
				case 7: printf("DCC");break;
				case 8: printf("DCCC");break;
				case 9: printf("CM");break;
				
				case 3: printf("C");
				case 2: printf("C");
				case 1: printf("C");
				break;
				
			}
				
			switch(dezenas){
				
				case 4: printf("XL");break;
				case 5: printf("L");break;
				case 6: printf("LX");break;
				case 7: printf("LXX");break;
				case 8: printf("LXXX");break;
				case 9: printf("XC");break;
				
				case 3: printf("X");
				case 2: printf("X");
				case 1: printf("X");
				break;
				
			}
				
			switch(unidades){
				
				case 4: printf("IV");break;
				case 5: printf("V");break;
				case 6: printf("VI");break;
				case 7: printf("VII");break;
				case 8: printf("VIII");break;
				case 9: printf("IX");break;
				
				case 3: printf("I");
				case 2: printf("I");
				case 1: printf("I");
				break;
				
				}
					
		
			}
	
	}
