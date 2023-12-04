#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    typedef struct cliente{
        char cpf[11];
        char nome[50];
        char numerocel[50];
        char numerotele[50];
        char email[50]

    }Cliente;
    

    short menuCliente() {
        short opcaomenucliente;

        do {
            printf("\n\n------------------------MENU-CLIENTE-------------------------\n");
            printf("\n1 - Incluir Cliente\n");
            printf("2 - Excluir Cliente\n");
            printf("3 - Consultar Cliente\n");
            printf("4 - Listar Clientes\n");
            printf("5 - Voltar ao Menu Principal\n\n");
            printf("-------------------------------------------------------------\n");
            printf("\n\nDigite a opcao desejada: ");
            scanf("%hd", &opcaomenucliente);  // Use %hd para short
            switch (opcaomenucliente) {
                case 1:
                    incluirCliente();
                    break;
                case 2:
                    excluirCliente();
                    break;
                case 3:
                    consultarCliente();
                    break;
                case 4:
                    listarClientes();
                    break;
                case 5:
                    return opcaomenucliente; // Retorna a opção para indicar a volta ao menu principal
                default:
                    printf("Opcao invalida tente novamente!");
                    break;
            }
        } while (opcaomenucliente != 5);

        return opcaomenucliente;
    }

    
    bool CPF(char cpf[12]) {
    int icpf[12];
    int i, soma = 0, digit1, res1, res2, digito2, valor;

    for (i = 0; i < 11; i++) {
        icpf[i] = cpf[i] - '0'; // Corrigindo para usar '0' em vez de 48
    }

    // Cálculo do primeiro dígito verificador (digit1)
    for (i = 0; i < 9; i++) {
        soma += icpf[i] * (10 - i);
    }
    res1 = soma % 11;
    digit1 = (res1 == 0 || res1 == 1) ? 0 : 11 - res1;

    // Cálculo do segundo dígito verificador (digito2)
    soma = 0;
    for (i = 0; i < 10; i++) {
        soma += icpf[i] * (11 - i);
    }
    valor = (soma / 11) * 11;
    res2 = soma - valor;
    digito2 = (res2 == 0 || res2 == 1) ? 0 : 11 - res2;

    // Validação
    return (digit1 == icpf[9] && digito2 == icpf[10]);
    }

    int verificarCliente(char cpf[12]) {
    // Abra o arquivo cliente.csv para leitura
    FILE *arqCliente = fopen("cliente.csv", "r");

    if (arqCliente == NULL) {
        printf("Erro ao abrir o arquivo cliente.csv");
        return 0; // Indica que não encontrou o CPF
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arqCliente) != NULL) {
        // Verifique se o CPF existe na linha
        if (strstr(linha, cpf) != NULL) {
            fclose(arqCliente);
            return 1; // Indica que encontrou o CPF
        }
    }

    fclose(arqCliente);
    return 0; // Indica que não encontrou o CPF
}

    void incluirCliente() {
        Cliente novoCliente;

        printf("Digite o CPF do cliente:\n");
        scanf("%s", novoCliente.cpf);

        // Verifique se o CPF é válido
        if (!CPF(novoCliente.cpf)) {
            printf("CPF invalido.\n");
            return;
        }

        // Verifique se o CPF já existe
        if (verificarCliente(novoCliente.cpf)) {
            printf("Cliente ja existe.\n");
            return;
        }

        // Limpar o buffer de entrada
        while (getchar() != '\n');

        printf("Digite o nome do cliente:\n");
        fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
        novoCliente.nome[strcspn(novoCliente.nome, "\n")] = '\0';  // Remover a quebra de linha

        printf("Digite o numero do celular do cliente:\n");
        fgets(novoCliente.numerocel, sizeof(novoCliente.numerocel), stdin);
        novoCliente.numerocel[strcspn(novoCliente.numerocel, "\n")] = '\0';

        printf("Digite o numero do telefone do cliente:\n");
        fgets(novoCliente.numerotele, sizeof(novoCliente.numerotele), stdin);
        novoCliente.numerotele[strcspn(novoCliente.numerotele, "\n")] = '\0';

        printf("Digite o email do cliente:\n");
        fgets(novoCliente.email, sizeof(novoCliente.email), stdin);
        novoCliente.email[strcspn(novoCliente.email, "\n")] = '\0';

        // Abra o arquivo cliente.csv para escrita (modo "a" para adicionar ao final)
        FILE *arqCliente = fopen("cliente.csv", "a");

        if (arqCliente == NULL) {
            printf("Erro ao abrir o arquivo cliente.csv");
            return;
        }

        // Escreva as informações do cliente no arquivo
        fprintf(arqCliente, "%.11s-%s-%s-%s-%s\n",
                novoCliente.cpf, novoCliente.nome,
                novoCliente.numerocel, novoCliente.numerotele,
                novoCliente.email);

        fclose(arqCliente);
        printf("Cliente adicionado com sucesso.\n");
    }
    
    void excluirCliente() {
        char cpf[12];

        printf("Digite o CPF do cliente a ser excluido:\n");
        scanf("%s", cpf);

        if (!verificarCliente(cpf)) {
            printf("Cliente nao encontrado.\n");
            return;
        }

        // Cliente encontrado, solicita confirmação
        printf("Cliente encontrado. Deseja realmente excluir? (S/N): ");
        char resposta;
        scanf(" %c", &resposta);

        if (resposta != 'S' && resposta != 's') {
            printf("Operacao de exclusao cancelada.\n");
            return;
        }

        FILE *arqCliente = fopen("cliente.csv", "r");
        FILE *tempFile = fopen("temp.csv", "w");

        if (arqCliente == NULL || tempFile == NULL) {
            printf("Erro ao abrir os arquivos.\n");
            return;
        }

        char linha[256];
        while (fgets(linha, sizeof(linha), arqCliente) != NULL) {
            if (strstr(linha, cpf) == NULL) {
                fputs(linha, tempFile);
            }
        }

        fclose(arqCliente);
        fclose(tempFile);

        // Feche o arquivo antes de tentar removê-lo
        arqCliente = NULL;  // Defina como NULL para evitar fechá-lo novamente
        if (remove("cliente.csv") != 0) {
            perror("Erro ao excluir o arquivo cliente.csv");
            return;
        }

        if (rename("temp.csv", "cliente.csv") != 0) {
            perror("Erro ao renomear o arquivo temp.csv");
            return;
        }

        printf("Cliente excluido com sucesso.\n");
    }

    void consultarCliente() {
        char cpf[12];

        printf("Digite o CPF do cliente a ser consultado:\n");
        scanf("%s", cpf);

        if (!verificarCliente(cpf)) {
            printf("Cliente nao encontrado.\n");
            return;
        }

        // Abrir o arquivo cliente.csv para leitura
        FILE *arqCliente = fopen("cliente.csv", "r");

        if (arqCliente == NULL) {
            printf("Erro ao abrir o arquivo cliente.csv");
            return;
        }

        char linha[256];
        while (fgets(linha, sizeof(linha), arqCliente) != NULL) {
            // Verifique se o CPF existe na linha
            if (strstr(linha, cpf) != NULL) {
                // Exiba as informações do cliente
                printf("\nInformacoes do Cliente:\n");
                printf("CPF: %s\n", strtok(linha, "-"));
                printf("Nome: %s\n", strtok(NULL, "-"));
                printf("Numero Celular: %s\n", strtok(NULL, "-"));
                printf("Numero Telefone: %s\n", strtok(NULL, "-"));
                printf("Email: %s\n", strtok(NULL, "-"));
                break;
            }
        }

    fclose(arqCliente);
}

    void listarClientes() {
        FILE *arqCliente = fopen("cliente.csv", "r");

        if (arqCliente == NULL) {
            printf("Erro ao abrir o arquivo cliente.csv\n");
            return;
        }

        printf("\nLista de Clientes:\n");

        char linha[256];
        while (fgets(linha, sizeof(linha), arqCliente) != NULL) {
            // Tokeniza a linha usando o caractere '-' como delimitador
            char *cpf = strtok(linha, "-");
            char *nome = strtok(NULL, "-");
            char *numCelular = strtok(NULL, "-");
            char *numTelefone = strtok(NULL, "-");
            char *email = strtok(NULL, "-");

            // Imprime todas as informações em uma linha
            printf("CPF: %s, Nome: %s, Num. Celular: %s, Num. Telefone: %s, Email: %s\n",
                cpf, nome, numCelular, numTelefone, email);
        }

        fclose(arqCliente);
    }   

#endif
