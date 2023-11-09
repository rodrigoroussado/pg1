int e_espaco(char c) {
	return c == ' ' || c == '\t' || c == '\n';
}

void maiuscula(char *str) {
	if (*str >= 'a' && *str <= 'z') {
		
	*str = *str - 'a' + 'A';
	
	}
}

bool name_middle_compressed(char orig[], char result[]) {
	
	//Remover os espaços finais e iniciais - podemos ver o str_trim
	char *inicio = orig;
	
	while (e_espaco(*inicio)) {
		
		++inicio;
	
	}

	char *fim = orig + strlen(orig) - 1;
	while (fim > inicio && e_espaco(*fim)) {
		
		--fim;
	}
	
	//poem o determinador no fim da string
	*(fim + 1) = '\0';   


	//Dibide o nome em varias partes - podemos depois ver se da para usar o str_split
	char *parts[MAX_PALAVRAS];
	int numParts = 0;
	int largura = strlen(inicio);
	int i = 0, j;

	while (i < largura) {
		
		//pula espaços iniciais
		while (i < largura && e_espaco(inicio[i])) {
			
			++i;
            
		}

		//enciontra o fim 
        
		j = i;
		while (j < largura && !e_espaco(inicio[j])) {
			
			++j;
            
		}

		//copia o array
		if (j > i) {
			
			inicio[j] = '\0';
			parts[numParts++] = &inicio[i];
			i = j + 1;
			
		}
		
		else {break;}
		
	}

	//ve se o nome é valido - mais que 2 nomes
	if (numParts < 2) {return false;}

	//Converter o nome para o formato pedido
	int resultLargura = 0;

	//poem em maiuscula a primeira letra de cada parte
	for (i = 0; i < numParts; ++i) {maiuscula(parts[i]);}

	//Escreve o primeiro nome
	resultLargura += sprintf(result + resultLargura, "%s ", parts[0]);

	//comprime os nomes do meio
	for (i = 1; i < numParts - 1; ++i) {
		if (strlen(parts[i]) > 2) {
			resultLargura += sprintf(result + resultLargura, "%c. ", parts[i][0]);
		}
	}

	//escrve o ultimo nome
	sprintf(result + resultLargura, "%s", parts[numParts - 1]);

	return true;
}
