#include <stdio.h>

void gerarTrianguloAsteriscos(int n) {
    for (int linha = 1; linha <= n; linha++) {
        // Imprime asteriscos da esquerda para a direita.
        for (int i = 1; i <= linha; i++) {
            printf("*");
        }
        printf("\n");
    }

    for (int linha = n - 1; linha >= 1; linha--) {
        // Imprime asteriscos da esquerda para a direita.
        for (int i = 1; i <= linha; i++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Digite um valor inteiro n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, insira um valor inteiro positivo.\n");
        return 1; // Encerra o programa com código de erro.
    }

    gerarTrianguloAsteriscos(n);

    return 0;
}
