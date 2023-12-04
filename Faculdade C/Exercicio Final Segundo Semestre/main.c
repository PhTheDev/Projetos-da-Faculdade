/*
2023.2-CMP2105/A01 - TÉCNICAS DE PROGRAMAÇÃO

PROJETO FINAL

ACADÊMICOS DO GRUPO: 
MÓDULO CLIENTE  -  PEDRO HENRIQUE FARIA DOS SANTOS SOARES - 2023.1.0033.0011-2

MÓDULO PRODUTO  -  DANIEL RIOS LEMES COSTA - 2023.1.0033.0004-0

MÓDULO PEDIDO   -  THIAGO HENRIQUE SOUZA RODRIGUES - 2023.1.0033.0063-5
*/

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
    short opcaomenu;

    do {
        printf("\n\n------------------------MENU-PRINCIPAL------------------------\n");
        printf("\n1 - Menu Cliente\n");
        printf("2 - Menu Produto\n");
        printf("3 - Menu Pedido\n");
        printf("4 - Sair do programa\n\n");
        printf("-------------------------------------------------------------\n");
        printf("\n\nDigite a opcao desejada: ");
        scanf("%hd", &opcaomenu);  // Use %hd para short
        switch (opcaomenu) {
            case 1:
                opcaomenu = menuCliente(); // Chama o menu do cliente
                break;
            case 2:
                //opcaomenu = menuProduto();
                break;
            case 3:
                //opcaomenu = menuPedido();
                break;    
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida tente novamente!");
                break;
        }
    } while (opcaomenu != 4);

    return 0;
}    
