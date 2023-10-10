int is_oblong(int n){

	int aux = 0;

	if(n < 0){return aux;}
	else{
		
		if(n%2 != 0){return aux;}
		else{
			
			for(int i = 0; i <= n; i++){
		
				if(n == i*(i+1)){aux = 1; break;}
				
		
				}	
			
			return aux;
			
			}
		
		}



}
