#include <stdio.h>
#include <stdlib.h>

void lerMatriz(int **matriz, int linhas, int colunas);
void somarMatrizes(int **matriz1, int **matriz2, int **resultado, int linhas, int colunas);
void mostrarMatriz(int **matriz, int linhas, int colunas);

int main() {
    int linhas, colunas;

    printf("Informe o numero de linhas e colunas das matrizes: ");
    scanf("%d %d", &linhas, &colunas);

    if (linhas <= 0 || colunas <= 0) {
        printf("As dimensoes da matriz devem ser positivas.\n");
        return 1;
    }

    int **matriz1 = (int **)malloc(linhas * sizeof(int *));
    int **matriz2 = (int **)malloc(linhas * sizeof(int *));
    int **resultado = (int **)malloc(linhas * sizeof(int *));

    for (int i = 0; i < linhas; i++) {
        matriz1[i] = (int *)malloc(colunas * sizeof(int));
        matriz2[i] = (int *)malloc(colunas * sizeof(int));
        resultado[i] = (int *)malloc(colunas * sizeof(int));
    }

    printf("Matriz 1:\n");
    lerMatriz(matriz1, linhas, colunas);

    printf("Matriz 2:\n");
    lerMatriz(matriz2, linhas, colunas);

    somarMatrizes(matriz1, matriz2, resultado, linhas, colunas);

    mostrarMatriz(resultado, linhas, colunas);

    // Liberar memoria
    for (int i = 0; i < linhas; i++) {
        free(matriz1[i]);
        free(matriz2[i]);
        free(resultado[i]);
    }
    free(matriz1);
    free(matriz2);
    free(resultado);

    return 0;
}

void lerMatriz(int **matriz, int linhas, int colunas) {
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void somarMatrizes(int **matriz1, int **matriz2, int **resultado, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void mostrarMatriz(int **matriz, int linhas, int colunas) {
    printf("Matriz resultante:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
