#include <stdio.h>
#include <stdlib.h>

void lerVetor(int **vetor, int n);
int calcularSoma(int **vetor, int n);

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *vetorPonteiros[n];

    for (int i = 0; i < n; i++) {
        vetorPonteiros[i] = malloc(sizeof(int));
    }

    lerVetor(vetorPonteiros, n);
    int soma = calcularSoma(vetorPonteiros, n);

    printf("A soma dos elementos do vetor: %d\n", soma);

    for (int i = 0; i < n; i++) {
        free(vetorPonteiros[i]);
    }

    return 0;
}

void lerVetor(int **vetor, int n) {
    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        (*vetor)[i] = 0;
        scanf("%d", &((*vetor)[i]));
    }
}


int calcularSoma(int **vetor, int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += (*vetor)[i];
    }
    return soma;
}