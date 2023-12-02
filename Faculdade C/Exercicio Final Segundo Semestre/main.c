#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cliente.h"

int main(){

    FILE* arqcliente = fopen("cliente.csv","a+");
    if(arqcliente == NULL){
        printf("Falha na abertura de arquivo!");
        exit(1);
    }
    menuCliente();

    return 0;
}    
