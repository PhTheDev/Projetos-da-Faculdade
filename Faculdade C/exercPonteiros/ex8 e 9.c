#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int *vetor,int tam,int valor);
void imprimirVet(int *vetor, int tam);

int main(){

    int tamanho=5;
    int *vet;

    vet=malloc(tamanho*sizeof(int));

    int valorVet=10;

    preencherVetor(vet,tamanho,valorVet);

    imprimirVet(vet,tamanho);

    free(vet);

    return 0;
}

void preencherVetor(int *vetor,int tam,int valor){
    int *ponteiro = vetor;

    while(ponteiro < vetor + tam){
        *ponteiro = valor;
        ponteiro++;
    }
}

void imprimirVet(int *vetor, int tam){
    int *pont = vetor;

    while(pont < vetor+tam){
        printf("%d\n",*pont);
        pont++;
    }
}