#include <stdio.h>
#include <stdlib.h>
#include "arc.h"

int main(){

    //criar ou abrir o arquivo!
    FILE *arquivo;
    arquivo = fopen("arqPessoa.txt","a+");
    if(arquivo == NULL){
        puts("Erro de abertura de arquivo!\n");
        exit(1);
    }
    int opcao;
    do{
        puts("==========================================================");
        puts("Digite a opcao desejada a seguir:");
        puts("1 - Incluir Pessoa");
        puts("2 - Excluir Pessoa");
        puts("3 - Consultar Pessoa");
        puts("4 - Listar Pessoas");
        puts("0 - Sair");
        puts("Opcao desejada:");
        scanf("%d",&opcao);
        puts("==========================================================");
            
        switch (opcao){
        case 1:
            incluirPessoa(arquivo);
            break;
        case 2:
            excluirPessoa(arquivo, fopen("arqPessoa.txt","w"));
            remove("arqPessoa.txt");
            rename("temp.txt","arqPessoa.txt"); 
            break;   
        case 3:
            consultarPessoa(arquivo);
            break;
        case 4:
            rewind(arquivo);
            listarPessoas(arquivo);  
            break;
        case 0:
            printf("Saindo!\n");
            break;
        default:
            printf("Opcao invalida, tente novamente!");
            break;
        }
    }while(opcao != 0);

    fflush(arquivo);
    fclose(arquivo);

    return EXIT_SUCCESS;
}