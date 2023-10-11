#include <stdio.h>
#include <stdbool.h>


//Função para determinar se um ano é bissexto
bool AnoBissexto(int ano){
		
		if( (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0) ){return true;} //Se o ano for bissexto, retorna true
		else{return false;}														 //Se o ano não for bissexto, retorna false
}



// Função para determinar o número de dias em um mês
int diasDoMes(int mes, int ano) {
   
		if( mes == 2 && AnoBissexto(ano) ){return 29;}		//Fevereiro (ano bissexto)
		else{
	
			switch(mes){
	
				case 2: return 28; break;					//Fevereiro (anos não bissextos)
				case 4:
				case 6:
				case 9:
				case 11: return 30; break;					//Caso para os 4 meses que têm 30 dias
				default: return 31;							//Caso para os 7 meses que têm 31 dias
	
			}
	
		}

}


int main(){
	
	int ano,mes,diaDaSemana;
	
	//Apresentar o programa
    printf("Este programa escrve todo o calendário de um ano a partir do mês que escolher!\n ");

    // Solicita o ano, mês inicial e dia da semana
    printf("Insira o ano: ");
    scanf("%d", &ano);

    printf("Insira o mês inicial (1-12): ");
    scanf("%d", &mes);

    printf("0-Dom, 1-Seg, 2-Ter, 3-Qua, 4-Qui, 5-Sex, 6-Sáb \n Digite o dia da semana: ");
    scanf("%d", &diaDaSemana);
    
       
    
    // Validação dos valores de entrada
    if (ano < 0 || mes < 1 || mes > 12 || diaDaSemana < 0 || diaDaSemana > 6) {
        printf("Dados inválidos.\n");
        return 1;								// Significa que ocorreu um problema na execução (dados inválidos)
    }

    // Escreve o cabeçalho do calendário
    printf("\nCalendário para o ano %d:\n", ano);
		
		
		
	// Loop para escrever os meses restantes do ano
    while (mes <= 12) {
        int dias = diasDoMes(mes, ano);


			switch(mes){
		
				case 1: printf("\n\nJaneiro %d:\n",ano); break;
				case 2: printf("\n\nFevereiro %d:\n",ano); break;
				case 3: printf("\n\nMarço %d:\n",ano); break;
				case 4: printf("\n\nAbril %d:\n",ano); break;
				case 5: printf("\n\nMaio %d:\n",ano); break;
				case 6: printf("\n\nJunho %d:\n",ano); break;
				case 7: printf("\n\nJulho %d:\n",ano); break;
				case 8: printf("\n\nAgosto %d:\n",ano); break;
				case 9: printf("\n\nSetembro %d:\n",ano); break;
				case 10: printf("\n\nOutubro %d:\n",ano); break;
				case 11: printf("\n\nNovembro %d:\n",ano); break;
				case 12: printf("\n\nDezembro %d:\n",ano); break;
		
			}


        // Escreve os nomes dos dias da semana
        printf("  D   S   T   Q   Q   S   S\n");

        // Escreve espaços para alinhar com os dias da semana
        for (int i = 0; i < diaDaSemana; i++) {
            printf("    ");
        }

        // Loop para escrever os números dos dias do mês
        for (int dia = 1; dia <= dias; dia++) {
            printf("%3d ", dia);
            diaDaSemana = (diaDaSemana + 1) % 7; //para garantir que o valor esteja dentro do intervalo de 0 a 6

            // Quebra de linha no sábado
            if (diaDaSemana == 0) {
                printf("\n");
            }
            
        }

        // Passa ao próximo mês
        mes++;
    }

}
