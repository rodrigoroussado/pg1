//Ordenar um array

void sort(int info[], int dim){

	for(int i = 0; i < dim-1; i++){

		int posMenor = i;
		for(int j = i+1; j < dim; j++){				//Procura a posição do menor valor

			if(info[j] < info[posMenor]){posMenor = j;}	//Encontrou um menor que o anterior menor

		}

		if(posMenor != i){	//Se o novo menor não for igual ao menor anterior, troca os de posição

			int aux = info[i];
			info[i] = info[posMenor];
			info[posMenor] = aux;


		}

	}

}

//Para passar a ordenar decrescentemente, temos de mudar a variável posMenor para posMaior e trocar "<" para ">" na linha 10
