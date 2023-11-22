#include <stdio.h>

float transformarf(float g);

int main(){

    float grau,grautransformado;

    puts("Digite um grau em Fahrenheit para transformar em Celsius: ");
    scanf("%f",&grau);

    grautransformado=transformarf(grau);

    printf("Temperatura em Celsius: %.1f",grautransformado);

    return 0;
}

float transformarf(float f){

    float c=(f-32.0)*(5.0/9.0);

    return c;

}