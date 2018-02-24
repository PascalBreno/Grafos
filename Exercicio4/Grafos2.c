/*
* Grupo: Breno Felix e Victor Felix
*
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdbool.h>
//Cria as matrizes na memória
bool **alocarMatrizQuadrada(int tamanho){
    bool **fim = (bool**)malloc(tamanho* sizeof(bool*));

    for (int i = 0; i < tamanho ; ++i) {
        fim[i] = (bool*)calloc(tamanho, sizeof(bool));
    }

    return fim;
}

//Multiplica as matrizes com as funções propriamente ditas
bool **multiplicarMatriz(bool **matriz1, bool **matriz2, int tamanho){
    bool **fim, aux;
    fim = alocarMatrizQuadrada(tamanho);


    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            aux = false;
            for (int k = 0; k < tamanho; ++k) {
                aux = aux or (matriz1[i][k] and matriz2[k][j]);
            }

            fim[i][j] = aux;
        }
    }


    return fim;
}
//Função para imprimir a Matriz
void imprimirMatriz(bool **matriz, int tamanho){
    for (int i = 0; i < tamanho; ++i) {
        printf("| ");
        for (int j = 0; j < tamanho; ++j) {
            if(j+1<tamanho){
                printf("%d -", matriz[i][j]);
            }else{
                printf(" %d |", matriz[i][j]);
            }
        }
        printf("\n");
    }
}
//Algoritmo de Warshall aplicando ponteiro com endereço já alocado
bool **warshall(bool **matriz, int tamanho){
    bool **fim;
    fim = alocarMatrizQuadrada(tamanho);
    for(int k = 0; k<tamanho; k++){
        for(int i=0; i<tamanho; i++){
            for(int j=0; j<tamanho; j++){
                fim[i][j] = matriz[i][j] or (matriz[i][k] and matriz[k][j]);
            }
        }

    }

    return fim;
}

int main() {
    bool **inicio, **fim,**aux;
    int tamanho, vertice1, vertice2;
    vertice1 = 0;
    vertice2 = 0;
    //Essa parte é responsável por ler o número de arestas para saber o tamanho da matriz
    printf("Insira o número de arestas total: \n");
    scanf("%d", &tamanho);
    //Função para a criação da matriz solicitada
    inicio= alocarMatrizQuadrada(tamanho);
    printf("Digite as arestas até um número menor que 0\n");
    while(true){
        scanf("%d%d", &vertice1, &vertice2);
        if(vertice1 <0 or vertice2 < 0){
            break;
        }
        inicio[vertice1-1][vertice2-1] = true;
    }

    //Processo de verificar os caminhos...
    aux = inicio;
    for (int i = 0; i < tamanho-1; ++i) {
        aux = multiplicarMatriz(inicio, aux, tamanho);
        printf("============= %d Etapa/Matriz =============\n", i+1);
        imprimirMatriz(aux, tamanho);
    }
    //Aplicando o Warshall
    aux = warshall(inicio, tamanho);
    printf("============= Warshall ============= \n");
    imprimirMatriz(aux, tamanho);
    return 0;
}
