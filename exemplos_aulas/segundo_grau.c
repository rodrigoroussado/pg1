//Calcular zeros de uma equação de segundo grau e calcula os seus máximos ou mínimos (aula de 27-09)

#include <stdio.h>
#include <stdbool.h>


//Escreve mensagens de erro no caso de má leitura
bool lerDados(double *a, double *b, double *c){				//Como estamos a passar endereços e não valores double, temos de colocar "*" - pointer para o endereço

	printf("Introduza os coeficientes da equação de 2º grau (a, b e c)\n");
	if ( scanf("%lf%lf%lf",a,b,c) !=3 ){				//Neste scanf não temos "&" nas variáveis porque já definimos nos parâmetros da função que é para pôr no endereço!
	
		printf("Erro na leitura dos valores!\n");
		return false;
	}


	if( a==0 ){

		printf("O coeficiente de x^2 não pode ser 0!\n");
		return false;
	}

	return true;

}


//Processa os dados (calcula os zeros)
bool processar(double a, double b, double c, double *zero_1, double *zero_2, double *inflexao_x){

	double aux = (b*b)-4*a*c;
	if(aux < 0){

		return false;			

	}

	
	*zero_1 = (-b + sqrt(aux))/2*a;
	*zero_2= (-b - sqrt(aux))/2*a;					//Como estes parâmetros são pointers, para os afetar, TEMOS DE OS USAR COMO POINTERS!

	*inflexao_x = -b/(2*a);
	printf("O ponto %s é (%lf,%lf)\n", ((a<0)?"máximo":"mínimo"), inflexao_x, f(a,b,c,inflexao_x));

	return true;

}


//Mostra os resultados processados ao utilizador
void escreveResultado(double a, double b, double c, bool ok, double zero_1, double zero_2){

	if(!ok){

		printf("Não existem zeros\n");
		return;							//Return sem nada porque é uma função void!

	}

	printf("Os zeros da função: %lfx^2 + %lfx + %lf são %lf e %lf\n",a,b,c,zero_1,zero_2);
	printf("\n");

}


//Função matemática
double f(double a, double b, double c, double x){

	return a*x*x + b*x + c;						//f(x) = ax^2 + bx + c

}

int main(){
	
	//Declarar variáveis
	double a,b,c;
	double zero_1, zero_2, inflexao_x;

	//Apresentar o programa
	printf("Resolução de equação do segundo grau.\n");
	
	//Ler valores de a, b e c
	if( !lerDados(&a,&b,&c) ){	//temos de passar o endereço das variáveis porque, se passarmos a variável, a função trabalha só com o valor e estamos a ler dados para o endereço!
		return 1;
	}					


	//Processar dados
	bool ok = processar(a,b,c,&zero_1,&zero_2,&inflexao_x);
	

	//Apresentar o resultado
	escreveResultado(a,b,c,ok,zero_1,zero_2,inflexao_x);


}
