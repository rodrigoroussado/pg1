bool binarySearch(int info[], int dim, int value){	//Procurar um elemento num array

	int left = 0;					//Limite esquerdo do array (parte utilizada)
	int right = dim-1;				//Limite direito do array (parte utilizada)

	while(left <= right){

		int med = (right + left)/2;		//Calculamos o ponto médio do array
		if(value == info[med]){return true;}	//Se o valor no ponto médio for o que procuramos - foi encontrado
		if(value < info[med]){right = med-1;}	//Se o valor estiver mais à esquerda que o ponto médio - reduzir a área de pesquisa (tirar os valores de certeza maiores que value)
		else{left = med + 1;}			//Se o valor estiver mais à direita que o ponto médio - reduzir a área de pesquisa (tirar os valores de certeza menores que value)
				

		}

	return false;

}
