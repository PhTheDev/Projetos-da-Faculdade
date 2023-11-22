#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *vetor,int tam);
int somaVetor(int *vetor,int tam);

int main()
{
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&n);
    
    int *vet;
    vet=malloc(n*sizeof(int));
    lerVetor(vet,n);

    printf("SOMA: %d",somaVetor(vet,n));

    free(vet);

    return 0;
}

void lerVetor(int *vetor,int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("Digite valor para colocar no vetor[%d]: ",i);
        scanf("%d",(vetor+i));
    }
}

int somaVetor(int *vetor,int tam){
    int i,soma=0;
    for(i=0;i<tam;i++){
        soma+=*(vetor+i);
    }
    return soma;
}


