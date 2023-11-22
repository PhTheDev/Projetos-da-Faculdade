#include <stdio.h>
#include <stdlib.h>

int main(){

    float **mat;
    int linha=3,coluna=3;
    //Cria as linhas da matriz utilizando aritmetica de ponteiros
    mat=(float **)malloc(linha*sizeof(float *));
    int i,j;
    //Cria as colunas da matriz utilizando aritmetica de ponteiros
    for(i=0;i<linha;i++){
        mat[i]=(float *)malloc(coluna*sizeof(int));
    }
    //Faz a impressao da matriz tambem utilizando aritmetica de ponteiros
    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            printf("%x\n",(void *)&mat[i]+j);
        }
    }

    //Libera toda a memoria utilizada nos malloc's (Otimo abito)
    for (int i = 0; i < linha; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}