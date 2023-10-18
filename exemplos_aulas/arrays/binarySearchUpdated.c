//binary search que indica em que posição temos de pôr um certo valor para que o array continue ordenado

bool binarySearch(int info[], int dim, int value, int *pos){	

	int left = 0;					
	int right = dim-1;				

	while(left <= right){

		int med = (right + left)/2;	
        	
		if(value == info[med]){*pos = med; return true;}	
		if(value < info[med]){right = med-1;}	
		else{left = med + 1;}			

		}

    *pos = left;
	return false;

}
