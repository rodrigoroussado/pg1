#include<stdio.h>

void escreverTabuada(int n){

    for(int i=0; i<=10; i++){
     
        printf("%d*%d=%d\n", n , i, n*i);
    
    }
    
    printf("\n");
    
}

int main(){
    int inicial, final;
    printf(" Escreve as tabuadas desde o primeiro numero ate ao segundo!\n");
    scanf("%d%d", &inicial, &final);
    
    for(int i=inicial; i <= final; i++){
    
        escreverTabuada(i);
    
    }
    

}