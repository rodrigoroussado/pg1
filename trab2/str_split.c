int str_split(char text[], word_t words[], int size) {
    int word_count = 0;
    char* start = text;
    char* end = text;

    while (*end != '\0' && word_count < size) {
		//encontra o inicio da palavra tirando tudo o que ´eespaço e mudanaças de linha ou mesmo tab
        while (*start != '\0' && (*start == ' ' || *start == '\t' || *start == '\n')) {
            start++;
        }

        if (*start == '\0') {   //caso a string esteja vazia e chegamos ao fim saimos so while
            break;
        }
		// end = start para começar a ler de onde parou anteriormente para agora encontrat o fim da palavra
        end = start;

        while (*end != '\0' && (*end != ' ' && *end != '\t' && *end != '\n')) {
            end++;
        }

        int word_length = end - start;


        strncpy (words[word_count], start, word_length);    //copia "start" vezes para words 
        words[word_count][word_length] = '\0';             //adiciona \0 no final da string!!

        word_count++;                                     //vai sempre interando ate end = \0
        start = end;
    }

    return word_count;

}
