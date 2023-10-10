int diasDoMes(int mes, int ano){
	
	if( mes == 2 && AnoBissexto(ano) ){return 29;}
	else{
	
		switch(mes){
	
			case 2: return 28; break;
			case 4:
			case 6:
			case 9:
			case 11: return 30; break;
			default: return 31;
	
		}
	
	}
	
}
