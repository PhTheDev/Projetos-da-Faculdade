#ifndef PESSOA_H
#define PESSOA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    //struct de uma pessoa contendo todos os indicadores dela
    typedef struct pessoa{
        int id;
        char nome[50];
        float peso;
        float altura;
        float imc;

    } Pessoa;
    
    //funcao que inclui uma pessoa no arquivo
    void incluirPessoa(FILE *arquivo){
        Pessoa pessoa;
        printf("Digite o ID da pessoa: ");
        scanf("%d", &pessoa.id);
        getchar();
        printf("Digite o nome da pessoa: ");
        fgets(pessoa.nome,50,stdin);
        printf("Digite o peso da pessoa: ");
        scanf("%f", &pessoa.peso);
        printf("Digite a altura da pessoa: ");
        scanf("%f", &pessoa.altura);
        pessoa.imc = pessoa.peso / (pessoa.altura * pessoa.altura);
            
        fprintf(arquivo, "%d;%s;%.2f;%.2f;%.2f\n", pessoa.id, pessoa.nome, pessoa.peso, pessoa.altura, pessoa.imc);
        printf("Pessoa incluida\n");    
    }

    //funcao que exclui uma pessoa no arquivo
    void excluirPessoa(FILE *entrada,FILE *saida){
        int idpessoa;
        printf("Digite o ID da pessoa a ser excluida: ");
        scanf("%d", &idpessoa);

        Pessoa pessoa;
        int encontrou = 0;

        while (fscanf(entrada, "%d;%s;%f;%f;%f\n",&pessoa.id,pessoa.nome,&pessoa.peso,&pessoa.altura,&pessoa.imc)){
            if(pessoa.id == idpessoa){
                encontrou = 1;
            } else {
                fprintf(saida, "%d;%s;%.2f;%.2f;%.2f\n", pessoa.id, pessoa.nome, pessoa.peso, pessoa.altura, pessoa.imc);
            }
        }

        if(encontrou){
            printf("Pessoa %d foi excluida!\n",idpessoa);
        }else{
            printf("Pessoa %d nao foi encontrada!\n",idpessoa);
        }
    }

    //funcao que consulta uma pessoa no arquivo
    void consultarPessoa(FILE *arquivo){
        int idpessoa;
        printf("Informe o ID da pessoa a ser consultada: ");
        scanf("%d", &idpessoa);

        Pessoa pessoa;
        int encontrou = 0;

        while (fscanf(arquivo, "%d;%s;%f;%f;%f\n", &pessoa.id, pessoa.nome, &pessoa.peso, &pessoa.altura, &pessoa.imc) != EOF) {
            if (pessoa.id == idpessoa) {
                encontrou = 1;
                printf("ID: %d, Nome: %s, Peso: %.2f, Altura: %.2f, IMC: %.2f\n", pessoa.id, pessoa.nome, pessoa.peso, pessoa.altura, pessoa.imc);
                break;
            }
        }

        if (!encontrou) {
            printf("Pessoa %d nao encontrada.\n", idpessoa);
        }
    }

    //funcao que lista uma pessoa no arquivo
    void listarPessoas(FILE *arquivo) {
    Pessoa pessoa;
    printf("Lista de Pessoas:\n");
    while (fscanf(arquivo, "%d;%s;%f;%f;%f\n", &pessoa.id, pessoa.nome, &pessoa.peso, &pessoa.altura, &pessoa.imc) != EOF) {
        printf("ID: %d, Nome: %s, Peso: %.2f, Altura: %.2f, IMC: %.2f\n", pessoa.id, pessoa.nome, pessoa.peso, pessoa.altura, pessoa.imc);
    }
}

#endif //PESSOA_H