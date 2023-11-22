#include <stdio.h>
#include <stdlib.h>

int main(){

    float *arr;
    arr=(float *)malloc(5*sizeof(float));
    int i; //declarar o indice fora do loop (Otimo abito)
    for(i=0;i<5;i++){
        printf("Digite um valor para o array[%d]:\n",i);
        scanf("%f",arr+i);
    }
    
    for(i=0;i<5;i++)
        printf("Endereco de memoria na posicao[%d]:%x\n",i,&arr+i);

    for(i=0;i<5;i++)
        free(arr+i);

    return 0;
}