#include <stdio.h>
#define MAX_LETRAS ('Z'-'A'+1)
#define MAX_LINHA 200
#define LARGURA_MAXIMA 78 // mudar o número dependendo do largura da caixa do texto


//         DEFINIÇÕES DAS FUNÇÕES        //
void clearContadores (int info[],int dim){

	for (int i = 0; i<dim;++i)info[i]=0;

}

int maiorContador(int info[], int dim){

	int maior =0;
	for(int i= 0; i<dim;++i){
	
		if(info[i]>maior)maior=info[i];
	
	}
	return maior;
	
}
void contarLinha (int dados[], char linha[]){
	
	
		for(int i = 0; linha[i]!= '\0'; ++i){
			
			char c = linha[i];
			if(c >= 'a' && c <= 'z') c = c - 'a' + 'A' ;
			if ( c >= 'A' && c <= 'Z') dados [c - 'A']++;
			
		}
	
}

int main (){
	
	int larguraMax = LARGURA_MAXIMA;
	int contador [MAX_LETRAS];
	
	clearContadores(contadores,MAX_LETRAS);
	char linha [MAX_LINHA];
	
	while (fgets(linha,MAX_LINHA,stdim)!=NULL){
	
		contarlinha(contadores,linha);
	
	}
	int maior = maiorContador (contadores, MAX_LETRAS);
	
	for(int i = 0; i<MAX_LETRAS; ++i){
	
		int qt = (contador[i]*larguraMax+(maior/2))/maior;    // (maior/2) serve para "arredondar" logo na conta
		printf ("%c", 'A'+i);
		for (int a = 0;a<qt;a++)printf ("*");
		printf("\n");
		
	}

}
