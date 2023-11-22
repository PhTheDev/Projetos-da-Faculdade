#include <stdio.h>

int maiorFatorPrimo(int numero);

int main() {
    int numero;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Por favor, insira um numero inteiro positivo.\n");
        return 1; // Encerra o programa com código de erro.
    }

    int maiorFator = maiorFatorPrimo(numero);

    printf("O maior fator primo de %d é %d.\n", numero, maiorFator);

    return 0;
}

int maiorFatorPrimo(int numero) {
    int maiorDivisor = 1;
    int divisor = 2;

    while (numero > 1) {
        if (numero % divisor == 0) {
            maiorDivisor = divisor;
            numero /= divisor;
        } else {
            divisor++;
        }
    }

    return maiorDivisor;
}