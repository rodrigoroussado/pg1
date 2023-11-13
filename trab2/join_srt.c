/*Programa que junta dois ficheiros .srt (Subtitle Ripple) em apenas um*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FILENAME 100
#define MAX_TIME 12
#define MAX_LINE 1000

//Definir tipos que suportam o nome do ficheiro e o tempo da legenda
typedef char FileName[MAX_FILENAME + 1];
typedef char TimeValue[MAX_TIME];


bool addTime(h1,m1,s1,ms1,h2,m2,s2,ms2,*hr,*mr,*sr,*msr){
	
	*hr = h1 + h2;
	if(*hr > 24){return false;}
	
	*mr = m1 + m2;
	if(*mr >= 60){*hr++; *mr-= 60;}
	
	*sr = s1 + s2;
	if(*sr >= 60){*mr++; *sr-=60}
	
	*msr = ms1 + ms2;
	if(*msr > 999){*sr++; *,sr-=999;}
	
	return true;
	
}

//Função que recebe o nome do ficheiro e o abre
FILE * readFileName(char msg[],FileName filename, char modo[]){
	
	int tamanhoFile = strlen(filename);
	FILE *f = NULL;
	
	while(true){
		
		printf("%s",msg);
		
		fgets(filename,tamanhoFile,stdin);
		int len = strlen(filename);
		
		if(filename[len-1] == '\n'){filename[len-1] = '\0';} //Se existir, retira o return no fim do ficheiro
		
		f = fopen(filename,modo);
		
		if(f != NULL){break;}
		
	}
	
	return f;
	
}

//Função que mostra erro quando não é possível ler o ficheiro
void erroConversao(){
	
	printf("Erro ao juntar os ficheiros!");
	
}


//Função que processa as legendas
bool processarLegendas(FILE *fin, FILE *fout ,int *nlegenda, TimeValue timeStart){

	int hrs, min, seg, mseg;
	int hrsS, minS, segS, msegS;
	int hrsE, minE, segE, msegE;
	
	char middle[MAX_LINE];
	char line[MAX_LINE];
	
	TimeValue timeS, timeE;

	
	while(fgets(line,MAX_LINE,fin) != NULL){
		
		fprintf(fout,"%d\n", ++(*nlegenda));
		
		if(fgets(line, MAX_LINE, fin) == NULL){erroConversao();}
			
		scanf(line,"%s:%s:%s", timeS,middle,timeE);
		
		addTime(hrs,min,seg,mseg,hrsS,minS,segS,msegS,timeS);
		addTime(hrsS,minS,segS,msegS,hrsE,minE,segE,msegE,timeE);
		
		fprintf(fout,"%s:%s:%s,%s",timeS,middle,timeE);
		
	}
	
	return true;
	
}




int main(){
	
	FileName filenamePart1, filenamePart2, filenameResult;
	TimeValue endTime = "00:00:00,000";
	
	int legendNumber;
	
	
	FILE *f1 = readFileName("Parte 1: ",filenamePart1,"r");
	if(f1 == NULL){erroConversao();}
	
	FILE *f2 = readFileName("Parte 2: ",filenamePart2,"r");
	if(f2 == NULL){erroConversao();}
	
	FILE *fout = readFileName("Resultado: ", filenameResult, "w");
	if(fout == NULL){erroConversao();}
	
	//Processar as legendas, atualizando o seu número e tempo e validar o formato de tempo
	bool res1 = processarLegendas(f1,fout,&legendNumber,endTime);
	bool res2 = processarLegendas(f2,fout,&legendNumber,endTime);

	
	//Fechar os ficheiros que foram abertos
	fclose(fout);
	fclose(f1);
	fclose(f2);
	
	return true;
	
}
