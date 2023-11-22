#include <stdio.h>

int main(){

    int variavelA, variavelB;

    printf("Endereco de memoria da variavel A:%x\n",&variavelA);
    printf("Endereco de memoria da variavel B:%x\n",&variavelB);

    if(&variavelA>variavelB)
        printf("Encereco de memoria da variavel A e maior que o do B");
    else 
        printf("Encereco de memoria da variavel B e maior que o do A");

    return 0;
}