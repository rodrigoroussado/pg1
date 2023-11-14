#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1000

void erro(){
	
	printf("Erro ao converter!");
	
}

int main() {
	
    FILE *file1, *file2, *output;
    char line1[MAX_LINE];
    char line2[MAX_LINE];

    //Abrir os dois ficheiros 
    file1 = fopen( "padrinho2_1.srt", "r" );
    file2 = fopen( "padrinho2_2.srt", "r" );

	//Se não houver nada nos ficheiros da erro
    if ( file1 == NULL || file2 == NULL ){
		
        erro();
        
    }

    //Abrir o ficheiro de escrita
    output = fopen( "legendasJuntas.srt", "w" );
    
    //Se não criar o ficheiro de output da erro
    if ( output == NULL ){
		
        erro();
        
    }
	
	int legendNumber1;
	int legendNumber2;
	
    //Processar o primeiro ficheiro
    while ( fgets( line1, sizeof(line1), file1 ) != NULL ){
        fprintf( output, "%s", line1 );

        //Ver se a linha tem todos o tempo e a legenda
        if ( sscanf( line1, "%*d:%*d:%*d,%*d --> %*d:%*d:%*d,%*d" ) == 0 ){
			
            //Incrementar o numero da legenda
            sscanf( line1, "%d", &legendNumber1 );
            
        }
    }
    
    //Adicionar uma linha para separar o ficheiro 1 do ficheiro 2 
    fprintf( output, "\n" );

    //Processar o segundo ficheiro
    while ( fgets( line2, sizeof(line2), file2 ) != NULL ){
        fprintf(output, "%s", line2);

		
        //Ver se a linha tem todos o tempo e a legenda
        if ( sscanf( line2, "%*d:%*d:%*d,%*d --> %*d:%*d:%*d,%*d" ) == 0 ){
			
            //Incrementar o numero da legenda
            sscanf( line2, "%d", &legendNumber2);
            
        }
    }

    //Fechar todos os ficheiros
    fclose( file1 );
    fclose( file2 );
    fclose( output );

    printf( "Sucesso!" );

    return 0;
}
