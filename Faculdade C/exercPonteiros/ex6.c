#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //biblioteca para o uso do uintptr_t

int main(){

    int *arr;
    int i;
    arr=(int *)malloc(5*sizeof(int));

    for(i=0;i<5;i++){
        printf("Digite um valor para o arr[%d]:\n",i);
        scanf("%i",arr+i);
    }
    for(i=0;i<5;i++){
        //uintptr_t armazena o numero do endereço de memoria e fala que e um numero inteiro
        //assim nao da erro quando vai dividir o endereco de memoria ara pegar o resto!
        if((uintptr_t)(&arr+i) % 2==0){
            printf("arr[%d];%x e par!\n",i,&arr+i);
        }
    }

    free(arr);

    return 0;
}