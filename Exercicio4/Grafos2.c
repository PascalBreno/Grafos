#include <stdio.h>
#include <stdlib.h>

int main(){
    int arestas;
    do{
        printf("Digite o número de vértices da matriz \n");
        scanf("%d", &arestas);
        if(arestas<2){
            printf("Número digitado inválido, tente novamente! \n");
        }
    }while(arestas<2);
    int matriz[arestas][arestas];
    for(int j=0; j<arestas;j++){
        printf("Linha nº %d \n", j+1);
        for (int i=0; i<arestas; i++){
            scanf("%d", &matriz[j][i]);    
        }
    }
    for(int j=0; j<arestas;j++){
        printf("Linha nº %d : |", j+1);
        for (int i=0; i<arestas; i++){
            if(i+1<arestas){
                printf("%d -", matriz[j][i]);
            }else{
                printf("%d", matriz[j][i]);
            }    
        }
        printf("|\n");
    }
    return 0;
}
