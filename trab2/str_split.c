bool name_middle_compressed(char orig[], char result[]) {
    
    return false;
}

/**
 * Descrição:
 *    Esta função coloca no array "words" as palavras (word_t) existentes no array "text" 
 * 	  até ao máximo de size palavras
 * Retorno:
 *    A função retorna o total de palavras colocadas no array "words"
 */
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

        int largura_word = fim - inicio;


        strncpy (words[contador], inicio, largura_word);    //copia "start" vezes para words 
        words[contador][largura_word] = '\0';             //adiciona \0 no final da string!!

        contador++;                                     //vai sempre interando ate end = \0
        inicio = fim;
    }

    return contador;

}
