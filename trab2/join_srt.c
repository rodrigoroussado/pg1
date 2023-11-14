#include <stdio.h>
#include <stdlib.h>

int main() {
	
    FILE *file1, *file2, *output;
    char line1[1000];
    char line2[1000];

    //Abrir os dois ficheiros 
    file1 = fopen( "padrinho2_1.srt", "r" );
    file2 = fopen( "padrinho2_2.srt", "r" );

	//Se não houver nada nos ficheiros da erro
    if ( file1 == NULL || file2 == NULL ){
		
        perror( "Erro ao abrir os ficheiros" );
        
        exit( EXIT_FAILURE );
        
    }

    //Abrir o ficheiro de escrita
    output = fopen( "legendasJuntas.srt", "w" );
    
    //Se não criar o ficheiro de output da erro
    if ( output == NULL ){
		
        perror( "Erro ao abrir o ficheiro final" );
        
        exit( EXIT_FAILURE );
        
    }
	
	int number1;
	int number2;
	
    //Processar o primeiro ficheiro
    while ( fgets( line1, sizeof(line1), file1 ) != NULL ){
        fprintf( output, "%s", line1 );

        //Ver se a linha tem todos o tempo e a legenda
        if ( sscanf( line1, "%*d:%*d:%*d,%*d --> %*d:%*d:%*d,%*d" ) == 0 ){
			
            //Incrementar o numero da legenda
            sscanf( line1, "%d", &number1 );
            
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
            sscanf( line2, "%d", &number2 );
            
        }
    }

    //Fechar todos os ficheiros
    fclose( file1 );
    fclose( file2 );
    fclose( output );

    printf( "Ficheiros combinados com sucesso\n" );

    return 0;
}
