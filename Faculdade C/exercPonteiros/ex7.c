#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *palavra1,*palavra2;

    //creio que a palavra nao deve passa de 20 characteres ao nao ser que seja esternocleidomastóideo mas acho que nao e o caso
    palavra1=malloc(20*sizeof(char));
    palavra2=malloc(20*sizeof(char));

    printf("Digite uma palavra:\n");
    fgets(palavra1,20,stdin);
    printf("Digite outra palavra:\n");
    fgets(palavra2,20,stdin);

    //quando se usa fgets quando apertamos enter no teclado entra junto com a string um \n ficando ex: em vez de carro fica carro\n
    palavra1[strcspn(palavra1, "\n")] = '\0';
    palavra2[strcspn(palavra2, "\n")] = '\0';

    char *pont1 = palavra1;
    char *pont2 = palavra2;

    while(*pont1){
        while(*pont1 && *pont2 && *pont1 == *pont2){
            pont1++;
            pont2++;
        }
    
        if(!*pont2){
            printf("'%s' ocorre em '%s' \n",palavra2,palavra1);
            break;
        }

        pont1++;
    }

    if(*pont2){
        printf("'%s' nao ocorre em '%s' \n",palavra2,palavra1);
    }

    free(palavra1);
    free(palavra2);

    return 0;
}