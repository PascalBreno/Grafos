#include <stdio.h>
#include <stdlib.h>
bool **warshall(bool **matriz, int tamanho){
    bool **retorno;
    retorno = alocarMatrizQuadrada(tamanho);
    for(int k = 0; k<tamanho; k++){
        for(int i=0; i<tamanho; i++){
            for(int j=0; j<tamanho; j++){
                retorno[i][j] = matriz[i][j] or (matriz[i][k] and matriz[k][j]);
            }
        }

    }

    return retorno;
}

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
    for (int i = 0; i < arestas-1; ++i) {
        retorno = multiplicarMatriz(matriz, tamanho);
        printf("Verificação de caminhos de tamanho %d \n", i+2);
        imprimirMatriz(retorno, tamanho);
    }

    return 0;
}
