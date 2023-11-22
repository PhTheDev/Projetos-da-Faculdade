#include <stdio.h>

int menu() {
    int op;
    printf("Escolha uma operacao:\n");
    printf("1 - Soma de matrizes\n");
    printf("2 - Multiplicacao de matrizes\n");
    printf("3 - Transposta de matriz\n");
    printf("0 - Sair\n");
    printf("Digite a opcao: ");
    scanf("%d", &op);
    return op;
}

void lerMatriz(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o valor para a matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void somarMatrizes(int resultado[][100], int matrizA[][100], int matrizB[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

void multiplicarMatrizes(int resultado[][100], int matrizA[][100], int matrizB[][100], int linhasA, int colunasA, int colunasB) {
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunasA; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void calcularTransposta(int transposta[][100], int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
}

int main() {
    //Pega as informaçoes das duas Matrizes A e B
    int linhasA, colunasA;
    printf("Digite o numero de linhas e colunas da matriz A: ");
    scanf("%d %d", &linhasA, &colunasA);

    int A[100][100];
    printf("Digite os elementos da matriz A:\n");
    lerMatriz(A, linhasA, colunasA);

    int linhasB, colunasB;
    printf("Digite o numero de linhas e colunas da matriz B: ");
    scanf("%d %d", &linhasB, &colunasB);

    int B[100][100];
    printf("Digite os elementos da matriz B:\n");
    lerMatriz(B, linhasB, colunasB);

    //Chama o menu() e entra em um switch case para saber qual vai ser a escolha do usuario
    int opcao;
    do {
        switch (opcao) {
            opcao = menu();
            case 1: //SOMA
                if (linhasA == linhasB && colunasA == colunasB) {
                    int resultadoSoma[100][100];
                    somarMatrizes(resultadoSoma, A, B, linhasA, colunasA);
                    printf("Resultado da soma:\n");
                    imprimirMatriz(resultadoSoma, linhasA, colunasA);
                } else {
                    printf("As matrizes nao podem ser somadas devido a dimensoes diferentes.\n");
                }
                break;
            case 2: //MULTIPLICAÇÃO
                if (colunasA == linhasB) {
                    int resultadoMultiplicacao[100][100];
                    multiplicarMatrizes(resultadoMultiplicacao, A, B, linhasA, colunasA, colunasB);
                    printf("Resultado da multiplicacao:\n");
                    imprimirMatriz(resultadoMultiplicacao, linhasA, colunasB);
                } else {
                    printf("As matrizes nao podem ser multiplicadas devido as dimensoes inadequadas.\n");
                }
                break;
            case 3: //TRANSPOSTA
                printf("Transposta da matriz A:\n");
                int transpostaA[100][100];
                calcularTransposta(transpostaA, A, linhasA, colunasA);
                imprimirMatriz(transpostaA, colunasA, linhasA);

                printf("Transposta da matriz B:\n");
                int transpostaB[100][100];
                calcularTransposta(transpostaB, B, linhasB, colunasB);
                imprimirMatriz(transpostaB, colunasB, linhasB);
                break;
            case 0: //FINALIZA O SWITCH CASE (FLAG)
                break;
            default: //CASO TENHA ESCREVIDO ALGO ERRADO DE ENTRADA E DEIXADO DE PADRAO A MENSAGEM OPÇÃO INVALIDA
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
