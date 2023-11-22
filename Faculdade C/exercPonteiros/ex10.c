#include <stdio.h>

int main() {
    int a, *b, **c, ***d;

    // Inicialize os ponteiros
    b = &a;
    c = &b;
    d = &c;

    // Leia o valor de a
    printf("Digite um valor para a: ");
    scanf("%d", &a);

    // Calcule e exiba o dobro, triplo e quádruplo usando os ponteiros
    printf("Dobro: %d\n", *b * 2);
    printf("Triplo: %d\n", **c * 3);
    printf("Quadruplo: %d\n", ***d * 4);

    return 0;
}
