bool big_mul_10(BIG_INT b) {
	
	if(big_size(b) + 1 > MAX_DIGITS){return false;}
    
    //Percorrer a array b, colocando todos os elementos uma posição para a frente
		for(int i = big_size(b); i != 0; i--){
			
			b[i+1] = b[i];
			
		}
		
		
	//Colocar o zero na primeira posição dos dígitos de big_int
	b[1] = 0;
	
	
	//Adicionar 1 ao número de dígitos do big_int
	b[0]++;
	
	return true;
	
}
