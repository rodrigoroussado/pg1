#include <stdio.h>
#include <stdbool.h>
//---------------------------
#define OPCAO_ZEROS '1'
#define OPCAO_MAXMIN '2'
#define OPCAO_TERMINAR 'T'
//---------------------------

//lê os dados introduzidos pelo utilizador
bool lerDados (double *a, double *b, double *c){    //(a,b,c)são pointers para um double
	
	printf ("Introduza os coeficientes da esqueção de 2º grau (a,b,c)");
	if (scanf("%lf%lf%lf",a, b, c) != 3){

		printf("Erro na leitura dos valores\n");
		return false;

	}

	if (a==0){
		printf("O coeficiente de x^2 não pode ser zero");
		return false;

	}
	return true;
}

//-----------------------------------------------------------------
//mostrar Menu

void mostrarMenu(){

printf("_ _ Menu _ _\n");
printf("%c - calcular Zeros", OPCAO_ZEROS);
printf("%c - Apresentar Máximo / Minimo da função\n", OPCAO_MAXMIN);
printf("%c - Terminar Programa \n", OPCAO_TERMINAR);
}

//Ler Opçao

char lerOpcao(){

char op;
printf("Escolha a opção");
scanf("%c",&op);

if(op!='\n'){
	char c;                                  //Limpar o resto da linha
	while(scanf("%c",&c) && c!='\n');
}

return op;

}


//executar opção

void executarOpcao(char opcao, double a, double b, double c,){

switch(opcao){

	case OPCAO_ZERO:
		//CALCULAR ZEROS
		break;
	case OPCAO_MAXMIN:
		//CALCULAR MAXIMO E MINIMO
		break;
//continuar para o resto...
	default:
		printf("Opção %c inválida\n", opcao);
		break;

}

}
//-----------------------------------------------------------------

//processa os dados (calcula os zeros)
bool processar (double a, double b, double c, double *zero_1, double *zero_2, double *inflexao_x){
	
	double aux = b*b - 4*a*c;
	if (aux < 0 ){
		
		return false;
	
	}
	*zero_1 = (-b + sqr(aux))/2*a;
	*zero_2 = (-b - sqr(aux))/2*a;
	*inflexao_x = -b /(2*a);
	return true;
}

//Mostra os resultados processados ao utilizador
void escreverResultado (double a, double b, double c, bool ok, double zero_1, double zero_2){
	
	if(!ok){
	
		printf("Não existe zeros!");
		return;

	}

	printf("Os zeros da função %lf x^2 + %lf x + %lf = (%lf,%lf)\n", a, b, c, zero_1, zero_2);
	
	printf("O ponto %s é (%lf,%lf)\n",(a<0?) "Máximo" : "Mínimo", inflexao:_x, f(a,b,c,inflexao_x);     //usamos %s -> string  // se o a>0 diz Máximo , se o a<0 diz Mínimo

} 

//função mat. para calcular o y
double f(double a, double b, double c, doubel x){

	return a*x*x+b*x+c;               // f(x) = ax^2+bx+c

}																																																	              

int main(){
	double a,b,c;
	double zero_1, zero_2, inflexao_x;

//ler os dados 
	printf("Operações sobre polinómios de 2º Grau \n");
	// printf("Resolução de equações de 2º grau.");
	if (!lerDados(&a,&b,&c)){     //passar os endereços das variaveis
		
		printf("Valores incorretos!\n");

		return 1;                  // acaba o programa

	}

// ----------------------------------------------------------    
	do {
		
		mostraMenu();
		char opcao = lerOpcao;
		if(opcao == TERMINAR){break;}
		executarOpcao(opcao, a, b, c);
	} while (true);
}  // acaba aqui o main!!!

// -----------------------------------------------------------

// continuação para o código inicial que apenas calcula os zeros e os max. min
//processar os dados
	bool ok = processar (a, b, c, &zero_1, &zero_2, &inflexao_x);



//escrever o resultado
	escreverResultado (a, b, c, ok, zero_1, zero_2, inflexao_x);



return 0;
}
