#include <stdio.h>

// Função para determinar se um ano é bissexto
int AnoBissexto (int ano) {
    //if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){ // Não sei pq é que não estva a dar assim 
		
		return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);  // retorna se o ano é bissexto ou nao 
	//}	
}

// Função para determinar o número de dias em um mês
int diasDoMes(int mes, int ano) {
   
		if( mes == 2 && AnoBissexto(ano) ){return 29;}
		else{
	
			switch(mes){
	
				case 2: return 28; break;
				case 4:
				case 6:
				case 9:
				case 11: return 30; break;
				default: return 31;
	
			}
	
		}

}

int main() {
    int ano, mes, diaDaSemana;
    
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
        return 1;		// Significa que ocorreu um problema na execução (dados inválidos)
    }

    // Escreve o cabeçalho do calendário
    printf("\nCalendário para o ano %d:\n", ano);

    // Loop para escrever os meses restantes do ano
    while (mes <= 12) {
        int dias = diasDoMes(mes, ano);

        // Escreve o nome do mês
        char *nomesMes[] = {"", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
        printf("\n%s %d:\n", nomesMes[mes], ano);    // escrve o dia do mes seguido do ano

        // Escreve os nomes dos dias da semana
        printf("Dom Seg Ter Qua Qui Sex Sáb\n");

        // EScreve espaços para alinhar com os dias da semana
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

        // Próximo mês
        mes++;
    }

    return 0;	//Sgnifica que correu sem problemas
}
