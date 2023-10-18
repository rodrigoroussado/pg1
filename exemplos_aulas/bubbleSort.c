//Ordenação de array com bubble sort - ordenar o array em pares (ordenar os valores i e i+1, depois os valores i+1 e i+2)

void bubbleSort(int info[], int dim){


	//Loop que percorre o array (não voltando a comparar com a última posição - que já sabemos ser o maior valor)
	for(int i = 0, max = dim-2; i < dim-1; i++, max--){

		bool troca = false;	//Variável que nos indica se houveram trocas - se se mantiver a false, o array está ordenado desde o início;

		//Loop que percorre cada par de valores
		for(int j = 0; j < = max; j++){

			if(info[j] > info[j+1]){	//Se o par estiver desordenado, troca os valores

				int aux = info[j];

				info[j] = info[j+1];
				info[j+1] = aux;

				troca = true;

			}

		}

		if(!troca){return;}

	}

}
