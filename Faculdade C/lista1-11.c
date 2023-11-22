#include <stdio.h>

int calcularPotencia(int x, int y);

int main() {
    int x, y, resultado;

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    printf("Digite o valor de y: ");
    scanf("%d", &y);

    resultado = calcularPotencia(x, y);

    printf("%d elevado a %d é igual a %d\n", x, y, resultado);

    return 0;
}

int calcularPotencia(int x, int y) {
    int resultado = 1;

    for (int i = 0; i < y; i++) {
        resultado *= x;
    }

    return resultado;
}

