#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 52

void shuffle(int array[], int size) {
	
    for (int i = size - 1; i > 0; i--) {
		
        int j = rand() % (i + 1);
        
        //Usa uma variavel auxiliar para fazermos a troca dos array
        int aux = array[i];
        array[i] = array[j];
        array[j] = aux;
    }
}

int main() {
    //Usar a funçaõ srand para dar random nos números
    srand(time(NULL));

    //Criar e percorrer o array
    int numbers[SIZE];
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = i;
    }

    //usar a função shuffle para baralhar os números
    shuffle(numbers, SIZE);

    //Percorrer o array baralhado e dar print
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
