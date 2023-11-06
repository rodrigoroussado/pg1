int str_split(char text[], word_t words[], int size) {
	
    int contador = 0;
    char* inicio = text;
    char* fim = text;

    while (*fim != '\0' && contador < size) {
		//encontra o inicio da palavra tirando tudo o que ´eespaço e mudanaças de linha ou mesmo tab
        while (*inicio != '\0' && (*inicio == ' ' || *inicio == '\t' || *inicio == '\n')) {
			
            inicio++;
            
        }

        if (*inicio == '\0') {   //caso a string esteja vazia e chegamos ao fim saimos so while
			
            break;
            
        }
		// fim = inicio para começar a ler de onde parou anteriormente para agora encontrat o fim da palavra
        fim = inicio;

        while (*fim != '\0' && (*fim != ' ' && *fim != '\t' && *fim != '\n')) {
			
            fim++;
            
        }

        int word_length = fim - inicio;


        strncpy (words[contador], inicio, word_length);    //copia "start" vezes para words 
        words[contador][word_length] = '\0';             //adiciona \0 no final da string!!

        contador++;                                     //vai sempre interando ate end = \0
        inicio = fim;
    }

    return contador;

}
}
