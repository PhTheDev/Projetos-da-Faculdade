#include <stdio.h>
#include <stdlib.h>çkç

void imprimir(int tam,int mat[tam][tam]){
    for(int l=0;l<tam;l++){
        for(int c=0;c<tam;c++){
        printf("%d",mat[l][c]);
        }
        printf("\n");
    }
}

void rotacionar90(int tam,int mat[tam][tam]){
    int l,c,mat2[tam][tam];
    for(l=0;l<tam;l++){
        for(c=0;c<tam;c++){
            mat2[c][tam-1-l]=mat[l][c]; //esta linha que rotaciona em 90;
        }
    }
    for(l=0;l<tam;l++){
         for(c=0;c<tam;c++){
             mat[l][c]= mat2[l][c];
         }
     }
}

int main()
{
    int dimencao;
    puts("Digite a dimencao da matrix: ");
    scanf("%d",&dimencao);
    int matrix[dimencao][dimencao];
    
    for(int i=0;i<dimencao;i++){
        for(int j=0;j<dimencao;j++){
        printf("Digite o valor para a matriz[%d][%d]: ",i,j);
        scanf("%d",&matrix[i][j]);
        }
    }

    printf("Matrix dada:\n");
    imprimir(dimencao,matrix);
    rotacionar90(dimencao,matrix);
    printf("\nMatriz rotacionada:\n");
    imprimir(dimencao, matrix);
    
    return 0;
}
