#include <stdio.h>

void gerarLinhasExclamacoes(int n);

int main() {
    int n;

    printf("Digite um valor inteiro n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, insira um valor inteiro positivo.\n");
        return 1; // Encerra o programa com código de erro.
    }

    gerarLinhasExclamacoes(n);

    return 0;
}

void gerarLinhasExclamacoes(int n) {
    int numExclamacoes = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= numExclamacoes; j++) {
            printf("!");
        }
        printf("\n");

        numExclamacoes++;
    }
}