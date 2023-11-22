#include <stdio.h>
#include <math.h>

void separarPartes(double numero, int *parteInteira, double *parteFracionaria) {
    *parteInteira = (int)floor(numero);
    *parteFracionaria = numero - *parteInteira;
}

int main() {
    double numero;
    printf("Digite o numero com parte fracionaria e inteira (ex: 123.4): ");
    scanf("%lf", &numero);

    int parteInteira;
    double parteFracionaria;

    separarPartes(numero, &parteInteira, &parteFracionaria);

    printf("Numero: %lf\n", numero);
    printf("Parte Inteira: %d\n", parteInteira);
    printf("Parte Fracionaria: %lf\n", parteFracionaria);

    return 0;
}
