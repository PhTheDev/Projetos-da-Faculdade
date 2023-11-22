#include <stdio.h>

void escolhademes(int op);

int main() {
    int opcao;
    printf("Digite a opcao: ");
    scanf("%d", &opcao);
    escolhademes(opcao);
    return 0;
}

void escolhademes(int op) {
    switch (op) {
        case 1:
            printf("Janeiro");
            break;
        case 2:
            printf("Fevereiro");
            break;
        case 3:
            printf("Marco");
            break;
        case 4:
            printf("Abril");
            break;
        case 5:
            printf("Maio");
            break;
        case 6:
            printf("Junho");
            break;
        case 7:
            printf("Julho");
            break;
        case 8:
            printf("Agosto");
            break;
        case 9:
            printf("Setembro");
            break;
        case 10:
            printf("Outubro");
            break;
        case 11:
            printf("Novembro");
            break;
        case 12:
            printf("Dezembro");
            break;
        default:
            printf("Opcao invalida");
            break;
    }
}
