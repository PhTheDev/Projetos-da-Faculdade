#include <stdio.h>

float calcularOperacao(float valor1, float valor2, char operador);

int main() {
    float valor1, valor2, resultado;
    char operador;

    printf("Digite dois valores numericos: ");
    scanf("%f %f", &valor1, &valor2);

    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &operador);

    resultado = calcularOperacao(valor1, valor2, operador);

    if (resultado != 0) {
        printf("Resultado da operacao: %.2f\n", resultado);
    }

    return 0;
}

float calcularOperacao(float valor1, float valor2, char operador) {
    float resultado;

    switch (operador) {
        case '+':
            resultado = valor1 + valor2;
            break;
        case '-':
            resultado = valor1 - valor2;
            break;
        case '*':
            resultado = valor1 * valor2;
            break;
        case '/':
            if (valor2 != 0) {
                resultado = valor1 / valor2;
            } else {
                printf("Erro: Divisao por zero não e permitida.\n");
                resultado = 0; // Valor inválido para indicar um erro.
            }
            break;
        default:
            printf("Operador desconhecido. Use '+', '-', '*', ou '/'.\n");
            resultado = 0; // Valor inválido para indicar um erro.
    }

    return resultado;
}