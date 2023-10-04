//Um programa que recebe um caractere e determina se este é digito, letra ou outro
//Caso seja um dígito, determina o seu dobro e, caso seja uma letra mostra o seu correspondente em minúscula (se for maiúscula) ou vice-versa

int main(){

		char c;

		printf("Insira um caractere: ");
		scanf("%c",c);

		if(c >= '0' && c <= '9'){
	
				printf("%c é um dígito\n",c);
				printf("O dobro de %c é %i\n", c, 2*(c - '0') );  //Como '0' representa o valor 48 (código de 0), basta-nos subtrair ao valor de c para saber o seu valor
																													//real e depois multiplicar por 2 para obter o dobro -> char (dígito) - '0' = char (dígito) em inteiro
		}

		else{
	
				if(c >= 'a' && c <= 'z'){
			
						printf("%c é uma letra minúscula\n");
						printf("Maiúscula = %c\n",c,(c-'a'+'A'));    //Distância do char ao início das minúsculas e somamos isso ao início das maiúsculas

				}	

				else{ 
						
						if(c >= 'A' && c <= 'Z'){

								printf("%c é uma letra minúscula\n");
								printf("Minúscula= %c\n",c,(c-'A'+'a'));
						}

				}

	}

}



/*
Char -> Int: char - '0'
Int -> Char: i + '0'
Char(minúsculo) -> Char(maiúsculo): (char - 'a') + 'A'
Char(maiúsculo) -> Char(minúsculo): (char - 'A')+'a

- quando os caracteres são maiores que ' ' (espaço, valor 32), são printáveis!

'\n','\t','\r' -> não são printáveis, portanto, são colocados assim (nova linha, tab e return)
*/
