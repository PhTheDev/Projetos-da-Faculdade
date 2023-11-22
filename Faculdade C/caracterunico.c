#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool verificar(char* palavra){ //verifica se possui caracteres unicos

    int tamanho = strlen(palavra);
    for(int i=0;i<tamanho;i++){
        for(int j=i+1;j<tamanho; j++){
            if(palavra[i]==palavra[j]){
                return false;
            }
        }
    }
    return true;

}

int main(){

    //digitar a palavra para comparar
    char p[100];
    printf("Digite a palavra para ver se ela possui somente caracteres unicos: ");
        scanf("%s",p);

    //entra em um if que chama a função para verificar a palavra
    if(verificar(p)){
        printf("A palavra %s possui somente caracteres unicos.\n",p);
    } else {
        printf("A palavra %s nao possui somente caracteres unicos",p);
    }

    return 0;
}