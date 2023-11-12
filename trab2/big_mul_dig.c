bool big_mul_dig(const BIG_INT b, int d, BIG_INT bres) {
	
	big_copy(b,bres);
	
    // Verifica se d é válido (entre 0 e 9) e retorna falso caso não seja
    if (d < 0 || d > 9) {return false;}

    // Se d for 0
    if (d == 0) {
		
        // Define o tamanho do array como 1
        bres[0] = 1;
        
        // Define o valor como 0
        bres[1] = 0;
        
    } 
    else {
		
		//Somar d vezes 
		for(int i = 0; i <= d; i++){
			
			if (big_add(bres,b,bres) == false ){return false;}
			
		}
		
	}
	
	return true;
}
