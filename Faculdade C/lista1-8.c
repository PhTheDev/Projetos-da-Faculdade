#include <stdio.h>
#include <math.h>

int QuadradoPerfeito(int numero);

int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (QuadradoPerfeito(numero)) {
        printf("%d e um quadrado perfeito.\n", numero);
    } else {
        printf("%d não e um quadrado perfeito.\n", numero);
    }

    return 0;
}

int QuadradoPerfeito(int numero) {
    if (numero < 0) {
        return 0;
    }

    int raizQuadrada = (int)sqrt(numero);

    return (raizQuadrada * raizQuadrada == numero);
}
