#include <stdio.h>

int somatorio(int n);

int main() {
    int n;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, insira um número inteiro positivo.\n");
        return 1; // Encerra o programa com código de erro.
    }

    int resultadoSomatorio = somatorio(n);

    printf("O somatorio de 1 até %d é igual a %d.\n", n, resultadoSomatorio);

    return 0;
}

int somatorio(int n) {
    int resultado = 0;

    for (int i = 1; i <= n; i++) {
        resultado += i;
    }

    return resultado;
}
