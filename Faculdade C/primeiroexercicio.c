#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reorganizarArray(int arr[], int n, int localizacaopivot) {
    int pivot = arr[localizacaopivot];

    // Mover o pivot para o final
    troca(&arr[localizacaopivot], &arr[n - 1]);

    int i = 0;

    for (int j = 0; j < n - 1; j++) {
        if (arr[j] <= pivot) {
            troca(&arr[i], &arr[j]);
            i++;
        }
    }

    // Colocar o pivot na lugar certo
    troca(&arr[i], &arr[n - 1]);
}

int main() {
    int n;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int A[n];

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int i;
    printf("Digite o índice i: ");
    scanf("%d", &i);

    // Para parar de dar o erro chato de lixo
    if (i < 0 || i >= n) {
        printf("O índice i indisponivel\n");
        return 1;
    }

    // Reorganizar os elementos
    reorganizarArray(A, n, i);

    // Imprimir o array reorganizado

    printf("Array reorganizado:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", A[j]);
    }
    printf("\n");

    return 0;
}
