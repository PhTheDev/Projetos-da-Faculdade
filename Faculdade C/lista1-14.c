#include <stdio.h>

long long calcularFatorial(int n);

int main() {
    int n;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Por favor, insira um número inteiro positivo.\n");
        return 1; // Encerra o programa com código de erro.
    }

    long long resultadoFatorial = calcularFatorial(n);

    if (resultadoFatorial == -1) {
        printf("Fatorial nao definido para numeros negativos.\n");
    } else {
        printf("%d! = %lld\n", n, resultadoFatorial);
    }

    return 0;
}

long long calcularFatorial(int n) {
    long long resultado = 1;

    if (n < 0) {
        return -1; // Valor inválido para números negativos.
    }

    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}