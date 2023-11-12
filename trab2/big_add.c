bool big_add(const BIG_INT b1, const BIG_INT b2, BIG_INT bm) {
	
	int carry = 0;
	int tamanho_bm;
	
    //Descobrir qual é o maior entre b1 e b2
	if ( big_size(b1) > big_size(b2) ) {
		tamanho_bm = big_size(b1);
	}
		
	else {
		
		tamanho_bm = big_size(b2);
    
	}
	
	//Percorrer o array para ir fazendo as somas com o respetivo carry
	for (int i = 1; i <= tamanho_bm; i++) {
		
		int c = carry;
		
		if ( i <= big_size(b1) ){c += b1[i];}
        
		if ( i <= big_size(b2) ){c += b2[i];}

		carry = c / 10;
		bm[i] = c % 10;
	}
    
	//Aumentar sempre 1 no tamanho da array quando o carry for 1
	if (carry == 1) {
		
		bm[tamanho_bm + 1] = carry;
		
		tamanho_bm++;
	}
    
	//Retorna falso caso tenha havido OVERFLOW
	if( bm[tamanho_bm + 1] >= MAX_DIGITS ){return false;}
	
	bm[0] = tamanho_bm;
	return true;	
}
