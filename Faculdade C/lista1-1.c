#include <stdio.h>

int maior(int n1,int n2);

int main(){

    int numero1,numero2;

    printf("Digite o numero1: ");
    scanf("%d",&numero1);

    printf("Digite o numero2: ");
    scanf("%d",&numero2);

    int m = maior(numero1,numero2);

    printf("%d e o maior",m);

    return 0;

}

int maior(int n1,int n2){

    if(n1>n2){
        return n1;
    }else{
        return n2;
    }
    
}