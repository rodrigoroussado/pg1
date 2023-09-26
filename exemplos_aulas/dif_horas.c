#include <stdio.h>

// ler dois horarios (h:min) e calcula a diferença entre eles

int main(){
    int hora_i, hora_f, min_i, min_f;
    int hora_dif, min_dif;
    
    // Apresentar o programa
    
    printf("Le dois horarios em formato hora:min, e calcula a diferença entre eles ");
    printf("Insira a hora de entrada: \n "); 
    if(scanf("%d:%d",&hora_i, &min_i) != 2 || hora_i <0 || hora_i >23 || min_i <0 || min_i > 59 ){
    
        printf("Hora Invalida!");
    
    }
    else{
    
        printf("Insira a hora de saida: \n "); 
            if(scanf("%d:%d",&hora_f, &min_f) != 2 || hora_f <0 || hora_f >23 || min_f <0 || min_f > 59 ){
    
                printf("Hora Invalida!");
    
    }
    
    hora_dif = hora_f - hora_i;
    min_dif = min_f - min_i;
    
    // se  hora_f < hora_i  ->  hora_f +24 - hora_i
    if(hora_f < hora_i){
    
        hora_dif = (hora_f+24)-hora_i;
    
    }
    
    // se min_f < min_i   ->  min_f+60 - min_i  && hora_dif--
    if(min_f < min_i){
    
        min_dif = (min_f+60) - min_i;
        hora_dif = hora_dif - 1;    
    
    } 
    
    printf("%d:%d",hora_dif, min_dif);
    
    }
    
    // Ler os horarios (h:min)
    // Validar os horarios 
    // Calcular a diferença

}
    