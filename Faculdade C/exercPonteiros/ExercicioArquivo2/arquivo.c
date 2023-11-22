#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *cmp = fopen("CMP-2.txt", "a+");
    FILE *arquivoalunos = fopen("alunos.csv", "w"); //Modo w(write) pois toda vez que o .c for executado ele recria os arquivos sem adicionar nada a ele.
    FILE *disciplinas = fopen("disciplinas.csv", "w");
    FILE *matriculas = fopen("matriculas.csv", "w");

    if (cmp == NULL || arquivoalunos == NULL || disciplinas == NULL || matriculas == NULL) {
        printf("Erro na abertura do arquivo!\n");
        exit(EXIT_FAILURE);
    }

    char num[256], matricula[50], nome[50], disciplina[50], cod_disciplina[10], turma[5], linha[63];

    //Seleciona todas as linhas do arquivo principal.
    while (fgets(linha, sizeof(linha), cmp)){
        //Filtra as linhas com matricula
        if(sscanf(linha, "%s %s %99[^\n]", num, matricula, nome)!=3){ // %99[^\n] --> é usado para ler até 99 caracteres da entrada padrão, excluindo os caracteres de nova linha
            continue;
        }

        //Faz a impressao da matricula nos arquivos matricula.csv e alunos.csv.
        sscanf(linha, "%s %s %99[^\n]", &num, &matricula, &nome);
        if(isdigit(num[0]) && isdigit(matricula[0]) && isdigit(matricula[1]) && isdigit(matricula[2]) && isdigit(matricula[3]) &&  matricula[4]=='.' && matricula[6]=='.' ){
            fprintf(arquivoalunos, "%s - %s\n",matricula, nome);
            fprintf(matriculas, "%s \n",matricula);            
        }

        //Acha no arquivo as disciplinas e seus codigos.
        if(sscanf(linha, "%s %99[^\n]", cod_disciplina, disciplina)!=2){
            continue;
        }

        //Imprime no arquivo as disciplinas e os codigos.
        sscanf(linha, "%s %99[^\n]", &cod_disciplina, &disciplina);
        if(cod_disciplina[0]=='C' && cod_disciplina[1]=='M'){
            fprintf(disciplinas, "\n%s ", cod_disciplina);
            fprintf(matriculas, "\n%s \n", cod_disciplina);
            fprintf(disciplinas, "%s", disciplina);

            strncpy(turma, disciplina + strlen(disciplina) - 2, 2);
            turma[2] = '\0';
            fprintf(matriculas, "%s\n", turma);
        }

    }

    printf("Compilacao completa arquivos criados!");
    
    //Fecha todos os arquivos esvasiando o buffer para evitar erros.
    fclose(cmp);
    fclose(arquivoalunos);
    fclose(matriculas);
    fclose(disciplinas);

    return 0;
}